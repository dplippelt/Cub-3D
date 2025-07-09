/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:54:18 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 19:44:59 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	if (!keys->minus && !keys->plus)
		rot->can_adjust = 1;
}

void	ft_key_action(t_cub3d *cub3d, t_keys *keys)
{
	if (keys->esc)
	{
		mlx_loop_end(cub3d->mlx);
		return ;
	}
	ft_move_actions(cub3d, keys);
	ft_rotate_actions(cub3d, keys);
	ft_door_action(cub3d, keys);
	ft_handle_minimap_toggle(&cub3d->mmap, &cub3d->keys);
	ft_handle_mouse_sens_adjustment(&cub3d->mouse.rot, &cub3d->keys);
}
