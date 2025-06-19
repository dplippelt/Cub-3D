/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:46:46 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/19 18:10:24 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_destroy_mlx_win(t_cub3d *cub3d)
{
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
}

void	ft_destroy_texture_imgs(t_xvar *mlx, t_imgs *imgs)
{
	int	i;

	i = 0;
	while (i < NUM_OF_IMGS)
	{
		if (imgs[i].img)
			mlx_destroy_image(mlx, imgs[i].img);
		i++;
	}
	free(imgs);
}

void	ft_destroy_all(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx, cub3d->fov.img);
	ft_destroy_texture_imgs(cub3d->mlx, cub3d->imgs);
	ft_destroy_mlx_win(cub3d);
}
