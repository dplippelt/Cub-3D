/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_condition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:02:23 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/26 14:47:36 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_rgb_to_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

static int	ft_found_player(char c)
{
	if (c == 'N')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'W')
		return (1);
	return (0);
}

static void ft_set_player_dir(t_cub3d *cub3d, char c)
{
	if (c == 'N')
	{
		cub3d->dir_row = -1;
		cub3d->plane_col = 0.66;
	}
	else if (c == 'E')
	{
		cub3d->dir_col = 1;
		cub3d->plane_row = 0.66;
	}
	else if (c == 'S')
	{
		cub3d->dir_row = 1;
		cub3d->plane_col = -0.66;
	}
	else if (c == 'W')
	{
		cub3d->dir_col = -1;
		cub3d->plane_row = -0.66;
	}
}

static void	ft_init_player(t_cub3d *cub3d)
{
	int	row;
	int	col;

	row = 0;
	while (cub3d->map[row])
	{
		col = 0;
		while (cub3d->map[row][col])
		{
			if (ft_found_player(cub3d->map[row][col]))
			{
				cub3d->pos_row = (double)row + 0.5;
				cub3d->pos_col = (double)col + 0.5;
				ft_set_player_dir(cub3d, cub3d->map[row][col]);
				return ;
			}
			col++;
		}
		row++;
	}
}

int	ft_init_game_condition(t_cub3d *cub3d, t_col *col)
{
	ft_init_player(cub3d);
	if (gettimeofday(&cub3d->time, NULL) < 0)
		return (0);
	cub3d->prev_time = cub3d->time;
	cub3d->c_color = ft_rgb_to_color(40, 40, 40); // temporary
	cub3d->f_color = ft_rgb_to_color(70, 8, 8); // temporary (100,8,8) / (70,8,8)
	return (1);
}
