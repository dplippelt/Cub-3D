/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:51:31 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 19:50:15 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_setup_hooks(void *win, t_cub3d *cub, t_mouse *mouse, t_keys *keys)
{
	ft_init_mouse(cub);
	mlx_hook(cub->win, DestroyNotify, ClientMessage, mlx_loop_end, cub->mlx);
	mlx_hook(win, KeyPress, KeyPressMask, ft_key_press, keys);
	mlx_hook(win, KeyRelease, KeyReleaseMask, ft_key_release, keys);
	mlx_hook(win, MotionNotify, PointerMotionMask, ft_mouse_move, mouse);
	mlx_hook(win, FocusOut, FocusChangeMask, ft_focus_out, mouse);
	mlx_hook(win, FocusIn, FocusChangeMask, ft_focus_in, mouse);
	mlx_loop_hook(cub->mlx, ft_rendering_loop, cub);
}
