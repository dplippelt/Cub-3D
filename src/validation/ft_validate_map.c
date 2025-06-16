/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:42:29 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 17:11:56 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_validate_file_format(const char *map_path)
{
	size_t	slen;

	slen = ft_strlen(map_path);
	if (slen < 4)
		return (ft_error(EFILEFORMAT));
	slen -= 4;
	if (ft_strcmp(&map_path[slen], FORMAT))
		return (ft_error(EFILEFORMAT));
	return (1);
}

static int	ft_validate_file(t_map *m)
{
	int	fd;

	if (!ft_open(m->map_path, &fd))
		return (0);
	if (!ft_validate_file_content(fd, m))
		return (0);
	return (1);
}

int	ft_validate_map(t_map *m)
{
	if (!ft_validate_file_format(m->map_path))
		return (0);
	if (!ft_validate_file(m))
		return (0);
	return (1);
}
