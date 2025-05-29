/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:32:48 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/29 15:42:48 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	skip_spaces(const char *str)
{
	int	i;

	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	no_line(char *line)
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

void	check_path_validity(char **file, int i, t_data *data)
{
	if (file[i][0] != 'N' && file[i][0] != 'S' && file[i][0] != 'W'
		&& file[i][0] != 'E' && file[i][0] != '\n' && file[i][0] != ' '
		&& file[i][0] != 'F' && file[i][0] != 'C')
	{
		printf("Error : Caracters no allowed <%c>\n", file[i][0]);
		free_data(data);
		exit(0);
	}
}
