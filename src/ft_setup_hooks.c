/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:51:31 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 16:47:36 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_setup_hooks(void *win, t_cub3d *cub3d, t_mouse *mouse)
{
	ft_init_mouse(cub3d);
	mlx_hook(win, KeyPress, KeyPressMask, ft_key_action, cub3d);
	mlx_hook(win, MotionNotify, PointerMotionMask, ft_mouse_move, mouse);
	mlx_hook(win, FocusOut, FocusChangeMask, ft_focus_out, mouse);
	mlx_hook(win, FocusIn, FocusChangeMask, ft_focus_in, mouse);
	mlx_loop_hook(cub3d->mlx, ft_rendering_loop, cub3d);
}
