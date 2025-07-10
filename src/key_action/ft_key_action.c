/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:54:18 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 16:40:04 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_action.h"
#include "bonus.h"

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
