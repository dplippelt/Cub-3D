/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:54:18 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/26 19:05:36 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_valid_move(t_cub3d *cub3d, double add_row, double add_col)
{
	int	next_pos_row;
	int	next_pos_col;

	next_pos_row = cub3d->pos_row + add_row;
	next_pos_col = cub3d->pos_col + add_col;
	if (cub3d->map[next_pos_row][next_pos_col] == '1')
		return ;
	cub3d->pos_row += add_row;
	cub3d->pos_col += add_col;
}

void	ft_action_move(int key, t_cub3d *cub3d)
{
	if (key == XK_w)
	{
		ft_valid_move(cub3d, cub3d->dir_row * cub3d->move_speed, 0);
		ft_valid_move(cub3d, 0, cub3d->dir_col * cub3d->move_speed);
	}
	else if (key == XK_s)
	{
		ft_valid_move(cub3d, -cub3d->dir_row * cub3d->move_speed, 0);
		ft_valid_move(cub3d, 0, -cub3d->dir_col * cub3d->move_speed);
	}
	else if (key == XK_d)
	{
		ft_valid_move(cub3d, cub3d->plane_row * cub3d->move_speed, 0);
		ft_valid_move(cub3d, 0, cub3d->plane_col * cub3d->move_speed);
	}
	else
	{
		ft_valid_move(cub3d, -cub3d->plane_row * cub3d->move_speed, 0);
		ft_valid_move(cub3d, 0, -cub3d->plane_col * cub3d->move_speed);
	}
}

void	ft_action_rotate(int key, t_cub3d *cub3d)
{
	if (key == XK_Left)
		ft_vector_rotation(cub3d, cub3d->rot_speed);
	else
		ft_vector_rotation(cub3d, -cub3d->rot_speed);
}

int	ft_key_action(int key, t_cub3d *cub3d)
{
	if (key == XK_Escape)
		return (mlx_loop_end(cub3d->mlx), 0);
	if (key == XK_Left || key == XK_Right)
		ft_action_rotate(key, cub3d);
	else if (key == XK_d || key == XK_w || key == XK_a || key == XK_s)
		ft_action_move(key, cub3d);
	else
		return (key);
	ft_update_field_of_view(cub3d);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	return (key);
}
