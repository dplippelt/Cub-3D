/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:25:30 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/30 13:16:38 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse(int move_x, t_cub3d *cub3d)
{
	static int	start_x;
	// double		rot_unit;
	// double		rot;

	printf("mouse x:%d\n", move_x);
	// if (!start_x)
	if (move_x != start_x)
	{
		// rot_unit = (double)66 / (double)360 * 2 * M_PI / (double)cub3d->win_x;
		// rot = ((double)move_x - (double)start_x) * rot_unit;
		printf("radian: %d\n", move_x);
		// ft_vector_rotation(cub3d, rot);
	}
	start_x = move_x;
	(void)cub3d;
	return (move_x);
}