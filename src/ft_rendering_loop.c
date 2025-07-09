/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:26:44 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/09 17:58:53 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	ft_show_info(t_display_info *di, void *mlx, void *win)
{
	long	ct;

	ct = 0;
	if (di->show_info)
	{
		ct = ft_getcurrenttime();
		if (!ct)
			return (0);
		if (ct - di->start_show < 2000)
		{
			mlx_string_put(mlx, win, 600, 50, 0xFFFFFF00, di->type);
			mlx_string_put(mlx, win, 690, 50, 0xFFFFFF00, di->value);
		}
		else
		{
			di->start_show = 0;
			di->show_info = 0;
		}
	}
	return (1);
}

int	ft_rendering_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (!ft_calc_frame_time(cub3d))
		return (mlx_loop_end(cub3d->mlx), 0);
	ft_key_action(cub3d, &cub3d->keys);
	ft_sprite_animation(cub3d);
	ft_door_status_check(cub3d);
	ft_update_field_of_view(cub3d);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	if (cub3d->mmap.visible)
		ft_draw_minimap(&cub3d->mmap);
	if (!ft_show_info(&cub3d->mouse.rot.display_info, cub3d->mlx, cub3d->win))
		return (mlx_loop_end(cub3d->mlx), 0);
	return (1);
}
