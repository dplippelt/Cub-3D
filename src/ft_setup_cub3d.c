/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_cub3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:27:43 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 17:56:47 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_setup_cub3d(t_cub3d *cub3d, t_file file)
{
	if (!ft_init_mlx_setup_win(cub3d))
		return (0);
	if (!ft_init_minimap(cub3d))
		return (0);
	if (!ft_init_texture_imgs(cub3d, file.tex))
		return (0);
	if (!ft_init_field_of_view(cub3d))
		return (0);
	if (!ft_init_game_condition(cub3d, file))
		return (0);
	ft_update_field_of_view(cub3d);
	if (!ft_calc_frame_time(cub3d))
		return (0);
	ft_put_img_to_win(cub3d->fov.img, cub3d);
	ft_draw_minimap(&cub3d->mmap);
	ft_setup_hooks(cub3d->win, cub3d, &cub3d->mouse);
	return (1);
}
