/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_field_of_view.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:02:43 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 14:06:30 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_get_texture_x(t_cub3d *cub3d, t_dda dda, t_ray ray, int tex_size)
{
	double	wall_x;
	int		texture_x;

	if (dda.side == ROW_SIDE)
		wall_x = cub3d->pos_col + dda.wall_dist * ray.dir_col;
	else
		wall_x = cub3d->pos_row + dda.wall_dist * ray.dir_row;
	wall_x -= (int)wall_x;
	texture_x = (int)(wall_x * tex_size);
	if (dda.side == ROW_SIDE && ray.dir_row > 0)
		texture_x = tex_size - texture_x - 1;
	else if (dda.side == COL_SIDE && ray.dir_col < 0)
		texture_x = tex_size - texture_x - 1;
	return (texture_x);
}

void	ft_update_field_of_view(t_cub3d *cub3d)
{
	int		win_x;
	t_rcast	rc;
	t_imgs	target;
	int		tex_x;

	win_x = 0;
	while (win_x < cub3d->win_x)
	{
		ft_ray_casting(&rc, cub3d, win_x);
		target = ft_get_target_img(cub3d, rc.dda, rc.ray);
		tex_x = ft_get_texture_x(cub3d, rc.dda, rc.ray, target.x);
		ft_draw_vertic_line(cub3d, target, win_x, tex_x);
		win_x++;
	}
	ft_sprite_casting(cub3d, cub3d->sprite);
}
