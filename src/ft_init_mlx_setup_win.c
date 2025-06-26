/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_setup_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:15:13 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/26 17:58:54 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_mlx_setup_win(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ft_error(EMLXINIT));
	mlx_get_screen_size(cub->mlx, &cub->win_x, &cub->win_y);
	cub->win_x /= 2;
	cub->win_y = cub->win_y * 3 / 4;
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, TITLE);
	if (!cub->win)
		return (ft_error(EMLXWIN));
	mlx_hook(cub->win, DestroyNotify, ClientMessage, mlx_loop_end, cub->mlx);
	return (1);
}
