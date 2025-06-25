/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_condition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:02:23 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/25 17:56:41 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_rgb_to_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

int	ft_init_game_condition(t_cub3d *cub3d)
{
	// TODO: depends on the player position (N / S / W / E)
	// cub3d->pos_row = 1.5;
	// cub3d->pos_col = 2.5;
	// TODO: depends on the N / S / W / E character
	// cub3d->dir_row = 1;
	// cub3d->dir_col = 0;
	// plane dir always points to the positive direction
	// cub3d->plane_row = 0;
	// cub3d->plane_col = -0.66;
	if (gettimeofday(&cub3d->time, NULL) < 0)
		return (0);
	cub3d->prev_time = cub3d->time;
	// TODO: get from the map data
	cub3d->c_color = ft_rgb_to_color(40, 40, 40); // temporary
	cub3d->f_color = ft_rgb_to_color(70, 8, 8); // temporary (100,8,8) / (70,8,8)
	return (1);
}
