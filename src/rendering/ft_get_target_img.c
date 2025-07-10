/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_target_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:05:09 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/10 15:40:15 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	ft_get_target_img(t_dda *dda, t_ray ray)
{
	if (dda->side == ROW_SIDE)
	{
		if (dda->hit_type == C_WALL)
		{
			if (ray.dir_row > 0)
				dda->img = EA;
			else
				dda->img = WE;
		}
		else if (dda->hit_type == C_DOOR)
			dda->img = DOOR;
	}
	else
	{
		if (dda->hit_type == C_WALL)
		{
			if (ray.dir_col > 0)
				dda->img = SO;
			else
				dda->img = NO;
		}
		else if (dda->hit_type == C_DOOR)
			dda->img = DOOR;
	}
}
