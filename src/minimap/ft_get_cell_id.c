/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cell_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:38:21 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/02 10:46:29 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static int	ft_offset(int pixel_pos)
{
	int	cell_offset;

	cell_offset = pixel_pos / CELL_SIZE;
	return (7 - cell_offset);
}

int	ft_get_cell_id(int line, int i, t_mmap *mmap)
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
		return (BACKGROUND);
	if (y >= mmap->map_height || x >= mmap->map_width)
		return (BACKGROUND);
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
	return (BACKGROUND);
}
