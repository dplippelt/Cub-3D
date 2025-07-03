/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:06:40 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 14:48:05 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_rotation.h"

static void	ft_recenter_mouse(int x, int y, t_mouse *mouse)
{
	int	do_center;

	do_center = 0;
	if (x >= mouse->max_x || x <= mouse->min_x)
		do_center = 1;
	else if (y >= mouse->max_y || y <= mouse->min_y)
		do_center = 1;
	if (do_center)
	{
		mouse->skip = 1;
		mlx_mouse_move(mouse->mlx, mouse->win, mouse->center_x, mouse->center_y);
	}
}

int	ft_mouse_move(int x, int y, void *param)
{
	t_mouse	*mouse;
	int		diff;

	mouse = (t_mouse *)param;
	if (mouse->skip)
	{
		mouse->x_prev = x;
		mouse->skip = 0;
		return (1);
	}
	diff = 0;
	if (x > mouse->x_prev)
	{
		diff = x - mouse->x_prev;
		printf("diff: %d\n", diff);
	}
	else if (x < mouse->x_prev)
	{
		diff = (mouse->x_prev - x) * -1;
		printf("diff: %d\n", diff);
	}
	ft_recenter_mouse(x, y, mouse);
	mouse->x_prev = x;
	return (1);
}
