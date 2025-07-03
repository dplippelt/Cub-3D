/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:05:29 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/26 19:05:44 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_vector_rotation(t_cub3d *cub3d, double x)
{
	double	tmp;

	tmp = cub3d->dir_row;
	cub3d->dir_row = cub3d->dir_row * cos(x) - cub3d->dir_col * sin(x);
	cub3d->dir_col = tmp * sin(x) + cub3d->dir_col * cos(x);
	tmp = cub3d->plane_row;
	cub3d->plane_row = cub3d->plane_row * cos(x) - cub3d->plane_col * sin(x);
	cub3d->plane_col = tmp * sin(x) + cub3d->plane_col * cos(x);
}
