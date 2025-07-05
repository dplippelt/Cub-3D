/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:26:44 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/05 15:15:57 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	ft_rendering_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (!ft_calc_frame_time(cub3d))
		return (mlx_loop_end(cub3d->mlx), 0);
	ft_sprite_animation(cub3d);
	ft_key_action(cub3d, &cub3d->keys);
	ft_update_field_of_view(cub3d);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	if (cub3d->mmap.visible)
		ft_draw_minimap(&cub3d->mmap);
	return (1);
}
