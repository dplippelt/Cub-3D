/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:50:26 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 15:27:55 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_get_nrows(char **src)
{
	size_t	nrows;

	nrows = 0;
	while (*src)
	{
		nrows++;
		src++;
	}
	return (nrows);
}

int	ft_copy_str_array(char ***dst, char **src)
{
	size_t	nrows;
	size_t	row;
	size_t	row_len;

	nrows = ft_get_nrows(src);
	*dst = malloc(sizeof(char *) * (nrows + 1));
	if (!*dst)
		return (ft_error(EMALLOC));
	row_len = 0;
	row = 0;
	while (src[row])
	{
		row_len = ft_strlen(src[row]);
		(*dst)[row] = malloc(row_len + 1);
		if (!(*dst)[row])
		{
			ft_cleanup_str_array(*dst);
			return (ft_error(EMALLOC));
		}
		ft_strlcpy((*dst)[row], src[row], row_len + 1);
		row++;
	}
	(*dst)[row] = NULL;
	return (1);
}
