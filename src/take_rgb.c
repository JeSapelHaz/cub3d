/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:55:00 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/20 16:58:41 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	handle_ceiling(char **file, int i, t_data *data, int *nbr_paths)
{
	int	j;

	if (data->mapinfo.ceiling)
	{
		printf("Error : Ceiling already defined\n");
		free_data(data);
		exit(0);
	}
	j = skip_spaces(file[i]);
	data->mapinfo.ceiling = ft_strndup(&file[i][j],
			ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
	(*nbr_paths)++;
}

static void	handle_floor(char **file, int i, t_data *data, int *nbr_paths)
{
	int	j;

	if (data->mapinfo.floor)
	{
		printf("Error : Floor already defined\n");
		free_data(data);
		exit(0);
	}
	j = skip_spaces(file[i]);
	data->mapinfo.floor = ft_strndup(&file[i][j],
			ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
	(*nbr_paths)++;
}

void	take_rgb(char **file, int i, t_data *data, int *nbr_paths)
{
	char	*trimmed;

	trimmed = ft_strtrim(file[i], " ");
	if (!trimmed)
		return ;
	free(file[i]);
	file[i] = trimmed;
	if (file[i][0] == 'C')
		handle_ceiling(file, i, data, nbr_paths);
	if (file[i][0] == 'F')
		handle_floor(file, i, data, nbr_paths);
}
