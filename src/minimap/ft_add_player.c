/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:12:00 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 18:04:10 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	ft_draw_player(int line, int i, t_mmap *mmap)
{
	char	*curr_img_data;
	int		*pxl_start;
	int		i_start;
	int		x;
	int		y;

	i_start = i + (MM_PLAYER_BORDER_X * (mmap->img.bpp / 8));
	y = MM_PLAYER_BORDER_Y;
	line += MM_PLAYER_BORDER_Y;
	while (y < CELL_SIZE - MM_PLAYER_BORDER_Y)
	{
		curr_img_data = &mmap->img.data[(line * mmap->img.sl)];
		i = i_start;
		x = 3;
		while (x < CELL_SIZE - MM_PLAYER_BORDER_X)
		{
			pxl_start = (int *)(curr_img_data + i);
			*pxl_start = BGRA(0,100,0,0);
			i += mmap->img.bpp / 8;
			x++;
		}
		y++;
		line++;
	}
}

void	ft_add_player(t_mmap *mmap)
{
	int	y;
	int	i;
	int	cell_id;

	y = 0;
	while (y < mmap->height)
	{
		i = 0;
		while (i < mmap->img.sl)
		{
			cell_id = ft_get_cell_id(y, i, mmap);
			if (cell_id == PLAYER)
			{
				ft_draw_player(y, i, mmap);
				return ;
			}
			i += mmap->img.bpp / 8;
		}
		y++;
	}
}
