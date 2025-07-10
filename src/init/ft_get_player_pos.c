/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:54:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 12:58:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

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
