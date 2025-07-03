/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_doors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:36:04 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 16:21:20 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_destroy_doors(t_cub3d *cub3d)
{
	size_t	i;

	if (cub3d->doors)
	{
		i = 0;
		while (cub3d->doors[i])
		{
			free(cub3d->doors[i]);
			i++;
		}
		free(cub3d->doors);
	}	
}

void	ft_print_doors(t_door **doors, size_t width)
{
	size_t	i;
	size_t	j;

	if (!doors)
		return ;
	printf("here\n");
	i = 0;
	while (doors[i])
	{
		j = 0;
		while (j < width)
		{
			if (doors[i][j].texid == DOOR)
			{
				printf("map row %zu, map col %zu\n", i, j);
				printf("pos row %f, pos col %f\n", doors[i][j].row, doors[i][j].col);
			}
			j++;
		}
		i++;
	}
}