/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:14:31 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/16 15:37:03 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) != 0)
		return (1);
	init_data(&data);
	parse_data(av[1], &data);
	if (take_info_file(data.mapinfo.file, &data))
		return (free_data(&data), 1);
	if (check_data(&data))
		return (free_data(&data), 1);
	// print_map(data);
	init_mlx(&data);
	// mlx_key_hook(data.win, controls, &data);
	mlx_hook(data.win, 17, 0, (void *)exit, 0);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, actions, &data);
	data.img = mlx_new_image(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.bpp,
			&data.size_line, &data.endian);
	draw_map(&data);
	draw_player(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	free_data(&data);
}