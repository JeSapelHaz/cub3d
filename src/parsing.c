/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/26 01:28:48 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_line_count(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static void	fill_file(char *path, t_data *data)
{
	int		fd;
	int		i;
	int		column;
	int		row;
	char	*line;

	row = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		clean_exit(data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		column = 0;
		i = 0;
		data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		while (line[i])
			data->mapinfo.file[row][column++] = line[i++];
		data->mapinfo.file[row][column] = '\0';
		row++;
		free(line);
		line = get_next_line(fd);
	}
	data->mapinfo.file[row] = NULL;
	close(fd);
}

int	parse_data(char *path, t_data *data)
{
	int	line_count;

	line_count = get_line_count(path);
	// error there is line_count = -1 ?
	data->mapinfo.file = ft_calloc(line_count + 1, sizeof(char *));
	if (!data->mapinfo.file)
		return (1);
	fill_file(path, data);
	return (0);
}
