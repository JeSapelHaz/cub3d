/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:15:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/02/12 14:30:50 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <string.h>

typedef struct s_mapinfo
{
	int		width;
	int		height;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		pos_x;
	int		pos_y;
    
}			t_mapinfo;

/* CHECK ARGS */
int			check_args(int ac, char **av);

#endif