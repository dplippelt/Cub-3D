/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_color_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:20:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 13:24:41 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_got_color_info(t_col *col, int type)
{
	while (col)
	{
		if (col->id == type)
			return (1);
		col = col->next;
	}
	return (0);
}

static size_t	ft_num_colors(t_col *col)
{
	size_t	n;

	n = 0;
	while (col)
	{
		n++;
		col = col->next;
	}
	return (n);
}

static int	ft_got_all_necessary_color_info(t_col *col)
{
	if (!ft_got_color_info(col, COLFLOOR))
		return (ft_error(EMISSINGINFO));
	if (!ft_got_color_info(col, COLCEILING))
		return (ft_error(EMISSINGINFO));
	if (ft_num_colors(col) > NCOL)
		return (ft_error(EDUPENTRIES));
	return (1);
}

int	ft_validate_color_info(t_col *col)
{
	if (!ft_got_all_necessary_color_info(col))
		return (0);
	return (1);
}
