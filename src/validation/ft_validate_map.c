/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:37:48 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 15:36:14 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static t_coord	ft_find_start_wall(char **m)
{
	t_coord	start;

	start = (t_coord){0};
	while (m[start.y][start.x])
	{
		if (m[start.y][start.x] == '1')
			break ;
		start.x++;
	}
	return (start);
}

static int	ft_check_wall(t_walls *w)
{
	w->start = ft_find_start_wall(w->map);
	w->next = w->start;
	if (w->map[w->start.y][w->start.x + 1] == '1')
		ft_set_next_wall(w, 1, 0);
	if (w->map[w->start.y + 1][w->start.x] == '1')
		ft_set_next_wall(w, 0, 1);
	debug_print_current_coords(w);
	return (w->valid);
}

static int	ft_init_walls(t_walls *w, t_map m)
{
	w->valid = 0;
	w->height = m.height;
	w->width = m.width;
	w->start = (t_coord){0};
	w->next = (t_coord){0};
	if (!ft_copy_str_array(&w->map, m.map))
		return (0);
	return (1);
}

int	ft_validate_map(t_map m)
{
	t_walls	w;

	if (!ft_init_walls(&w, m))
		return (0);
	if (!ft_check_wall(&w))
	{
		ft_cleanup_str_array(w.map);
		return (ft_error(EWALL));
	}
	ft_cleanup_str_array(w.map);
	return (1);
}
