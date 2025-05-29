/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:31:59 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/29 13:00:18 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_dir(t_data *data, char direction)
{
	if (direction == 'N')
		data->player.angle = PI / 2.0;
	else if (direction == 'S')
		data->player.angle = (3.0 * PI) / 2.0;
	else if (direction == 'E')
		data->player.angle = 2.0 * PI;
	else
		data->player.angle = PI;
}

static int	check_map_chars(t_data *data, int *nbr_players)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (data->mapinfo.map[++i])
	{
		j = -1;
		while (data->mapinfo.map[i][++j])
		{
			c = data->mapinfo.map[i][j];
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			{
				data->player.pos_x = j;
				data->player.pos_y = i;
				set_player_dir(data, c);
				(*nbr_players)++;
			}
			else if (c != ' ' && c != '1' && c != '0' && c != '\t' && c != '\n'
				&& c != '\r' && c != '\v' && c != '\f')
				return (printf("Error : Caracter <%c> not allowed in the map\n", c), 1);
		}
	}
	return (0);
}

int	check_map(t_data *data)
{
	int	nbr_players;

	nbr_players = 0;
	if (check_map_chars(data, &nbr_players))
		return (1);
	if (nbr_players == 0 || nbr_players > 1)
	{
		printf("Error : Its a game for 1 player\n");
		return (1);
	}
	return (0);
}
