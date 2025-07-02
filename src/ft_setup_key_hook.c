/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:51:31 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 18:18:16 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_setup_key_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[KeyPress].hook = funct;
	win->hooks[KeyPress].param = param;
	win->hooks[KeyPress].mask = KeyPressMask;
}
