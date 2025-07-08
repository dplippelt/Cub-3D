/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:37:48 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/08 13:03:54 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_init_map_val(t_map_val *map_val, t_map map)
{
	map_val->height = map.height;
	map_val->width = map.width;
	map_val->valid = 1;
	if (!ft_copy_map_with_border(&map_val->map, map.map, map.width))
		return (0);
	return (1);
}

int	ft_validate_map(t_map *map)
{
	t_map_val	map_val;

	if (!ft_init_map_val(&map_val, *map))
		return (0);
	if (!ft_validate_wall(&map_val))
		return (ft_error(EWALL));
	if (!ft_validate_player(map))
		return (ft_error(ENUMPLAYERS));
	if (!ft_validate_playable_area(&map_val))
		return (ft_error(EMAP));
	ft_cleanup_str_array(map_val.map);
	return (1);
}
