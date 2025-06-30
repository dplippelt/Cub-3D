/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:33:50 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 15:44:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

//make walls 10x10 pixels

static int	ft_offset(int pixel_pos)
{
	int	cell_offset;

	cell_offset = pixel_pos / CELL_SIZE;
	return (7 - cell_offset);
}

static int	ft_get_cell_id(int line, int i, t_mmap *mmap)
{
	int	x;
	int	y;
	int	x_offset;
	int	y_offset;

	x_offset = ft_offset(i / (mmap->img.bpp / 8));
	y_offset = ft_offset(line);
	if (x_offset == 0 && y_offset == 0)
		return (PLAYER);
	y = (int)*mmap->pos_y - y_offset;
	x = (int)*mmap->pos_x - x_offset;
	if (y < 0 || x < 0)
		return (NOTHING);
	if (y >= mmap->map_height || x >= mmap->map_width)
		return (NOTHING);
	if (mmap->map[y][x] == '0')
		return (FLOOR);
	if (mmap->map[y][x] == '1')
		return (WALL);
	if (mmap->map[y][x] == 'N')
		return (FLOOR);
	if (mmap->map[y][x] == 'E')
		return (FLOOR);
	if (mmap->map[y][x] == 'S')
		return (FLOOR);
	if (mmap->map[y][x] == 'W')
		return (FLOOR);
	return (NOTHING);
}

static void	ft_fill_line(int y, t_mmap *mmap)
{
	int		i;
	int		color;
	int		*pxl_start;
	char	*curr_img_data;
	int		cell_id;

	curr_img_data = &mmap->mmap[y * mmap->img.sl];
	i = 0;
	while (i < mmap->img.sl)
	{
		cell_id = ft_get_cell_id(y, i, mmap);
		if (cell_id == WALL)
			color = BGRA(128, 128, 128, 0);
		else if (cell_id == NOTHING)
			color = BGRA(64, 64, 64, 0);
		else if (cell_id == FLOOR)
			color = BGRA(0, 0, 100, 0);
		else if (cell_id == PLAYER)
			color = BGRA(0, 100, 0, 0);
		pxl_start = (int *)(curr_img_data + i);
		*pxl_start = color;
		i += mmap->img.bpp / 8;
	}
}

static void	ft_fill_image_buffer(t_mmap *mmap)
{
	char	*img_data;
	int		y;

	img_data = mmap->mmap;
	y = 0;
	while (y < mmap->height)
	{
		ft_fill_line(y, mmap);
		y++;
	}
}

int	ft_draw_minimap(t_mmap *mmap)
{
	static t_imgs	*img;
	static void		*mlx;
	static void		*win;

	img = &mmap->img;
	mlx = mmap->mlx;
	win = mmap->win;
	ft_fill_image_buffer(mmap);
	mlx_put_image_to_window(mlx, win, img->img, img->x, img->y);
	return (1);
}
