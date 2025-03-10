/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:14:31 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/10 15:39:12 by hbutt            ###   ########.fr       */
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
	if (check_data(data))
		return (free_data(&data), 1);
	init_mlx(&data);
	mlx_key_hook(data.window, controls, &data);
	mlx_hook(data.window, 17, 0, (void *)exit, 0);
	mlx_loop(data.mlx);
	free_data(&data);
}
