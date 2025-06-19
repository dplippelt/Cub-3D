/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:04:15 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 15:38:19 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void	ft_set_next_wall(t_walls *w, int x, int y)
{
	w->map[w->next.y][w->next.x] = 'X';
	w->next.y += y;
	w->next.x += x;
	if (w->next.y == w->start.y && w->next.x == w->start.x)
		w->valid = 1;
	ft_check_next_wall(w);
}

static int	ft_is_next_wall(t_walls *w, int x, int y)
{
	ssize_t	new_y;
	ssize_t	new_x;

	new_y = w->next.y + y;
	new_x = w->next.x + x;
	if (new_y > (ssize_t)w->height - 1 || new_y < 0)
		return (0);
	if (new_x > (ssize_t)w->width - 1 || new_x < 0)
		return (0);
	if (w->map[new_y][new_x] == '1')
		return (1);
	return (0);
}

void	ft_check_next_wall(t_walls *w)
{
	if (w->valid)
		return ;
	if (ft_is_next_wall(w, 0, 1)) //UP
		ft_set_next_wall(w, 0, 1);
	if (ft_is_next_wall(w, 0, -1)) //DOWN
		ft_set_next_wall(w, 0, -1);
	if (ft_is_next_wall(w, 1, 0)) //RIGHT
		ft_set_next_wall(w, 1, 0);
	if (ft_is_next_wall(w, -1, 0)) //LEFT
		ft_set_next_wall(w, -1, 0);
}
