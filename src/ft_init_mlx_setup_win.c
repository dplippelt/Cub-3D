/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_setup_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:15:13 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 13:33:08 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_win_dimesions(t_cub3d *cub)
{
	int	screen_x;
	int	screen_y;

	cub->win_x = WIN_X_DEFAULT;
	cub->win_y = WIN_Y_DEFAULT;
	mlx_get_screen_size(cub->mlx, &screen_x, &screen_y);
	if ((screen_y * 19 / 20) < WIN_Y_DEFAULT)
	{
		cub->win_y = screen_y * 19 / 20;
		cub->win_x = cub->win_y * 4 / 3;
	}
	else if (screen_x < WIN_X_DEFAULT)
	{
		cub->win_x = screen_x;
		cub->win_y = cub->win_x * 3 / 4;
	}
}

int	ft_init_mlx_setup_win(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ft_error(EMLXINIT));
	ft_set_win_dimesions(cub);
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, TITLE);
	if (!cub->win)
		return (ft_error(EMLXWIN));
	mlx_hook(cub->win, DestroyNotify, ClientMessage, mlx_loop_end, cub->mlx);
	return (1);
}
