/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:48:04 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/08 14:43:17 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static int	ft_set_minimap_cell_size(int win_w, int win_h)
{
	if (win_w <= 720 || win_h <= (720 * 3 / 4))
		return (CELL_SIZE_DEFAULT * 3 / 4);
	return (CELL_SIZE_DEFAULT);
}

static int	ft_set_minimap_player_border(int win_w, int win_h)
{
	if (win_w <= 720 || win_h <= (720 * 3 / 4))
		return (PLAYER_BORDER_DEFAULT - 1);
	return (PLAYER_BORDER_DEFAULT);
}

static int	ft_set_minimap_size(int win_w, int win_h, int cell_size)
{
	int	size;

	size = win_h;
	if (win_h > win_w)
		size = win_w;
	size /= 5;
	size -= (size % cell_size);
	if ((size / cell_size) % 2 == 0)
		size += cell_size;
	if (size > MM_MAX_SIZE)
		size = MM_MAX_SIZE;
	return (size);
}

static void	ft_set_minimap_dimensions(t_mmap *mmap, int win_w, int win_h)
{
	int	size;
	int	vis_dist;
	int	cell_size;
	int	player_border;

	cell_size = ft_set_minimap_cell_size(win_w, win_h);
	player_border = ft_set_minimap_player_border(win_w, win_h);
	size = ft_set_minimap_size(win_w, win_h, cell_size);
	vis_dist = (size / cell_size) / 2;
	mmap->height = size;
	mmap->width = size;
	mmap->vis_dist = vis_dist;
	mmap->cell_size = cell_size;
	mmap->player_border = player_border;
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
	mmap->img.x = cub->win_x / MM_POS;
	mmap->img.y = mmap->img.x;
	mmap->cols.wall = ft_bgra(128, 128, 128, 0);
	mmap->cols.background = ft_bgra(64, 64, 64, 0);
	mmap->cols.floor = ft_bgra(0, 0, 100, 0);
	mmap->cols.player = ft_bgra(0, 100, 0, 0);
	mmap->cols.door_closed = ft_bgra(0, 120, 150, 0);
	mmap->cols.door_open = ft_bgra(0, 70, 100, 0);
	mmap->cols.squirrel = ft_bgra(19, 69, 139, 0);	//Medium Brown
	// mmap->cols.squirrel = ft_bgra(63, 133, 205, 0);	//Light Brown
	// mmap->cols.squirrel = ft_bgra(33, 67, 101, 0);	//Dark Brown
	// mmap->cols.squirrel = ft_bgra(0, 215, 255, 0);	//Gold
	mmap->can_toggle = 1;
	mmap->visible = 1;
	return (1);
}
