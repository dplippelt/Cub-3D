/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time_diff_usec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:58:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/11 10:00:49 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ft_get_time_diff_usec(struct timeval curr, struct timeval prev)
{
	long long	usec_now;
	long long	usec_from;

	usec_now = curr.tv_sec * 1e6 + curr.tv_usec;
	usec_from = prev.tv_sec * 1e6 + prev.tv_usec;
	return (usec_now - usec_from);
}
