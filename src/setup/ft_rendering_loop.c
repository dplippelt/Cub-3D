/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:26:44 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 15:43:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "rendering.h"

static int	ft_frame_rate_limiter(t_cub3d *cub3d)
{
	long	time_diff;
	long	st;

	if (gettimeofday(&cub3d->time, NULL) < 0)
		return (ft_error(EGETTIME));
	time_diff = ft_get_time_diff_usec(cub3d->time, cub3d->prev_time);
	if (time_diff < 0)
		time_diff = cub3d->frame_time * 1e6;
	if (time_diff < cub3d->frame_time_target * 1e6)
	{
		st = cub3d->time.tv_sec * 1e6 + cub3d->time.tv_usec;
		ft_usleep(cub3d->frame_time_target * 1e6 - time_diff, st);
	}
	if (gettimeofday(&cub3d->prev_time, NULL) < 0)
		return (ft_error(EGETTIME));
	if (time_diff > cub3d->frame_time_target * 1e6)
		cub3d->frame_time = time_diff / 1e6;
	else
		cub3d->frame_time = cub3d->frame_time_target;
	return (1);
}

int	ft_rendering_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (!ft_frame_rate_limiter(cub3d))
		return (mlx_loop_end(cub3d->mlx), 0);
	if (!ft_calc_frame_time(cub3d))
		return (mlx_loop_end(cub3d->mlx), 0);
	ft_key_action(cub3d, &cub3d->keys);
	ft_sprite_animation(cub3d);
	ft_door_positioning(cub3d);
	ft_update_field_of_view(cub3d);
	ft_sprite_casting(cub3d, cub3d->sprite);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	if (cub3d->mmap.visible)
		ft_draw_minimap(&cub3d->mmap);
	if (cub3d->fps_counter.visible)
		ft_show_fps(&cub3d->fps_counter, cub3d->mlx, cub3d->win);
	if (!ft_show_sens_settings(&cub3d->mouse.rot.set, cub3d->mlx, cub3d->win))
		return (mlx_loop_end(cub3d->mlx), 0);
	if (!ft_show_fov_settings(&cub3d->fov_data.set, cub3d->mlx, cub3d->win))
		return (mlx_loop_end(cub3d->mlx), 0);
	if (!ft_show_fps_settings(&cub3d->fps.set, cub3d->mlx, cub3d->win))
		return (mlx_loop_end(cub3d->mlx), 0);
	return (1);
}
