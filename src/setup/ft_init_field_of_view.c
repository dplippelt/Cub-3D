/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_field_of_view.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:01:52 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 12:49:56 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_field_of_view(t_cub3d *cub3d)
{
	cub3d->fov_data.fov_factor = FOV_FACTOR;
	cub3d->fov_data.can_adjust = 1;
	cub3d->fov.x = cub3d->win_x;
	cub3d->fov.y = cub3d->win_y;
	cub3d->fov.img = mlx_new_image(cub3d->mlx, cub3d->win_x, cub3d->win_y);
	if (!cub3d->fov.img)
		return (ft_error(EMLXNEWIMG));
	ft_set_img_addr(&cub3d->fov);
	return (1);
}
