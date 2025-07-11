/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fps_adjustment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:24 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 12:34:20 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"

static int	ft_update_fps_settings(t_settings *di, int fps)
{
	di->show_info = 1;
	di->start_show = ft_getcurrenttime();
	if (!di->start_show)
		return (0);
	di->value = (double)fps;
	return (1);
}

static void	ft_update_fps(t_fps *fps, t_keys *keys, double *frame_time_target)
{
	if (fps->can_adjust && keys->pg_down)
	{
		if (fps->fps - 5 > 30)
			fps->fps -= 5;
		else
			fps->fps = 30;
	}
	if (fps->can_adjust && keys->pg_up)
	{
		if (fps->fps + 5 < 120)
			fps->fps += 5;
		else
			fps->fps = 120;
	}
	if (fps->can_adjust && keys->home)
		fps->fps = FPS;
	*frame_time_target = 1 / (double)fps->fps;
}

int	ft_handle_fps_adjustment(t_cub3d *cub, t_fps *fps, t_keys *keys)
{
	ft_update_fps(fps, keys, &cub->frame_time_target);
	if (fps->can_adjust && (keys->pg_up || keys->pg_down || keys->home))
	{
		fps->can_adjust = 0;
		if (!ft_update_fps_settings(&fps->set, fps->fps))
			return (0);
	}
	if (!keys->pg_up && !keys->pg_down && !keys->home)
		fps->can_adjust = 1;
	return (1);
}
