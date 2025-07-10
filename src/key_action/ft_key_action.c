/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:54:18 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 14:22:54 by dlippelt         ###   ########.fr       */
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

static int	ft_update_sens_settings(t_settings *di, int sens)
{
	di->show_info = 1;
	di->start_show = ft_getcurrenttime();
	if (!di->start_show)
		return (0);
	di->value = (double)sens;
	return (1);
}

static int	ft_update_fov_settings(t_settings *di, double fov)
{
	di->show_info = 1;
	di->start_show = ft_getcurrenttime();
	if (!di->start_show)
		return (0);
	di->value = fov;
	return (1);
}

static int	ft_handle_mouse_sens_adjustment(t_rot *rot, t_keys *keys)
{
	if (rot->can_adjust && keys->plus)
	{
		if (rot->sens - MOUSE_SENS_STEPS > MOUSE_SENS_MIN)
			rot->sens -= MOUSE_SENS_STEPS;
		else
			rot->sens = MOUSE_SENS_MIN;
	}
	if (rot->can_adjust && keys->minus)
	{
		if (rot->sens + MOUSE_SENS_STEPS < MOUSE_SENS_MAX)
			rot->sens += MOUSE_SENS_STEPS;
		else
			rot->sens = MOUSE_SENS_MAX;
	}
	if (rot->can_adjust && keys->zero)
		rot->sens = MOUSE_SENS;
	if (rot->can_adjust && (keys->plus || keys->minus || keys->zero))
	{
		rot->can_adjust = 0;
		if (!ft_update_sens_settings(&rot->set, rot->sens))
			return (0);
	}
	if (!keys->minus && !keys->plus && !keys->zero)
		rot->can_adjust = 1;
	return (1);
}

static int	ft_handle_fov_adjustment(t_cub3d *cub, t_fov *fov, t_keys *keys)
{
	if (fov->can_adjust && keys->mult)
	{
		if (fov->fov_factor + FOV_FACTOR_STEPS > FOV_FACTOR_MAX)
			fov->fov_factor = FOV_FACTOR_MAX;
		else
			fov->fov_factor += FOV_FACTOR_STEPS;
	}
	if (fov->can_adjust && keys->div)
	{
		if (fov->fov_factor - FOV_FACTOR_STEPS < FOV_FACTOR_MIN)
			fov->fov_factor = FOV_FACTOR_MIN;
		else
			fov->fov_factor -= FOV_FACTOR_STEPS;
	}
	if (fov->can_adjust && keys->equal)
		fov->fov_factor = FOV_FACTOR;
	if (fov->can_adjust && (keys->mult || keys->div || keys->equal))
	{
		fov->can_adjust = 0;
		if (!ft_update_fov_settings(&fov->set, fov->fov_factor))
			return (0);
	}
	cub->plane_row = fov->fov_factor * cub->dir_col;
	cub->plane_col = -fov->fov_factor * cub->dir_row;
	if (!keys->mult && !keys->div && !keys->equal)
		fov->can_adjust = 1;
	return (1);
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
	if (!ft_handle_mouse_sens_adjustment(&cub3d->mouse.rot, &cub3d->keys))
	{
		mlx_loop_end(cub3d->mlx);
		return ;
	}
	if (!ft_handle_fov_adjustment(cub3d, &cub3d->fov_data, keys))
	{
		mlx_loop_end(cub3d->mlx);
		return ;
	}
}
