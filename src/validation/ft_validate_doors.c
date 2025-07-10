/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_doors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:02:17 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 13:06:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_validate_door(char **map, int x, int y)
{
	if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
		return (1);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
		return (1);
	return (0);
}

int	ft_validate_doors(t_map_val *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'D')
			{
				if (!ft_validate_door(map->map, x, y))
				{
					map->valid = 0;
					return (map->valid);
				}
			}
			x++;
		}
		y++;
	}
	return (map->valid);
}
