/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:55:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:18:07 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_found_hole(t_map_val *map, int y, int x)
{
	if (map->map[y][x] == '0')
		return (1);
	if (map->map[y][x] == 'N')
		return (1);
	if (map->map[y][x] == 'E')
		return (1);
	if (map->map[y][x] == 'S')
		return (1);
	if (map->map[y][x] == 'W')
		return (1);
	if (map->map[y][x] == 'C')
		return (1);
	if (map->map[y][x] == 'D')
		return (1);
	return (0);
}

static int	ft_valid_pos(t_map_val *map, int y, int x)
{
	if (y < 0)
		return (0);
	if (y >= map->height)
		return (0);
	if (x < 0)
		return (0);
	if (x >= map->width)
		return (0);
	if (map->map[y][x] == '1')
		return (0);
	if (map->map[y][x] == 'X')
		return (0);
	if (ft_found_hole(map, y, x))
	{
		map->valid = 0;
		return (0);
	}
	return (1);
}

static void	ft_flood_fill_rec(t_map_val *map, int y, int x)
{
	if (!ft_valid_pos(map, y, x))
		return ;
	map->map[y][x] = 'X';
	ft_flood_fill_rec(map, y + 1, x);
	ft_flood_fill_rec(map, y - 1, x);
	ft_flood_fill_rec(map, y, x + 1);
	ft_flood_fill_rec(map, y, x - 1);
}

int	ft_validate_wall(t_map_val *map)
{
	ft_flood_fill_rec(map, 0, 0);
	return (map->valid);
}
