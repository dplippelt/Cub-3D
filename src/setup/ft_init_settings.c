/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:17:35 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 14:40:23 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_settings(t_cub3d *cub)
{
	t_settings	*sens;
	t_settings	*fov;

	sens = &cub->mouse.rot.set;
	fov = &cub->fov_data.set;
	sens->show_info = 0;
	sens->start_show = 0;
	sens->value = 0;
	sens->set_x = cub->mmap.img.x + 5;
	sens->set_y = cub->mmap.img.y + cub->mmap.height + 20;
	fov->show_info = 0;
	fov->start_show = 0;
	fov->value = 0;
	fov->set_x = cub->mmap.img.x + 5;
	fov->set_y = cub->mmap.img.y + cub->mmap.height + 40;
}
