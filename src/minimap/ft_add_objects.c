/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:12:00 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/02 15:37:18 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	ft_draw_object(int line, int i, int color, t_mmap *mmap)
{
	char	*curr_img_data;
	int		*pxl_start;
	int		i_start;
	int		x;
	int		y;

	i_start = i + (mmap->player_border * (mmap->img.bpp / 8));
	y = mmap->player_border;
	line += mmap->player_border;
	while (y < mmap->cell_size - mmap->player_border)
	{
		curr_img_data = &mmap->img.data[(line * mmap->img.sl)];
		i = i_start;
		x = mmap->player_border;
		while (x < mmap->cell_size - mmap->player_border)
		{
			pxl_start = (int *)(curr_img_data + i);
			*pxl_start = color;
			i += mmap->img.bpp / 8;
			x++;
		}
		y++;
		line++;
	}
}

static void	ft_check_pixel(int y, int i, int *drew_obj, t_mmap *mmap)
{
	int	cell_id;

	cell_id = ft_get_cell_id(y, i, mmap);
	if (cell_id == SQUIRREL)
		ft_draw_object(y, i, SQUIRREL_COLOR, mmap);
	if (cell_id == PLAYER)
		ft_draw_object(y, i, PLAYER_COLOR, mmap);
	if (cell_id == PLAYER || cell_id == SQUIRREL)
		*drew_obj = 1;
}

void	ft_add_objects(t_mmap *mmap)
{
	int	y;
	int	i;
	int	drew_obj;

	y = 0;
	while (y < mmap->height)
	{
		i = 0;
		drew_obj = 0;
		while (i < mmap->img.sl)
		{
			ft_check_pixel(y, i, &drew_obj, mmap);
			if (drew_obj)
				i += (mmap->img.bpp / 8) * mmap->cell_size;
			else
				i += mmap->img.bpp / 8;
		}
		if (drew_obj)
			y += mmap->cell_size;
		else
			y++;
	}
}
