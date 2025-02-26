/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/02/26 15:17:56 by hbutt            ###   ########.fr       */
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

int	parse_data(char *path, t_data *data)
{
	int line_count = get_line_count(path);
	char *line;
	int fd;
	int row = 0;
	int column = 0;
	data->mapinfo.file = ft_calloc(line_count + 1, sizeof(char *));
	if (!data->mapinfo.file)
		return (1);
	int i;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		column = 0;
		i = 0;
		data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		while (line[i])
		{
			data->mapinfo.file[row][column] = line[i];
			i++;
			column++;
		}
		data->mapinfo.file[row][column] = '\0';
		row++;
		free(line);
		line = get_next_line(fd);
	}
	data->mapinfo.file[row] = NULL;
	close(fd);
	return (0);
}