/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:22:15 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/10 15:25:27 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

//-----------------------------MAP----------------------------------------------
#define mapX 8      // Largeur de la carte
#define mapY 8      // Hauteur de la carte
#define mapS 64     // Taille d'un cube de la carte

char map[mapY][mapX] = {
    {'1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1'}
};

//------------------------PLAYER------------------------------------------------
float degToRad(int a) { return a * PI / 180.0; }
int FixAng(int a) { if (a > 359) a -= 360; if (a < 0) a += 360; return a; }

float px, py, pdx, pdy, pa;

//---------------------------Draw Rays and Walls--------------------------------
float distance(float ax, float ay, float bx, float by, float ang) { return cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay); }

void *mlx;
void *win;
void *img;
char *data;
int bpp;
int size_line;
int endian;

// Fonction pour effacer l'image (remplir avec du noir)
void clearImage()
{
    for (int y = 0; y < 510; y++)
    {
        for (int x = 0; x < 1024; x++)
        {
            int pixel = (y * size_line) + (x * (bpp / 8));
            data[pixel] = 0;         // R
            data[pixel + 1] = 0;     // G
            data[pixel + 2] = 0;     // B
        }
    }
}

void drawPixel(int x, int y, int color)
{
    if (x >= 0 && x < 1024 && y >= 0 && y < 510)
    {
        int pixel = (y * size_line) + (x * (bpp / 8));
        data[pixel] = color & 0xFF;
        data[pixel + 1] = (color >> 8) & 0xFF;
        data[pixel + 2] = (color >> 16) & 0xFF;
    }
}

void drawLine(int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1)
    {
        drawPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void drawMap2D()
{
    int x, y, xo, yo;
    for (y = 0; y < mapY; y++)
    {
        for (x = 0; x < mapX; x++)
        {
            int color = map[y][x] == '1' ? 0xFFFFFF : 0x000000;
            xo = x * mapS; yo = y * mapS;
            for (int i = 0; i < mapS; i++)
            {
                for (int j = 0; j < mapS; j++)
                {
                    drawPixel(xo + i, yo + j, color);
                }
            }
        }
    }
}

void drawPlayer2D()
{
    drawPixel(px, py, 0xFFFF00);
    drawLine(px, py, px + pdx * 20, py + pdy * 20, 0xFFFF00);
}

void drawRays2D()
{
    int r, mx, my, dof, side;
    float vx, vy, rx, ry, ra, xo, yo, disV, disH;

    ra = FixAng(pa + 30);

    for (r = 0; r < 60; r++)
    {
        dof = 0; side = 0; disV = 100000;
        float Tan = tan(degToRad(ra));
        if (cos(degToRad(ra)) > 0.001) { rx = (((int)px >> 6) << 6) + 64; ry = (px - rx) * Tan + py; xo = 64; yo = -xo * Tan; }
        else if (cos(degToRad(ra)) < -0.001) { rx = (((int)px >> 6) << 6) - 0.0001; ry = (px - rx) * Tan + py; xo = -64; yo = -xo * Tan; }
        else { rx = px; ry = py; dof = 8; }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6;
            if (mx >= 0 && mx < mapX && my >= 0 && my < mapY && map[my][mx] == '1') { dof = 8; disV = cos(degToRad(ra)) * (rx - px) - sin(degToRad(ra)) * (ry - py); }
            else { rx += xo; ry += yo; dof += 1; }
        }
        vx = rx; vy = ry;

        dof = 0; disH = 100000;
        Tan = 1.0 / Tan;
        if (sin(degToRad(ra)) > 0.001) { ry = (((int)py >> 6) << 6) - 0.0001; rx = (py - ry) * Tan + px; yo = -64; xo = -yo * Tan; }
        else if (sin(degToRad(ra)) < -0.001) { ry = (((int)py >> 6) << 6) + 64; rx = (py - ry) * Tan + px; yo = 64; xo = -yo * Tan; }
        else { rx = px; ry = py; dof = 8; }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6;
            if (mx >= 0 && mx < mapX && my >= 0 && my < mapY && map[my][mx] == '1') { dof = 8; disH = cos(degToRad(ra)) * (rx - px) - sin(degToRad(ra)) * (ry - py); }
            else { rx += xo; ry += yo; dof += 1; }
        }

        int color = 0x00FF00;
        if (disV < disH) { rx = vx; ry = vy; disH = disV; color = 0x00CC00; }
        drawLine(px, py, rx, ry, color);

        int ca = FixAng(pa - ra); disH = disH * cos(degToRad(ca));
        int lineH = (mapS * 320) / (disH); if (lineH > 320) { lineH = 320; }
        int lineOff = 160 - (lineH >> 1);

        drawLine(r * 8 + 530, lineOff, r * 8 + 530, lineOff + lineH, color);

        ra = FixAng(ra - 1);
    }
}

int key_press(int keycode, void *param)
{
    (void) param;
    if (keycode == 65361) { pa += 5; pa = FixAng(pa); pdx = cos(degToRad(pa)); pdy = -sin(degToRad(pa)); } // Left arrow
    if (keycode == 65363) { pa -= 5; pa = FixAng(pa); pdx = cos(degToRad(pa)); pdy = -sin(degToRad(pa)); } // Right arrow
    if (keycode == 65362) { px += pdx * 5; py += pdy * 5; } // Up arrow
    if (keycode == 65364) { px -= pdx * 5; py -= pdy * 5; } // Down arrow

    // Effacer l'image avant de redessiner
    clearImage();

    // Redessiner la carte, le joueur et les rayons
    drawMap2D();
    drawPlayer2D();
    drawRays2D();

    // Mettre à jour la fenêtre
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    return (0);
}

// int main(int argc, char *argv[])
// {
//     (void) argc;
//     (void) argv;
//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 1024, 510, "MiniLibX Raycaster");
//     img = mlx_new_image(mlx, 1024, 510);
//     data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

//     px = 150; py = 400; pa = 90;
//     pdx = cos(degToRad(pa)); pdy = -sin(degToRad(pa));

//     // Dessiner la carte, le joueur et les rayons
//     drawMap2D();
//     drawPlayer2D();
//     drawRays2D();
//     mlx_put_image_to_window(mlx, win, img, 0, 0);

//     // Configurer la gestion des touches
//     mlx_hook(win, 2, 1L << 0, key_press, NULL);

//     // Lancer la boucle principale
//     mlx_loop(mlx);
//     return (0);
// }