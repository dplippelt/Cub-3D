/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:55:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/02 14:22:57 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_found_hole(t_walls *w, int y, int x)
{
	if (w->map[y][x] == '0')
		return (1);
	if (w->map[y][x] == 'N')
		return (1);
	if (w->map[y][x] == 'E')
		return (1);
	if (w->map[y][x] == 'S')
		return (1);
	if (w->map[y][x] == 'W')
		return (1);
	if (w->map[y][x] == 'C')
		return (1);
	return (0);
}

static int	ft_valid_pos(t_walls *w, int y, int x)
{
	if (y < 0)
		return (0);
	if (y >= w->height + 2)
		return (0);
	if (x < 0)
		return (0);
	if (x >= w->width + 2)
		return (0);
	if (w->map[y][x] == '1')
		return (0);
	if (w->map[y][x] == 'X')
		return (0);
	if (ft_found_hole(w, y, x))
	{
		w->valid = 0;
		return (0);
	}
	return (1);
}

static void	ft_flood_fill_rec(t_walls *w, int y, int x)
{
	if (!ft_valid_pos(w, y, x))
		return ;
	w->map[y][x] = 'X';
	ft_flood_fill_rec(w, y + 1, x);
	ft_flood_fill_rec(w, y - 1, x);
	ft_flood_fill_rec(w, y, x + 1);
	ft_flood_fill_rec(w, y, x - 1);
}

void	ft_validate_wall(t_walls *w)
{
	w->valid = 1;
	ft_flood_fill_rec(w, 0, 0);
}
