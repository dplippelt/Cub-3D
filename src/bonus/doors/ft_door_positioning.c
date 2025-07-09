/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_positioning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:06:51 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 20:42:31 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	ft_door_action(t_door *door, t_cub3d *cub3d)
{
	if (door->status == OPENING)
	{
		door->open_ratio += cub3d->frame_time;
		if (door->open_ratio - 1 < EPSILON)
		{
			door->open_ratio = 1;
			door->status = OPEN;
		}
	}
	else if (door->status == CLOSING)
	{
		door->open_ratio -= cub3d->frame_time;
		if (door->open_ratio < EPSILON)
		{
			door->open_ratio = 0;
			door->status = CLOSE;
		}
	}
}

void	ft_door_status_check(t_cub3d *cub3d)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == 'D')
				ft_door_action(&cub3d->doors[i][j], cub3d);
			j++;
		}
		i++;
	}
};