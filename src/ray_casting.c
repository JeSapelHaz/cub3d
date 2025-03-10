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
// #define mapX 8      // Largeur de la carte
// #define mapY 8      // Hauteur de la carte
// #define mapS 64     // Taille d'un cube de la carte

// char map[mapY][mapX] = {
//     {'1', '1', '1', '1', '1', '1', '1', '1'},
//     {'1', '0', '1', '0', '0', '0', '0', '1'},
//     {'1', '0', '1', '0', '0', '0', '0', '1'},
//     {'1', '0', '1', '0', '0', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '1', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '1', '1', '1', '1', '1', '1', '1'}
// };

//------------------------PLAYER------------------------------------------------
float degToRad(int a) { return a * PI / 180.0; }
int FixAng(int a) { if (a > 359) a -= 360; if (a < 0) a += 360; return a; }

//---------------------------Draw Rays and Walls--------------------------------
float distance(float ax, float ay, float bx, float by, float ang) { return cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay); }


// Fonction pour effacer l'image (remplir avec du noir)
void clearImage(t_data *data)
{
    for (int y = 0; y < 510; y++)
    {
        for (int x = 0; x < 1024; x++)
        {
            int pixel = (y * data->size_line) + (x * (data->bpp / 8));
            data->img_addr[pixel] = 0;         // R
            data->img_addr[pixel + 1] = 0;     // G
            data->img_addr[pixel + 2] = 0;     // B
        }
    }
}

void drawPixel(t_data* data, int x, int y, int color)
{
    if (x >= 0 && x < 1024 && y >= 0 && y < 510)
    {
        int pixel = (y * data->size_line) + (x * (data->bpp / 8));
        data->img_addr[pixel] = color & 0xFF;
        data->img_addr[pixel + 1] = (color >> 8) & 0xFF;
        data->img_addr[pixel + 2] = (color >> 16) & 0xFF;
    }
}

void drawLine(t_data* data, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1)
    {
        drawPixel(data, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void drawMap2D(t_data* data)
{
    int x, y, xo, yo;
    for (y = 0; y < data->mapinfo.map_y; y++)
    {
        for (x = 0; x < data->mapinfo.map_x; x++)
        {
            int color = data->mapinfo.map[y][x] == '1' ? 0xFFFFFF : 0x000000;
            xo = x * data->mapinfo.size_of_world; yo = y * data->mapinfo.size_of_world;
            for (int i = 0; i < data->mapinfo.size_of_world; i++)
            {
                for (int j = 0; j < data->mapinfo.size_of_world; j++)
                {
                    drawPixel(data, xo + i, yo + j, color);
                }
            }
        }
    }
}

void drawPlayer2D(t_data* data, t_player *player)
{
    drawPixel(data, player->pos_x, player->pos_y, 0xFFFF00);
    drawLine(data, player->pos_x, player->pos_y, player->pos_x + player->dir_x * 20, player->pos_y + player->dir_y * 20, 0xFFFF00);
}

void drawRays2D(t_data *data, t_player *player)
{
    int r, mx, my, dof, side;
    float vx, vy, rx, ry, ra, xo, yo, disV, disH;

    ra = FixAng(player->angle + 30);

    for (r = 0; r < 60; r++)
    {
        dof = 0; side = 0; disV = 100000;
        float Tan = tan(degToRad(ra));
        if (cos(degToRad(ra)) > 0.001) { rx = (((int)player->pos_x >> 6) << 6) + 64; ry = (player->pos_x - rx) * Tan + player->pos_y; xo = 64; yo = -xo * Tan; }
        else if (cos(degToRad(ra)) < -0.001) { rx = (((int)player->pos_x >> 6) << 6) - 0.0001; ry = (player->pos_x - rx) * Tan + player->pos_y; xo = -64; yo = -xo * Tan; }
        else { rx = player->pos_x; ry = player->pos_y; dof = 8; }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6;
            if (mx >= 0 && mx < data->mapinfo.map_x && my >= 0 && my < data->mapinfo.map_y && data->mapinfo.map[my][mx] == '1') { dof = 8; disV = cos(degToRad(ra)) * (rx - player->pos_x) - sin(degToRad(ra)) * (ry - player->pos_y); }
            else { rx += xo; ry += yo; dof += 1; }
        }
        vx = rx; vy = ry;

        dof = 0; disH = 100000;
        Tan = 1.0 / Tan;
        if (sin(degToRad(ra)) > 0.001) { ry = (((int)player->pos_y >> 6) << 6) - 0.0001; rx = (player->pos_y - ry) * Tan + player->pos_x; yo = -64; xo = -yo * Tan; }
        else if (sin(degToRad(ra)) < -0.001) { ry = (((int)player->pos_y >> 6) << 6) + 64; rx = (player->pos_y - ry) * Tan + player->pos_x; yo = 64; xo = -yo * Tan; }
        else { rx = player->pos_x; ry = player->pos_y; dof = 8; }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6;
            if (mx >= 0 && mx < data->mapinfo.map_y && my >= 0 && my < data->mapinfo.map_y && data->mapinfo.map[my][mx] == '1') { dof = 8; disH = cos(degToRad(ra)) * (rx - player->pos_x) - sin(degToRad(ra)) * (ry - player->pos_y); }
            else { rx += xo; ry += yo; dof += 1; }
        }

        int color = 0x00FF00;
        if (disV < disH) { rx = vx; ry = vy; disH = disV; color = 0x00CC00; }
        drawLine(data, player->pos_x, player->pos_y, rx, ry, color);

        int ca = FixAng(player->angle - ra); disH = disH * cos(degToRad(ca));
        int lineH = (data->mapinfo.size_of_world * 320) / (disH); if (lineH > 320) { lineH = 320; }
        int lineOff = 160 - (lineH >> 1);

        drawLine(data, r * 8 + 530, lineOff, r * 8 + 530, lineOff + lineH, color);

        ra = FixAng(ra - 1);
    }
}

int key_press(int keycode, void *param)
{
    t_data *data = (t_data *)param;
    t_player *player = &data->player;

    if (keycode == 65361) { // Left arrow
        player->angle += 5;
        player->angle = FixAng(player->angle);
        player->dir_x = cos(degToRad(player->angle));
        player->dir_y = -sin(degToRad(player->angle));
    }
    if (keycode == 65363) { // Right arrow
        player->angle -= 5;
        player->angle = FixAng(player->angle);
        player->dir_x = cos(degToRad(player->angle));
        player->dir_y = -sin(degToRad(player->angle));
    }
    if (keycode == 65362) { // Up arrow
        player->pos_x += player->dir_x * 5;
        player->pos_y += player->dir_y * 5;
    }
    if (keycode == 65364) { // Down arrow
        player->pos_x -= player->dir_x * 5;
        player->pos_y -= player->dir_y * 5;
    }

    // Effacer l'image avant de redessiner
    clearImage(data);

    // Redessiner la carte, le joueur et les rayons
    drawMap2D(data);
    drawPlayer2D(data, player);
    drawRays2D(data, player);

    // Mettre à jour la fenêtre
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int main(int ac, char* av[])
{
    t_data data;

    // Taille des cubes
    data.mapinfo.size_of_world = 64;

    if (check_args(ac, av) != 0)
        return (1);

    init_data(&data);
    parse_data(av[1], &data);

    // Vérifier que la carte est correctement chargée
    printf("Map loaded:\n");
    printMap(&data);

    if (take_info_file(data.mapinfo.file, &data))
        return (free_data(&data), 1);

    if (check_data(data))
        return (free_data(&data), 1);

    // Initialisation de MLX
    data.mlx = mlx_init();
    if (!data.mlx) {
        fprintf(stderr, "Error: mlx_init failed\n");
        return (1);
    }

    data.win = mlx_new_window(data.mlx, 1024, 510, "MiniLibX Raycaster");
    if (!data.win) {
        fprintf(stderr, "Error: mlx_new_window failed\n");
        return (1);
    }

    data.img = mlx_new_image(data.mlx, 1024, 510);
    if (!data.img) {
        fprintf(stderr, "Error: mlx_new_image failed\n");
        return (1);
    }

    data.img_addr = mlx_get_data_addr(data.img, &data.bpp, &data.size_line, &data.endian);
    if (!data.img_addr) {
        fprintf(stderr, "Error: mlx_get_data_addr failed\n");
        return (1);
    }

    // Initialisation du joueur
    data.player.pos_x = 150;
    data.player.pos_y = 400;
    data.player.angle = 90;
    data.player.dir_x = cos(degToRad(data.player.angle));
    data.player.dir_y = -sin(degToRad(data.player.angle));

    // Dessiner la carte, le joueur et les rayons
    printf("Drawing map...\n");
    drawMap2D(&data);

    printf("Drawing player...\n");
    drawPlayer2D(&data, &data.player);

    printf("Drawing rays...\n");
    drawRays2D(&data, &data.player);

    // Mettre à jour la fenêtre
    printf("Updating window...\n");
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    // Configurer la gestion des touches
    mlx_hook(data.win, 2, 1L << 0, key_press, &data);

    // Configurer la fermeture de la fenêtre
    mlx_hook(data.win, 17, 0, (void *)exit, 0);

    // Lancer la boucle principale
    printf("Entering main loop...\n");
    mlx_loop(data.mlx);

    // Nettoyer les ressources
    free_data(&data);
    return (0);
}