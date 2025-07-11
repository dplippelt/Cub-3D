/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:46:44 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 10:50:55 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_usleep(long dur, long st)
{
	long	ct;
	long	dt;

	ct = ft_getcurrenttime() * 1000;
	if (ct == -1)
		return (0);
	if (st == -1)
		st = ct;
	dt = ct - st;
	while (dt < dur)
	{
		if (dur - dt > 200)
			usleep(((dur - dt) / 2));
		else
			usleep((dur - dt));
		ct = ft_getcurrenttime() * 1000;
		if (ct == -1)
			return (0);
		dt = ct - st;
	}
	return (1);
}
