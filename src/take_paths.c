/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:55:20 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/29 15:56:45 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	handle_no_path(char **file, int i, t_data *data, int *nbr_paths)
{
	int	j;

	if (data->mapinfo.textures[NORTH].path)
	{
		printf("Error : NO already defined\n");
		free_data(data);
		exit(0);
	}
	if (!ft_isspace(file[i][2]))
	{
		printf("Error : NO path\n");
		free_data(data);
		exit(0);
	}
	j = skip_spaces(file[i]);
	if (!file[i][2 + j] || file[i][2 + j] == '\n')
	{
		printf("Error : NO path missing\n");
		free_data(data);
		exit(0);
	}
	data->mapinfo.textures[NORTH].path = ft_strndup(&file[i][j],
			ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
	(*nbr_paths)++;
}

static void	handle_so_path(char **file, int i, t_data *data, int *nbr_paths)
{
	int	j;

	if (data->mapinfo.textures[SOUTH].path)
	{
		printf("Error : SO already defined\n");
		free_data(data);
		exit(0);
	}
	if (!ft_isspace(file[i][2]))
	{
		printf("Error : SO path\n");
		free_data(data);
		exit(0);
	}
	j = skip_spaces(file[i]);
	if (!file[i][2 + j] || file[i][2 + j] == '\n')
	{
		printf("Error : SO path missing\n");
		free_data(data);
		exit(0);
	}
	data->mapinfo.textures[SOUTH].path = ft_strndup(&file[i][j],
			ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
	(*nbr_paths)++;
}

static void	handle_we_path(char **file, int i, t_data *data, int *nbr_paths)
{
	int	j;

	if (data->mapinfo.textures[WEST].path)
	{
		printf("Error : WE already defined\n");
		free_data(data);
		exit(0);
	}
	if (!ft_isspace(file[i][2]))
	{
		printf("Error : WE path\n");
		free_data(data);
		exit(0);
	}
	j = skip_spaces(file[i]);
	if (!file[i][2 + j] || file[i][2 + j] == '\n')
	{
		printf("Error : WE path missing\n");
		free_data(data);
		exit(0);
	}
	data->mapinfo.textures[WEST].path = ft_strndup(&file[i][j],
			ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
	(*nbr_paths)++;
}

static void	handle_ea_path(char **file, int i, t_data *data, int *nbr_paths)
{
	int	j;

	if (data->mapinfo.textures[EAST].path)
	{
		printf("Error : EA already defined\n");
		free_data(data);
		exit(0);
	}
	if (!ft_isspace(file[i][2]))
	{
		printf("Error : EA path\n");
		free_data(data);
		exit(0);
	}
	j = skip_spaces(file[i]);
	if (!file[i][2 + j] || file[i][2 + j] == '\n')
	{
		printf("Error : EA path missing\n");
		free_data(data);
		exit(0);
	}
	data->mapinfo.textures[EAST].path = ft_strndup(&file[i][j],
			ft_strlen(file[i]) - j - count_trailing_spaces(file[i]));
	(*nbr_paths)++;
}

void	take_paths(char **file, int i, t_data *data, int *nbr_paths)
{
	char	*trimmed;

	trimmed = ft_strtrim(file[i], " ");
	if (!trimmed)
		return ;
	free(file[i]);
	file[i] = trimmed;
	check_path_validity(file, i, data);
	if (file[i][0] == 'N' && file[i][1] == 'O')
		handle_no_path(file, i, data, nbr_paths);
	if (file[i][0] == 'S' && file[i][1] == 'O')
		handle_so_path(file, i, data, nbr_paths);
	if (file[i][0] == 'W' && file[i][1] == 'E')
		handle_we_path(file, i, data, nbr_paths);
	if (file[i][0] == 'E' && file[i][1] == 'A')
		handle_ea_path(file, i, data, nbr_paths);
}
