/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:42:05 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 14:45:04 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_is_valid_map_char(char c)
{
	if (c == ' ')
		return (1);
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'W')
		return (1);
	if (c == 'C')
		return (1);
	if (c == 'D')
		return (1);
	return (0);
}

int	ft_only_trailing_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

size_t	ft_get_line_length(char *line)
{
	size_t	line_len;

	line_len = 0;
	while (*line && ft_is_valid_map_char(*line))
	{
		if (*line == ' ' && ft_only_trailing_spaces(line))
			return (line_len);
		line++;
		line_len++;
	}
	return (line_len);
}

int	ft_malloc_map(t_map *map)
{
	size_t	line;

	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (ft_error(EMALLOC));
	line = 0;
	while (line < map->height)
	{
		map->map[line] = malloc(map->width + 1);
		if (!map->map[line])
		{
			ft_cleanup_str_array(map->map);
			return (ft_error(EMALLOC));
		}
		line++;
	}
	map->map[map->height] = NULL;
	return (1);
}
