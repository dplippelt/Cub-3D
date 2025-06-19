/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_cub3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:26:51 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/19 18:10:38 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_rgb_to_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

void	ft_init_field_of_view(t_cub3d *cub3d)
{
	cub3d->fov.x = cub3d->win_x;
	cub3d->fov.y = cub3d->win_y;
	cub3d->fov.img = mlx_new_image(cub3d->mlx, cub3d->win_x, cub3d->win_y);
	if (!cub3d->fov.img)
	{
		ft_destroy_texture_imgs(cub3d->mlx, cub3d->imgs);
		ft_destroy_mlx_win(cub3d);
		exit(EXIT_FAILURE);
	}
	ft_set_img_addr(&cub3d->fov);
}

void	ft_init_game_condition(t_cub3d *cub3d)
{
	// TODO: depends on the player position (N / S / W / E)
	cub3d->pos_row = 1.5;
	cub3d->pos_col = 2.5;
	// TODO: depends on the N / S / W / E character
	cub3d->dir_row = 1;
	cub3d->dir_col = 0;
	// plane dir always points to the positive direction
	cub3d->plane_row = 0;
	cub3d->plane_col = -0.66;
	if (gettimeofday(&cub3d->time, NULL) < 0)
	{
		ft_destroy_all(cub3d);
		exit(EXIT_FAILURE);
	}
	cub3d->prev_time = cub3d->time;
	cub3d->frame_time = 0;
	cub3d->move_speed = 0;
	cub3d->rot_speed = 0;
	// TODO: get from the map data
	cub3d->c_color = ft_rgb_to_color(0, 255, 255); // temporary
	cub3d->f_color = ft_rgb_to_color(0, 255, 255); // temporary
}

void	ft_start_cub3d(t_cub3d *cub3d)
{
	ft_init_texture_imgs(cub3d);
	ft_init_field_of_view(cub3d);
	ft_init_game_condition(cub3d);
	ft_update_field_of_view(cub3d);
	ft_calc_frame_time(cub3d);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	ft_setup_hook(cub3d->win, ft_key_action, cub3d);
}
