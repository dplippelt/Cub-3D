/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:42:29 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 15:27:44 by dlippelt         ###   ########.fr       */
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

static int	ft_validate_file_content(const char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error(ERRNO));
	close(fd);
	return (1);
}

int	ft_validate_map(const char *map_path)
{
	if (!ft_validate_file_format(map_path))
		return (0);
	if (!ft_validate_file_content(map_path))
		return (0);
	return (1);
}
