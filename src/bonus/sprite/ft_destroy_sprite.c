/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:05:14 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 18:08:48 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_destroy_sprite(t_cub3d *cub3d)
{
	if (cub3d->sprite)
		free(cub3d->sprite);
	if (cub3d->wall_dists)
		free(cub3d->wall_dists);
}
