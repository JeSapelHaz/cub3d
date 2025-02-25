/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:53 by hbutt             #+#    #+#             */
/*   Updated: 2025/02/14 15:43:34 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Check if the args are valid */
int	check_args(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Error : Pas de map, tu veux pas jouer chef ?\n");
		return (1);
	}
	else if (ac > 2)
	{
		printf("Error : Le seul argument valable est la map\n");
		return (1);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
	{
		printf("Error : Map invalide chef\n");
		return (1);
	}
	return (0);
}
