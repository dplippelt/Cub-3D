/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_playable_area.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:23 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/02 14:45:30 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_found_hole(t_map_val *map, int y, int x)
{
	if (map->map[y][x] == ' ')
		return (1);
	return (0);
}

static int	ft_valid_pos(t_map_val *map, int y, int x)
{
	if (y < 0)
		return (0);
	if (y >= map->height + 2)
		return (0);
	if (x < 0)
		return (0);
	if (x >= map->width + 2)
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

void	ft_validate_playable_area(t_map_val *map)
{
	map->valid = 1;
	ft_get_player_pos(&map->player, map->map);
	ft_flood_fill_rec(map, map->player.y, map->player.x);
}
