/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:35:27 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/26 10:53:21 by dlippelt         ###   ########.fr       */
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

static int	ft_count_players(char **map)
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
}

int	ft_validate_player(t_map *map)
{
	if (ft_count_players(map->map) != 1)
		return (ft_error(ENUMPLAYERS));
	return (1);
}
