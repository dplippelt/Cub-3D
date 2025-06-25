/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:48:53 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/25 17:58:02 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_found_player(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

static void ft_get_player_dir(t_cub3d *cub3d, char c)
{
	if (c == 'N')
	{
		cub3d->dir_row = -1;
		cub3d->dir_col = 0;
		cub3d->plane_row = 0;
		cub3d->plane_col = 0.66;
	}
	if (c == 'E')
	{
		cub3d->dir_row = 0;
		cub3d->dir_col = 1;
		cub3d->plane_row = -0.66;
		cub3d->plane_col = 0;
	}
	if (c == 'S')
	{
		cub3d->dir_row = 1;
		cub3d->dir_col = 0;
		cub3d->plane_row = 0;
		cub3d->plane_col = -0.66;
	}
	if (c == 'W')
	{
		cub3d->dir_row = 0;
		cub3d->dir_col = -1;
		cub3d->plane_row = 0.66;
		cub3d->plane_col = 0;
	}
}

static void	ft_get_player_pos(t_cub3d *cub3d, char **map)
{
	int		y;
	int		x;
	int		found_player;

	found_player = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_found_player(map[y][x]))
			{
				cub3d->pos_row = (double)y + 0.5;
				cub3d->pos_col = (double)x + 0.5;
				ft_get_player_dir(cub3d, map[y][x]);
				return ;
			}
			x++;				
		}
		y++;
	}
}

void	ft_init_cub3d(t_cub3d *cub3d, char **map)
{
	*cub3d = (t_cub3d){0};
	// cub3d->mlx = NULL;
	// cub3d->win = NULL;
	// cub3d->imgs = NULL;
	// cub3d->fov.img = NULL;
	// cub3d->fov.data = NULL;
	// cub3d->fov.bpp = 0;
	// cub3d->fov.sl = 0;
	// cub3d->fov.endian = 0;
	// cub3d->fov.x = 0;
	// cub3d->fov.y = 0;
	// cub3d->win_x = 0;
	// cub3d->win_y = 0;
	// cub3d->pos_row = 0;
	// cub3d->pos_col = 0;
	// cub3d->dir_row = 0;
	// cub3d->dir_col = 0;
	// cub3d->plane_row = 0;
	// cub3d->plane_col = 0;
	// cub3d->time.tv_sec = 0;
	// cub3d->time.tv_usec = 0;
	// cub3d->time.tv_sec = 0;
	// cub3d->time.tv_usec = 0;
	// cub3d->frame_time = 0;
	// cub3d->move_speed = 0;
	// cub3d->rot_speed = 0;
	// cub3d->f_color = 0;
	// cub3d->c_color = 0;
	cub3d->map = map;	
	ft_get_player_pos(cub3d, map);
}
