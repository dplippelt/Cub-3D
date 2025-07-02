/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cell_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:38:21 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/02 15:05:47 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static int	ft_offset(int pixel_pos, t_mmap *mmap)
{
	int	cell_offset;

	cell_offset = pixel_pos / mmap->cell_size;
	return (mmap->vis_dist - cell_offset);
}

static int	ft_is_player_cell(char **map, int x, int y)
{
	if (map[y][x] == 'N')
		return (1);
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] == 'S')
		return (1);
	if (map[y][x] == 'W')
		return (1);
	return (0);
}

int	ft_get_cell_id(int line, int i, t_mmap *mmap)
{
	int	x;
	int	y;
	int	x_offset;
	int	y_offset;

	x_offset = ft_offset(i / (mmap->img.bpp / 8), mmap);
	y_offset = ft_offset(line, mmap);
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
	if (mmap->map[y][x] == 'C')
		return (SQUIRREL);
	if (ft_is_player_cell(mmap->map, x, y))
		return (FLOOR);
	return (BACKGROUND);
}
