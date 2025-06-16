/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:59:29 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 14:10:44 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_putstr(char *s, int fd)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (write(fd, s, slen) == -1)
		return (0);
	return (1);
}
