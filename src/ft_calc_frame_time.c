/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_frame_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:39:09 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 17:53:22 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_get_time_diff_sec(struct timeval curr, struct timeval prev)
{
	double	usec_now;
	double	usec_from;

	usec_now = curr.tv_sec * 1e6 + curr.tv_usec;
	usec_from = prev.tv_sec * 1e6 + prev.tv_usec;
	return ((usec_now - usec_from) / 1e6);
}

int	ft_calc_frame_time(t_cub3d *cub3d)
{
	cub3d->prev_time = cub3d->time;
	if (gettimeofday(&cub3d->time, NULL) < 0)
		return (ft_error(EGETTIME));
	cub3d->frame_time = ft_get_time_diff_sec(cub3d->time, cub3d->prev_time);
	cub3d->move_speed = DIST_PER_SECOND * cub3d->frame_time;
	cub3d->rot_speed = RADIAN_PER_SECOND * cub3d->frame_time;
	return (1);
}
