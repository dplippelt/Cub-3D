/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vertic_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:03:10 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/19 18:11:46 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_calc_screen_y_pos(t_line *ln, t_dda dda, int screen_y)
{
	ln->hight = (int)(screen_y / dda.wall_dist);
	ln->begin = screen_y / 2 - ln->hight / 2;
	if (ln->begin < 0)
		ln->begin = 0;
	ln->end = screen_y / 2 + ln->hight / 2;
	if (ln->end >= screen_y)
		ln->end = screen_y - 1;
}

static void	ft_set_tex_pixel(char *dest, char *src, t_line ln, t_cub3d *cub3d)
{
	double			unit;
	double			texture_pos;
	int				texture_col;
	unsigned int	color;
	int				i;

	unit = (double)TEXTURE_SIZE / ln.hight;
	texture_pos = (ln.begin - (cub3d->win_y / 2 - ln.hight / 2)) * unit;
	i = ln.begin;
	while (i < ln.end)
	{
		texture_col = (int)texture_pos % TEXTURE_SIZE;
		color = *((unsigned int *)(src + texture_col * TEXTURE_SIZE * 4));
		*(unsigned int *)(dest + i * cub3d->fov.sl) = color;
		texture_pos += unit;
		++i;
	}
}

void	ft_set_ceiling_pixel(char *dest, t_line ln, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < ln.begin)
	{
		*(unsigned int *)(dest + i * cub3d->fov.sl) = cub3d->c_color;
		i++;
	}
}

void	ft_set_floor_pixel(char *dest, t_line ln, t_cub3d *cub3d)
{
	int	i;

	i = ln.end;
	while (i < cub3d->win_y - 1)
	{
		*(unsigned int *)(dest + i * cub3d->fov.sl) = cub3d->f_color;
		i++;
	}
}

void	ft_draw_vertic_line(t_cub3d *cub3d, t_rcast rc, int screen_x, int tex_x)
{
	t_imgs	target_img;
	char	*dest;
	char	*src;
	t_line	ln;

	target_img = ft_get_target_img(cub3d, rc.dda, rc.ray);
	dest = cub3d->fov.data + screen_x * 4;
	src = target_img.data + tex_x * 4;
	ft_calc_screen_y_pos(&ln, rc.dda, cub3d->win_y);
	ft_set_ceiling_pixel(dest, ln, cub3d);
	ft_set_tex_pixel(dest, src, ln, cub3d);
	ft_set_floor_pixel(dest, ln, cub3d);
}
