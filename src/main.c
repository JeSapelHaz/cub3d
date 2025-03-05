/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:14:31 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/04 15:28:21 by hbutt            ###   ########.fr       */
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
	take_info_file(data.mapinfo.file, &data);
	// print_file(data);
	free_data(&data);
	return (0);
}
