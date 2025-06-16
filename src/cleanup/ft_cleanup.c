/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:24 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 17:34:53 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	ft_cleanup_map(t_map *m)
{
	size_t	line;

	if (!m->map)
		return ;
	line = 0;
	while (m->map[line])
	{
		free(m->map[line]);
		line++;
	}
	free(m->map);
}
