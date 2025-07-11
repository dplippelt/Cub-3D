/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_frame_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:39:09 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/11 12:47:19 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

//Rename function
int	ft_calc_frame_time(t_cub3d *cub3d)
{
	// cub3d->prev_time = cub3d->time;
	// if (gettimeofday(&cub3d->time, NULL) < 0)
	// 	return (ft_error(EGETTIME));
	// cub3d->frame_time = 1 / (double)FPS;
	// cub3d->frame_time = ft_get_time_diff_sec(cub3d->time, cub3d->prev_time);
	cub3d->move_speed = DIST_PER_SECOND * cub3d->frame_time;
	cub3d->rot_speed = RADIAN_PER_SECOND * cub3d->frame_time;
	return (1);
}
