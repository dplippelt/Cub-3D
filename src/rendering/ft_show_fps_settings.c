/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_fps_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:37:01 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 12:37:12 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	ft_build_fps_str(char *s, double value, size_t size)
{
	char	*sval;

	sval = ft_itoa((int)value);
	if (!sval)
		return (0);
	ft_strlcpy(s, "FPS: ", size);
	ft_strlcpy(s + 5, sval, size - 5);
	return (free(sval), 1);
}

int	ft_show_fps_settings(t_settings *set, void *mlx, void *win)
{
	long	ct;
	char	s[30];

	ct = 0;
	if (set->show_info)
	{
		ct = ft_getcurrenttime();
		if (!ct)
			return (0);
		if (ct - set->start_show < 2000)
		{
			ft_build_fps_str(s, set->value, 30);
			mlx_string_put(mlx, win, set->set_x, set->set_y, 0xFFFFFF00, s);
		}
		else
		{
			set->start_show = 0;
			set->show_info = 0;
		}
	}
	return (1);
}
