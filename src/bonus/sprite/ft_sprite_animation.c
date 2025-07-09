/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:27:20 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 19:32:43 by tmitsuya         ###   ########.fr       */
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

static int	ft_is_image_change(t_cub3d *cub3d, int sec)
{
	size_t	i;

	if (sec < ANIMATION_SPEED_MILISEC)
		return (0);
	i = 0;
	while (i < cub3d->num_sprite)
		ft_change_sprite_id(&cub3d->sprite[i++]);
	return (1);
}

int	ft_sprite_animation(t_cub3d *cub3d)
{
	int	sec;

	sec = ft_get_time_diff_sec(cub3d->time, cub3d->anim_time) * 1000;
	if (ft_is_image_change(cub3d, sec))
		cub3d->anim_time = cub3d->time;
	return (1);
}
