/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colortoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:20:23 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 16:14:38 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

u_int8_t	ft_colortoi(char **s, int *overflow)
{
	u_int8_t	num;
	u_int8_t	num_new;

	num = 0;
	while (**s >= '0' && **s <= '9')
	{
		num_new = num * 10 + (**s - '0');
		if (num_new < num)
		{
			*overflow = 1;
			return (*overflow);
		}
		num = num_new;
		(*s)++;
	}
	return (num);
}
