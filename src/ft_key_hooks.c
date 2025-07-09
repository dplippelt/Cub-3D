/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:45 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/09 13:48:05 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_press(int key, void *param)
{
	t_keys	*keys;

	keys = (t_keys *)param;
	if (key == XK_Escape)
		keys->esc = 1;
	else if (key == XK_Left)
		keys->left = 1;
	else if (key == XK_Right)
		keys->right = 1;
	else if (key == XK_w)
		keys->w = 1;
	else if (key == XK_a)
		keys->a = 1;
	else if (key == XK_s)
		keys->s = 1;
	else if (key == XK_d)
		keys->d = 1;
	else if (key == XK_space)
		keys->space = 1;
	if (key == XK_m)
		keys->m = 1;
	if (key == XK_KP_Subtract)
		keys->minus = 1;
	if (key == XK_KP_Add)
		keys->plus = 1;
	return (1);
}

int	ft_key_release(int key, void *param)
{
	t_keys	*keys;

	keys = (t_keys *)param;
	if (key == XK_Escape)
		keys->esc = 0;
	else if (key == XK_Left)
		keys->left = 0;
	else if (key == XK_Right)
		keys->right = 0;
	else if (key == XK_w)
		keys->w = 0;
	else if (key == XK_a)
		keys->a = 0;
	else if (key == XK_s)
		keys->s = 0;
	else if (key == XK_d)
		keys->d = 0;
	else if (key == XK_space)
		keys->space = 0;
	if (key == XK_m)
		keys->m = 0;
	if (key == XK_KP_Subtract)
		keys->minus = 0;
	if (key == XK_KP_Add)
		keys->plus = 0;
	return (1);
}
