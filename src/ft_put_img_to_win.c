/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:18:47 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/19 17:24:08 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_img_to_win(t_img *img, t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, img, 0, 0);
}
