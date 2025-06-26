/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_condition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:02:23 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/26 17:49:48 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_player_dir(t_cub3d *cub3d, char c)
{
	if (c == 'N')
		cub3d->dir_row = -1;
	if (c == 'E')
		cub3d->dir_col = 1;
	if (c == 'S')
		cub3d->dir_row = 1;
	if (c == 'W')
		cub3d->dir_col = -1;
	cub3d->plane_row = 0.66 * cub3d->dir_col;
	cub3d->plane_col = -0.66 * cub3d->dir_row;
}

static void	ft_init_player(t_cub3d *cub3d, t_pos player, char **map)
{
	cub3d->pos_col = (double)player.x + 0.5;
	cub3d->pos_row = (double)player.y + 0.5;
	ft_set_player_dir(cub3d, map[player.y][player.x]);
}

static int	ft_rgb_to_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

static void	ft_get_color(t_cub3d *cub3d, t_col *col)
{
	while (col)
	{
		if (col->id == COLFLOOR)
			cub3d->f_color = ft_rgb_to_color(col->r, col->g, col->b);
		else if (col->id == COLCEILING)
			cub3d->c_color = ft_rgb_to_color(col->r, col->g, col->b);
		col = col->next;
	}
}

int	ft_init_game_condition(t_cub3d *cub3d, t_file file)
{
	ft_init_player(cub3d, file.map.player, cub3d->map);
	if (gettimeofday(&cub3d->time, NULL) < 0)
		return (ft_error(EGETTIME));
	cub3d->prev_time = cub3d->time;
	ft_get_color(cub3d, file.col);
	return (1);
}
