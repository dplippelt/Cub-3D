/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:48:51 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 18:14:42 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_change_door_status(t_cub3d *cub3d, t_door *door)
{
	if (door->status == CLOSE || door->status == CLOSING)
		door->status = OPENING;
	else if (door->status == OPEN || door->status == OPENING)
		door->status = CLOSING;
	cub3d->door_act = 0;
}

static void	ft_check_door(t_cub3d *cub3d)
{
	int	forward_row;
	int	forward_col;

	forward_row = cub3d->pos_row + cub3d->dir_row;
	forward_col = cub3d->pos_col + cub3d->dir_col;
	if (cub3d->map[forward_row][forward_col] == C_DOOR)
		ft_change_door_status(cub3d, &cub3d->doors[forward_row][forward_col]);
}

void	ft_door_action(t_cub3d *cub3d, t_keys *key)
{
	if (cub3d->door_act && key->space)
		ft_check_door(cub3d);
	if (!key->space)
		cub3d->door_act = 1;
}
