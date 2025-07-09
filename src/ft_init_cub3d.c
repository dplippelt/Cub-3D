/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:48:53 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 15:38:49 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_cub3d(t_cub3d *cub3d, t_map *map)
{
	*cub3d = (t_cub3d){0};
	// cub3d->mlx = NULL;
	// cub3d->win = NULL;
	// cub3d->imgs = NULL;
	// cub3d->fov.img = NULL;
	// cub3d->fov.data = NULL;
	// cub3d->fov.bpp = 0;
	// cub3d->fov.sl = 0;
	// cub3d->fov.endian = 0;
	// cub3d->fov.x = 0;
	// cub3d->fov.y = 0;
	// cub3d->win_x = 0;
	// cub3d->win_y = 0;
	// cub3d->pos_row = 0;
	// cub3d->pos_col = 0;
	// cub3d->dir_row = 0;
	// cub3d->dir_col = 0;
	// cub3d->plane_row = 0;
	// cub3d->plane_col = 0;
	// cub3d->time.tv_sec = 0;
	// cub3d->time.tv_usec = 0;
	// cub3d->time.tv_sec = 0;
	// cub3d->time.tv_usec = 0;
	// cub3d->frame_time = 0;
	// cub3d->move_speed = 0;
	// cub3d->rot_speed = 0;
	// cub3d->f_color = 0;
	// cub3d->c_color = 0;
	cub3d->map = map->map;
	cub3d->map_data = map;
	cub3d->fov_factor = FOV_FACTOR;
	cub3d->can_adjust_fov = 1;
}
