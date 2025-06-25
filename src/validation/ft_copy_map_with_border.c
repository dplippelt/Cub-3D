/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map_with_border.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:25:07 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 17:08:00 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static size_t	ft_get_nrows(char **src)
{
	size_t	nrows;

	nrows = 0;
	while (src[nrows])
		nrows++;
	return (nrows);
}

static int	ft_malloc_expanded_array(char ***dst, size_t old_rows, size_t wdth)
{
	size_t	new_rows;
	size_t	new_width;
	size_t	i;

	new_rows = old_rows + 2;
	new_width = wdth + 2;
	*dst = malloc(sizeof(char *) * (new_rows + 1));
	if (!*dst)
		return (ft_error(EMALLOC));
	i = 0;
	while (i < new_rows)
	{
		(*dst)[i] = malloc(new_width + 1);
		if (!(*dst)[i])
		{
			ft_cleanup_str_array(*dst);
			return (ft_error(EMALLOC));
		}
		i++;
	}
	(*dst)[i] = NULL;
	return (1);
}

static void	ft_fill_border_line(char *line, size_t width)
{
	size_t	i;

	i = 0;
	while (i < width + 2)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
}

static void	ft_copy_line_with_borders(char *dst, char *src, size_t width)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst[0] = ' ';
	i = 0;
	while (i < src_len && i < width)
	{
		dst[i + 1] = src[i];
		i++;
	}
	dst[width + 1] = ' ';
	dst[width + 2] = '\0';
}

int	ft_copy_map_with_border(char ***dst, char **src, size_t width)
{
	size_t	orig_rows;
	size_t	src_row;
	size_t	dst_row;

	orig_rows = ft_get_nrows(src);
	if (!ft_malloc_expanded_array(dst, orig_rows, width))
		return (0);
	ft_fill_border_line((*dst)[0], width);
	dst_row = 1;
	src_row = 0;
	while (src_row < orig_rows)
	{
		ft_copy_line_with_borders((*dst)[dst_row], src[src_row], width);
		dst_row++;
		src_row++;
	}
	ft_fill_border_line((*dst)[dst_row], width);
	return (1);
}
