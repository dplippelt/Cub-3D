/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_map_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:41:18 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 10:44:45 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_map_line(char *s, size_t y)
{
	printf("\n");
	printf("Found start of map on line %zu\n", y);
	printf("First line of the map: %s\n", s);
}
