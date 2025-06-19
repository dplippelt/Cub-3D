/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:35:41 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 10:39:32 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	ft_found_map(char *line)
{
	int	is_map;

	is_map = 0;
	while (*line)
	{
		if (*line != ' ' && *line != '1')
			return (0);
		if (*line == '1')
			is_map = 1;
		line++;
	}
	return (is_map);
}
