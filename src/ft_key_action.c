/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:54:18 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 19:48:33 by tmitsuya         ###   ########.fr       */
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
	if (cub3d->map[next_pos_row][next_pos_col] == 'D')
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

void	ft_key_action(t_cub3d *cub3d, t_keys *keys)
{
	if (keys->esc)
	{
		mlx_loop_end(cub3d->mlx);
		return ;
	}
	if (keys->left)
		ft_action_rotate(XK_Left, cub3d);
	if (keys->right)
		ft_action_rotate(XK_Right, cub3d);
	if (keys->w)
		ft_action_move(XK_w, cub3d);
	if (keys->a)
		ft_action_move(XK_a, cub3d);
	if (keys->s)
		ft_action_move(XK_s, cub3d);
	if (keys->d)
		ft_action_move(XK_d, cub3d);
	if (keys->space)
		ft_action_door(cub3d);
}
