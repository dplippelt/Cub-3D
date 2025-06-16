/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:53:28 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 14:14:40 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enums.h"
#include "utils.h"

int	ft_error(int e)
{
	ft_putstr("Error\n", 2);
	if (e == ERRNO)
		ft_putstr(strerror(errno), 2);
	if (e == ENUMPARAM)
		ft_putstr("Incorrect number of parameters.\n", 2);
	return (0);
}
