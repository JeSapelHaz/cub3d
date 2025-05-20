/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:17:01 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/20 16:58:54 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	fill_map(char **file, int i, t_data *data)
{
	int	j;

	j = 0;
	while (file[i] && no_line(file[i]) == 0)
		i++;
	while (file[i] && no_line(file[i]) == 1 && ++i)
		j++;
	data->mapinfo.map = malloc(sizeof(char *) * (j + 1));
	if (!data->mapinfo.map)
		return (1);
	i = i - j;
	j = 0;
	while (file[i] && no_line(file[i]) == 1)
	{
		if (file[i][ft_strlen(file[i]) - 1] == '\n')
			data->mapinfo.map[j] = ft_strndup(file[i], ft_strlen(file[i]) - 1);
		else
			data->mapinfo.map[j] = ft_strdup(file[i]);
		i++;
		j++;
	}
	data->mapinfo.map[j] = NULL;
	data->mapinfo.map_height = j;
	return (0);
}

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	is_start_of_map(char *line)
{
	int	i;
	int	has_map_char;

	i = 0;
	has_map_char = 0;
	while (line[i])
	{
		if (is_map_char(line[i]))
			has_map_char = 1;
		else if (line[i] != '\t' && line[i] != '\n' && line[i] != '\r'
			&& line[i] != '\v' && line[i] != '\f')
			return (0);
		i++;
	}
	return (has_map_char);
}

static int	only_one_map(char **file, int i)
{
	int	found_map;
	int	map_has_ended;

	found_map = 0;
	map_has_ended = 0;
	while (file[i])
	{
		if (is_start_of_map(file[i]))
		{
			if (map_has_ended)
				return (1);
			found_map = 1;
		}
		else if (found_map && no_line(file[i]) == 0)
		{
			map_has_ended = 1;
		}
		i++;
	}
	return (0);
}

int	take_info_file(char **file, t_data *data)
{
	int	i;
	int	nbr_paths;

	nbr_paths = 0;
	i = 0;
	while (file[i] && nbr_paths != 6 && !is_start_of_map(file[i]))
	{
		take_paths(file, i, data, &nbr_paths);
		take_rgb(file, i, data, &nbr_paths);
		i++;
	}
	if (nbr_paths != 6)
		return (printf("Error in the paths\n"), 1);
	if (only_one_map(file, i))
		return (printf("Error : Only one map please\n"), 1);
	if (fill_map(file, i, data))
		return (1);
	return (0);
}
