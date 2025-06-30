/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:33:50 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 12:58:25 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	ft_fill_line(char *img_data, int line_len, int bytespp)
{
	int	i;
	int	*pxl_start;
	int	color;

	color = BGRA(255, 0, 0, 0);

	i = 0;
	while (i < line_len)
	{
		pxl_start = (int *)(img_data + i);
		*pxl_start = color;
		i += bytespp;
	}
}

static void	ft_fill_image_buffer(t_mmap *mmap)
{
	char	*img_data;
	int		line_len;
	int		bytespp;
	int		y;

	img_data = mmap->mmap;
	line_len = mmap->img.sl;
	bytespp = mmap->img.bpp / 8;
	y = 0;
	while (y < mmap->height)
	{
		ft_fill_line(&img_data[y * line_len], line_len, bytespp);
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
	if (!mlx_put_image_to_window(mlx, win, img->img, img->x, img->y))
		return (0); //needs ft_error() call
	return (1);
}
