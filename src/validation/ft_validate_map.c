/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:42:29 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 15:08:54 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "enums.h"
#include "macros.h"

int	ft_validate_file_format(char *map_path)
{
	size_t	slen;

	slen = ft_strlen(map_path);
	if (slen < 4)
		return (0);
	slen -= 4;
	if (ft_strcmp(&map_path[slen], FORMAT))
		return (0);
	return (1);
}

int	ft_validate_map(char *map_path)
{
	if (!ft_validate_file_format(map_path))
		return (ft_error(EFILEFORMAT));

	return (1);
}
