/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:48:53 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 19:44:43 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_cub3d(t_cub3d *cub3d, t_map *map)
{
	*cub3d = (t_cub3d){0};
	cub3d->map = map->map;
	cub3d->map_data = map;
}
