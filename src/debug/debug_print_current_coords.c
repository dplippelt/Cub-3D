/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_current_coords.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:31:54 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 15:39:17 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_current_coords(t_walls *w)
{
	printf("\n");
	printf("start x: %zu\n", w->start.x);
	printf("start y: %zu\n", w->start.y);
	printf("curr x: %zu\n", w->next.x);
	printf("curr y: %zu\n", w->next.y);
	printf("\n");
	debug_print_str_array(w->map);
	printf("\n");
}
