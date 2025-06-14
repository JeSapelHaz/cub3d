/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:14:31 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/29 13:07:26 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) != 0)
		return (1);
	init_data(&data);
	if (parse_data(av[1], &data) == 1)
		return (free_data(&data), 1);
	if (take_info_file(data.mapinfo.file, &data))
		return (free_data(&data), 1);
	if (check_data(&data))
		return (free_data(&data), 1);
	init_mlx(&data);
	data.player.pos_x += 0.5f;
	data.player.pos_y += 0.5f;
	load_image(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 0, clean_exit, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, actions, &data);
	mlx_loop(data.mlx);
	clean_exit(&data);
}
