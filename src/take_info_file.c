/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:17:01 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 17:25:36 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	skip_spaces(const char *str)
{
	int	i;

	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

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
	int		j;
	char	*trimmed;

	j = 0;
	trimmed = ft_strtrim(file[i], " ");
	if (!trimmed)
		return ;
	free(file[i]);
	file[i] = trimmed;
	if (file[i][0] == 'C')
	{
		if (data->mapinfo.ceiling)
			return (printf("Error : Ceiling already defined\n"),
				free_data(data), exit(0));
		j = skip_spaces(file[i]);
		data->mapinfo.ceiling = ft_strndup(&file[i][j], ft_strlen(file[i]) - j
				- count_trailing_spaces(file[i]));
		(*nbr_paths)++;
	}
	if (file[i][0] == 'F')
	{
		if (data->mapinfo.floor)
			return (printf("Error : Floor already defined\n"), free_data(data),
				exit(0));
		j = skip_spaces(file[i]);
		data->mapinfo.floor = ft_strndup(&file[i][j], ft_strlen(file[i]) - j
				- count_trailing_spaces(file[i]));
		(*nbr_paths)++;
	}
}

static void	take_paths(char **file, int i, t_data *data, int *nbr_paths)
{
	int		j;
	char	*trimmed;

	j = 0;
	trimmed = ft_strtrim(file[i], " ");
	if (!trimmed)
		return ;
	free(file[i]);
	file[i] = trimmed;
	if (file[i][0] == 'N' && file[i][1] == 'O')
	{
		if (data->mapinfo.textures[NORTH].path)
			return (printf("Error : NO already defined\n"), free_data(data),
				exit(0));
		j = skip_spaces(file[i]);
		data->mapinfo.textures[NORTH].path = ft_strndup(&file[i][j],
				ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
		(*nbr_paths)++;
	}
	if (file[i][0] == 'S' && file[i][1] == 'O')
	{
		if (data->mapinfo.textures[SOUTH].path)
			return (printf("Error : SO already defined\n"), free_data(data),
				exit(0));
		j = skip_spaces(file[i]);
		data->mapinfo.textures[SOUTH].path = ft_strndup(&file[i][j],
				ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
		(*nbr_paths)++;
	}
	if (file[i][0] == 'W' && file[i][1] == 'E')
	{
		if (data->mapinfo.textures[WEST].path)
			return (printf("Error : WE already defined\n"), free_data(data),
				exit(0));
		j = skip_spaces(file[i]);
		data->mapinfo.textures[WEST].path = ft_strndup(&file[i][j],
				ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
		(*nbr_paths)++;
	}
	if (file[i][0] == 'E' && file[i][1] == 'A')
	{
		if (data->mapinfo.textures[EAST].path)
			return (printf("Error : EA already defined\n"), free_data(data),
				exit(0));
		j = skip_spaces(file[i]);
		data->mapinfo.textures[EAST].path = ft_strndup(&file[i][j],
				ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
		(*nbr_paths)++;
	}
}

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
	if (fill_map(file, i, data))
		return (1);
	return (0);
}
