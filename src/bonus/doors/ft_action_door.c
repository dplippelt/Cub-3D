/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:48:51 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 20:01:54 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_change_door_status(t_door *door)
{
	if (door->status == CLOSE)
		door->status = OPENING;
	else if (door->status == CLOSING)
		door->status = OPENING;
	else if (door->status == OPENING)
		door->status = CLOSING;
	else if (door->status == OPEN)
		door->status = CLOSING;
	printf("door->status %d\n", door->status);
}

void	ft_action_door(t_cub3d *cub3d)
{
	int	forward_row;
	int	forward_col;

	forward_row = cub3d->pos_row + cub3d->dir_row;
	forward_col = cub3d->pos_col + cub3d->dir_col;
	if (cub3d->map[forward_row][forward_col] == 'D')
		ft_change_door_status(&cub3d->doors[forward_row][forward_col]);
}
