/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:39:10 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 19:39:50 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_action_rotate(int key, t_cub3d *cub3d)
{
	if (key == XK_Left)
		ft_vector_rotation(cub3d, cub3d->rot_speed);
	else
		ft_vector_rotation(cub3d, -cub3d->rot_speed);
}

void	ft_rotate_actions(t_cub3d *cub3d, t_keys *keys)
{
	if (keys->left)
		ft_action_rotate(XK_Left, cub3d);
	if (keys->right)
		ft_action_rotate(XK_Right, cub3d);	
}