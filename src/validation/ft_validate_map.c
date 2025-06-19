/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:37:48 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 17:49:18 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_init_walls(t_walls *w, t_map m)
{
	w->valid = 1;
	w->height = m.height;
	w->width = m.width;
	w->pos = (t_pos){0};
	if (!ft_copy_map_with_border(&w->map, m.map, m.width))
		return (0);
	return (1);
}

int	ft_validate_map(t_map m)
{
	t_walls	w;

	if (!ft_init_walls(&w, m))
		return (0);
	ft_check_wall(&w);
	if (!w.valid)
	{
		ft_cleanup_str_array(w.map);
		return (ft_error(EWALL));
	}
	ft_cleanup_str_array(w.map);
	return (1);
}
