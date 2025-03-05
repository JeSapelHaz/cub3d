/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:14:31 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/05 17:01:58 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	controls(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_clear_window(data->mlx, data->window);
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) != 0)
		return (1);
	init_data(&data);
	parse_data(av[1], &data);
	take_info_file(data.mapinfo.file, &data);
	if (check_data(data))
		return (1);
	init_mlx(&data);
	mlx_key_hook(data.window, controls, &data);
	mlx_hook(data.window, 17, 0, (void *)exit, 0);
	mlx_loop(data.mlx);
	print_file(data);
	print_paths(data);
	print_map(data);
	free_data(&data);
}
