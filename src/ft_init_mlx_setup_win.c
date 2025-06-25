/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_setup_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:15:13 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/25 16:11:54 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_mlx_setup_win(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (0);
	mlx_get_screen_size(cub->mlx, &cub->win_x, &cub->win_y);
	cub->win_x /= 2;
	cub->win_y = cub->win_y * 3 / 4;
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, TITLE);
	if (!cub->win)
		return (0);
	mlx_hook(cub->win, DestroyNotify, ClientMessage, mlx_loop_end, cub->mlx);
	return (1);
}
