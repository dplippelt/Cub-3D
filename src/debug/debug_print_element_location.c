/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_element_location.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:19:26 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 12:29:30 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_element_location(int element_id, size_t x, size_t y)
{
	if (element_id == TEXNORTH)
		printf("\"NO\" found at ");
	else if (element_id == TEXEAST)
		printf("\"EA\" found at ");
	else if (element_id == TEXSOUTH)
		printf("\"SO\" found at ");
	else if (element_id == TEXWEST)
		printf("\"WE\" found at ");
	else if (element_id == COLFLOOR)
		printf("\"F\" found at ");
	else if (element_id == COLCEILING)
		printf("\"C\" found at ");
	printf("(%zu, %zu)\n", x, y);
}
