/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:17:35 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 12:00:06 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

void	ft_init_settings(t_cub3d *cub)
{
	t_settings	*sens;
	t_settings	*fov;
	t_settings	*fps;

	sens = &cub->mouse.rot.set;
	fov = &cub->fov_data.set;
	fps = &cub->fps.set;
	*fov = (t_settings){0};
	*sens = (t_settings){0};
	*fps = (t_settings){0};
	cub->mouse.rot.can_adjust = 1;
	cub->mouse.rot.sens = MOUSE_SENS;
	sens->set_x = cub->mmap.img.x + 5;
	sens->set_y = cub->mmap.img.y + cub->mmap.height + 20;
	cub->fov_data.can_adjust = 1;
	cub->fov_data.fov_factor = FOV_FACTOR;
	fov->set_x = cub->mmap.img.x + 5;
	fov->set_y = cub->mmap.img.y + cub->mmap.height + 40;
	cub->fps.can_adjust = 1;
	cub->fps.fps = FPS;
	fps->set_x = cub->mmap.img.x + 5;
	fps->set_y = cub->mmap.img.y + cub->mmap.height + 60;
}
