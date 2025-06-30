/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:48:04 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 15:44:47 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

int	ft_init_minimap(t_cub3d *cub)
{
	t_mmap	*mmap;

	mmap = &cub->mmap;
	mmap->map = cub->map;
	mmap->mlx = cub->mlx;
	mmap->win = cub->win;
	mmap->pos_x = &cub->pos_col;
	mmap->pos_y = &cub->pos_row;
	mmap->map_width = cub->map_data->width;
	mmap->map_height = cub->map_data->height;
	mmap->width = 300;
	mmap->height = 300;
	mmap->img.img = mlx_new_image(mmap->mlx, mmap->width, mmap->height);
	if (!mmap->img.img)
		return (ft_error(EMLXNEWIMG));
	ft_set_img_addr(&mmap->img);
	mmap->mmap = mmap->img.data;
	mmap->img.x = MM_X;
	mmap->img.y = MM_Y;
	return (1);
}
