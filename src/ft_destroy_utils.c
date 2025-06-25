/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:46:46 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/25 16:13:54 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_destroy_texture_imgs(t_cub3d *cub3d)
{
	int	i;

	if (!cub3d->imgs)
		return ;
	i = 0;
	while (i < NUM_OF_IMGS)
	{
		if (cub3d->imgs[i].img)
			mlx_destroy_image(cub3d->mlx, cub3d->imgs[i].img);
		i++;
	}
	free(cub3d->imgs);
}

static void	ft_destroy_fov(t_cub3d *cub3d)
{
	if (cub3d->fov.img)
		mlx_destroy_image(cub3d->mlx, cub3d->fov.img);
}

static void	ft_destroy_win(t_cub3d *cub3d)
{
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
}

static void	ft_destroy_mlx(t_cub3d *cub3d)
{
	if (!cub3d->mlx)
		return ;
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
}

void	ft_destroy_all(t_cub3d *cub3d)
{
	ft_destroy_texture_imgs(cub3d);
	ft_destroy_fov(cub3d);
	ft_destroy_win(cub3d);
	ft_destroy_mlx(cub3d);
}
