/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_target_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:05:09 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/19 18:05:28 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_imgs	ft_get_target_img(t_cub3d *cub3d, t_dda dda, t_ray ray)
{
	if (dda.side == ROW_SIDE)
	{
		if (ray.dir_row > 0)
			return (cub3d->imgs[EA]);
		else
			return (cub3d->imgs[WE]);
	}
	else
	{
		if (ray.dir_col > 0)
			return (cub3d->imgs[SO]);
		else
			return (cub3d->imgs[NO]);
	}
}
