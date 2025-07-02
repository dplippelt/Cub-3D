/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_cub3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:27:43 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 18:18:46 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_setup_cub3d(t_cub3d *cub3d, t_file file)
{
	if (!ft_init_mlx_setup_win(cub3d))
		return (0);
	if (!ft_init_texture_imgs(cub3d, file.tex))
		return (0);
	if (!ft_init_field_of_view(cub3d))
		return (0);
	if (!ft_init_game_condition(cub3d, file))
		return (0);
	if (!ft_init_sprite(cub3d))
		return (0);
	ft_update_field_of_view(cub3d);
	if (!ft_calc_frame_time(cub3d))
		return (0);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	ft_setup_key_hook(cub3d->win, ft_key_action, cub3d);
	// ft_setup_mouse_hook(cub3d->win, MotionNotify, PointerMotionMask, ft_mouse, cub3d);
	ft_setup_loop_hook(cub3d->mlx, ft_sprite_animation, cub3d);
	return (1);
}
