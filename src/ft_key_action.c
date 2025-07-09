/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:54:18 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 15:47:43 by dlippelt         ###   ########.fr       */
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

static void	ft_handle_minimap_toggle(t_mmap *mmap, t_keys *keys)
{
	if (mmap->can_toggle && keys->m)
	{
		mmap->visible = !mmap->visible;
		mmap->can_toggle = 0;
	}
	if (!keys->m)
		mmap->can_toggle = 1;
}

static void	ft_handle_mouse_sens_adjustment(t_rot *rot, t_keys *keys)
{
	if (rot->can_adjust && keys->plus)
	{
		if (rot->sens - MOUSE_SENS_STEPS > MOUSE_SENS_MIN)
			rot->sens -= MOUSE_SENS_STEPS;
		else
			rot->sens = MOUSE_SENS_MIN;
		rot->can_adjust = 0;
	}
	if (rot->can_adjust && keys->minus)
	{
		if (rot->sens + MOUSE_SENS_STEPS < MOUSE_SENS_MAX)
			rot->sens += MOUSE_SENS_STEPS;
		else
			rot->sens = MOUSE_SENS_MAX;
		rot->can_adjust = 0;
	}
	if (rot->can_adjust && keys->zero)
	{
		rot->sens = MOUSE_SENS;
		rot->can_adjust = 0;
	}
	if (!keys->minus && !keys->plus && !keys->zero)
		rot->can_adjust = 1;
}

static void	ft_handle_fov_adjustment(t_cub3d *cub3d, t_keys *keys)
{
	if (cub3d->can_adjust_fov && keys->mult)
	{
		if (cub3d->fov_factor + 0.1 > 1.66)
			cub3d->fov_factor = 1.66;
		else
			cub3d->fov_factor += 0.1;
		cub3d->can_adjust_fov = 0;
	}
	if (cub3d->can_adjust_fov && keys->div)
	{
		if (cub3d->fov_factor - 0.1 < 0.36)
			cub3d->fov_factor = 0.36;
		else
			cub3d->fov_factor -= 0.1;
		cub3d->can_adjust_fov = 0;
	}
	if (cub3d->can_adjust_fov && keys->equal)
	{
		cub3d->fov_factor = FOV_FACTOR;
		cub3d->can_adjust_fov = 0;
	}
	cub3d->plane_row = cub3d->fov_factor * cub3d->dir_col;
	cub3d->plane_col = -cub3d->fov_factor * cub3d->dir_row;
	if (!keys->mult && !keys->div && !keys->equal)
		cub3d->can_adjust_fov = 1;
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
	ft_handle_minimap_toggle(&cub3d->mmap, &cub3d->keys);
	ft_handle_mouse_sens_adjustment(&cub3d->mouse.rot, &cub3d->keys);
	ft_handle_fov_adjustment(cub3d, keys);
}
