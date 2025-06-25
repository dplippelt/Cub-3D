/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:09:31 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 12:34:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_map(t_map *map)
{
	size_t	y;

	printf("\nMap height: %zu\t\t\tMap width: %zu\n", map->height, map->width);
	printf("===================== MAP =====================\n");
	y = 0;
	while (y < map->height)
	{
		printf("%s\n", map->map[y]);
		y++;
	}
	printf("===============================================\n");
}
