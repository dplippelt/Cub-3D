/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:59:30 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 18:18:32 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_zero(t_door *door, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		door[i++] = (t_door){0};
}

static int	ft_set_doors_info(t_door *door, t_map map, size_t i, size_t j)
{
	if (map.map[i - 1][j] == '1' && map.map[i + 1][j] == '1')
		door->dir = ROW_SIDE;
	else if (map.map[i][j - 1] == '1' && map.map[i][j + 1] == '1')
		door->dir = COL_SIDE;
	else
		return (0);
	if (door->dir == ROW_SIDE)
	{
		door->row = i;
		door->col = j + 0.5;
	}
	else
	{
		door->row = i + 0.5;
		door->col = j;
	}
	door->status = CLOSE;
	door->time = 0;
	door->texid = DOOR;
	return (1);
}

static int	ft_loading_doors(t_door **doors, t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'D')
			{
				if (!ft_set_doors_info(&doors[i][j], map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_init_doors(t_cub3d *cub3d, t_map map)
{
	size_t	i;
	int		flag;

	cub3d->doors = (t_door **)malloc(sizeof(t_door *) * (map.height + 1));
	if (!cub3d->doors)
		return (0);
	i = 0;
	flag = 0;
	while (i < map.height)
	{
		cub3d->doors[i] = (t_door *)malloc(sizeof(t_door) * (map.width + 1));
		if (!cub3d->doors[i])
			flag = 1;
		else
			ft_set_zero(cub3d->doors[i], map.width);
		i++;
	}
	cub3d->doors[map.height] = NULL;
	if (flag)
		return (0);
	if (!ft_loading_doors(cub3d->doors, map))
		return (0);
	return (1);
}
