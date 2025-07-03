/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcurrenttime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:27:00 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 18:42:20 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ft_getcurrenttime(void)
{
	struct timeval	time;
	long 			curr_time;

	curr_time = 0;
	if (gettimeofday(&time, NULL) < 0)
		return (-1);
	curr_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (curr_time);
}
