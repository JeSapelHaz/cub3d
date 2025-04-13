/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by hbutt             #+#    #+#             */
/*   Updated: 2025/04/13 14:31:36 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_texture(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->mapinfo.texture[i].img = mlx_xpm_file_to_image(data->mlx,
				data->mapinfo.texture[i].img_addr,
				&data->mapinfo.texture[i].width,
				&data->mapinfo.texture[i].height);
		if (!data->mapinfo.texture[i].img)
		{
			free_data(data);
			ft_putstr_fd("Error: Failed to load texture\n", 2);
			exit(1);
		}
		data->mapinfo.texture[i].img_addr = mlx_get_data_addr(data->mapinfo.texture[i].img,
				&data->mapinfo.texture[i].bpp,
				&data->mapinfo.texture[i].size_line,
				&data->mapinfo.texture[i].endian);
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_addr = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	if (!data->mlx || !data->win || !data->img || !data->img_addr)
	{
		free_data(data);
		ft_putstr_fd("Error\nFailed to initialize mlx\n", 2);
		exit(1);
	}
	init_texture(data);
}