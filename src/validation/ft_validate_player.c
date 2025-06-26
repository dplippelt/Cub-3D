/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:35:27 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/26 11:05:01 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_found_player(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

static size_t	ft_count_players(char **map)
{
	size_t	y;
	size_t	x;
	size_t	nplayers;

	nplayers = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_found_player(map[y][x]))
				nplayers++;
			x++;
		}
		y++;
	}
	return (nplayers);
}

int	ft_validate_player(t_map *map)
{
	if (ft_count_players(map->map) != 1)
		return (ft_error(ENUMPLAYERS));
	return (1);
}

void	ft_get_player_pos(t_pos *player, char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_found_player(map[y][x]))
			{
				player->y = y;
				player->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
