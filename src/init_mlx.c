/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by hbutt             #+#    #+#             */
/*   Updated: 2025/04/09 16:14:36 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
}