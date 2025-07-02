/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:48:04 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/02 11:22:04 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	ft_set_minimap_dimensions(t_mmap *mmap, int win_w, int win_h)
{
	int	size;
	int	vis_dist;

	size = 0;
	vis_dist = 0;
	if (win_h < win_w)
		size = win_h;
	size /= 5;
	size -= (size % CELL_SIZE);
	if ((size / CELL_SIZE) % 2 == 0)
		size += CELL_SIZE;
	if (size > MM_MAX_SIZE)
		size = MM_MAX_SIZE;
	vis_dist = (size / CELL_SIZE) / 2;
	mmap->height = size;
	mmap->width = size;
	mmap->vis_dist = vis_dist;
}

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
	ft_set_minimap_dimensions(mmap, cub->win_x, cub->win_y);
	mmap->img.img = mlx_new_image(mmap->mlx, mmap->width, mmap->height);
	if (!mmap->img.img)
		return (ft_error(EMLXNEWIMG));
	ft_set_img_addr(&mmap->img);
	mmap->mmap = mmap->img.data;
	mmap->img.x = MM_X;
	mmap->img.y = MM_Y;
	return (1);
}
