/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:11:41 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 12:42:24 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static int	ft_build_sens_str(char *s, double value, size_t size)
{
	size_t	sl;
	char	*sval;

	sval = ft_itoa(21 - (int)value / 100);
	if (!sval)
		return (0);
	sl = ft_strlen(sval);
	ft_strlcpy(s, "Mouse sens: ", size);
	s += 12;
	size -= 12;
	if (sl == 1)
	{
		s[0] = ' ';
		s++;
		size--;
	}
	ft_strlcpy(s, sval, size);
	free(sval);
	s += sl;
	size -= sl;
	ft_strlcpy(s, " / 20", size);
	return (1);
}

static int	ft_build_fov_str(char *s, double value, size_t size)
{
	char	*pre_dec;
	char	*post_dec;

	pre_dec = NULL;
	post_dec = NULL;
	pre_dec = ft_itoa((int)value);
	post_dec = ft_itoa(((int)(value * 100) % 100));
	if (!pre_dec || !post_dec)
		return (free(pre_dec), free(post_dec), 0);
	ft_strlcpy(s, "Fov factor: ", size);
	s += 12;
	size -= 12;
	ft_strlcpy(s, pre_dec, size);
	s += ft_strlen(pre_dec);
	size -= ft_strlen(pre_dec);
	s++[0] = '.';
	size--;
	ft_strlcpy(s, post_dec, size);
	return (free(pre_dec), free(post_dec), 1);
}

int	ft_show_sens_settings(t_settings *set, void *mlx, void *win)
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
			if (!ft_build_sens_str(s, set->value, 30))
				return (0);
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

int	ft_show_fov_settings(t_settings *set, void *mlx, void *win)
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
			ft_build_fov_str(s, set->value, 30);
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
