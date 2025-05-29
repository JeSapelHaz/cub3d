/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:53 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/29 12:59:44 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Check if the args are valid */
int	check_args(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Error : No map, you dont want to play bro?\n");
		return (1);
	}
	else if (ac > 2)
	{
		printf("Error : Only the map is valid\n");
		return (1);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
	{
		printf("Error : Map invalid\n");
		return (1);
	}
	return (0);
}
