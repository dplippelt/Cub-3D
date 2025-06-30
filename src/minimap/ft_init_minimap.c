/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:48:04 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 12:59:38 by dlippelt         ###   ########.fr       */
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
	mmap->pos_x = &cub->pos_row;
	mlx_get_screen_size(mmap->mlx, &mmap->screen_width, &mmap->screen_height);
	mmap->width = cub->win_x / 5;
	mmap->height = cub->win_y / 5;
	mmap->img.img = mlx_new_image(mmap->mlx, mmap->width, mmap->height);
	if (!mmap->img.img)
		return (ft_error(EMLXNEWIMG));
	ft_set_img_addr(&mmap->img);
	mmap->mmap = mmap->img.data;
	mmap->img.x = 50;
	mmap->img.y = 50;
	return (1);
}
