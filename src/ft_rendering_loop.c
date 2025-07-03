/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:26:44 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 16:06:53 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	ft_rendering_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (!ft_calc_frame_time(cub3d))
		return (0);
	ft_update_field_of_view(cub3d);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	ft_draw_minimap(&cub3d->mmap);
	return (1);
}
