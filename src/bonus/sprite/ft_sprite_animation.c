/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:27:20 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 18:51:08 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_change_sprite_id(t_sprite *sprite)
{
	if (sprite->id == SPRITE_0)
		sprite->id = SPRITE_1;
	else if (sprite->id == SPRITE_1)
		sprite->id = SPRITE_2;
	else if (sprite->id == SPRITE_2)
		sprite->id = SPRITE_3;
	else
		sprite->id = SPRITE_0;
}

// static int	ft_is_image_change(t_cub3d *cub3d, int sec)
// {
// 	size_t	i;

// 	if (sec < ANIMATION_SPEED_MILISEC)
// 		return (0);
// 	i = 0;
// 	while (i < cub3d->num_sprite)
// 		ft_change_sprite_id(&cub3d->sprite[i++]);
// 	return (1);
// }

static void	ft_animate_sprites(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	while (i < cub3d->num_sprite)
		ft_change_sprite_id(&cub3d->sprite[i++]);
}

int	ft_sprite_animation(t_cub3d *cub3d)
{

	if (ft_get_time_diff_sec(cub3d->time, cub3d->prev_anim_timevl) * 1000 > ANIMATION_SPEED_MILISEC)
	{
		ft_animate_sprites(cub3d);
		cub3d->prev_anim_timevl = cub3d->time;
	}
	return (1);
}

// int	ft_is_image_change(t_cub3d *cub3d, size_t count)
// {
// 	size_t	i;

// 	if (count % ANIMATION_SPEED)
// 		return (0);
// 	i = 0;
// 	while (i < cub3d->num_sprite)
// 		ft_change_sprite_id(&cub3d->sprite[i++]);
// 	return (1);
// }

// int	ft_sprite_animation(t_cub3d *cub3d)
// {
// 	static size_t	count;

// 	count++;
// 	if (!ft_is_image_change(cub3d, count))
// 		return (0);
// 	ft_update_field_of_view(cub3d);
// 	ft_put_img_to_win(cub3d->fov.img, cub3d);
// 	return (1);
// }
