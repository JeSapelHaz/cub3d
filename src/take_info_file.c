/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:17:01 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/12 14:00:56 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	no_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	take_rgb(char **file, int i, t_data *data, int *nbr_paths)
{
	if (file[i][0] == 'C')
	{
		data->mapinfo.ceiling = ft_strndup(&file[i][2], ft_strlen(file[i]) - 3);
		(*nbr_paths)++;
	}
	if (file[i][0] == 'F')
	{
		data->mapinfo.floor = ft_strndup(&file[i][2], ft_strlen(file[i]) - 3);
		(*nbr_paths)++;
	}
}

static void	take_paths(char **file, int i, t_data *data, int *nbr_paths)
{
	if (file[i][0] == 'N' && file[i][1] == 'O')
	{
		data->mapinfo.north_path = ft_strndup(&file[i][3], ft_strlen(file[i])
				- 4);
		(*nbr_paths)++;
	}
	if (file[i][0] == 'S' && file[i][1] == 'O')
	{
		data->mapinfo.south_path = ft_strndup(&file[i][3], ft_strlen(file[i])
				- 4);
		(*nbr_paths)++;
	}
	if (file[i][0] == 'W' && file[i][1] == 'E')
	{
		data->mapinfo.west_path = ft_strndup(&file[i][3], ft_strlen(file[i])
				- 4);
		(*nbr_paths)++;
	}
	if (file[i][0] == 'E' && file[i][1] == 'A')
	{
		data->mapinfo.east_path = ft_strndup(&file[i][3], ft_strlen(file[i])
				- 4);
		(*nbr_paths)++;
	}
}
int len_line(char *line)
{
	return ft_strlen(line);
}

static int	fill_map(char **file, int i, t_data *data)
{
	int	j;

	j = 0;
	while (file[i] && no_line(file[i]) == 0)
		i++;
	while (file[i] && no_line(file[i]) == 1)
	{
		i++;
		j++;
	}
	data->mapinfo.map = malloc(sizeof(char *) * (j + 1));
	if (!data->mapinfo.map)
		return (1);
	i = i - j;
	j = 0;
	while (file[i] && no_line(file[i]) == 1)
	{
		data->mapinfo.map[j] = ft_strndup(file[i], ft_strlen(file[i]) -1);
		i++;
		j++;
	}
	data->mapinfo.map[j] = NULL;
	data->mapinfo.map_height = j;
	return (0);
}

int	take_info_file(char **file, t_data *data)
{
	int i;
	int nbr_paths;
	int j;

	nbr_paths = 0;
	i = 0;
	j = 0;
	while (file[i] && nbr_paths != 6)
	{
		take_paths(file, i, data, &nbr_paths);
		take_rgb(file, i, data, &nbr_paths);
		i++;
	}
	if (nbr_paths != 6)
		return (printf("error dans les paths mon pote\n"), 1);
	if (fill_map(file, i, data))
		return (1);
	return (0);
}