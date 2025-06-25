/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_rbg_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:49:30 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 16:08:05 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_rbg_values(t_col *col)
{
	printf("\n");
	while (col)
	{
		if (col->id == COLFLOOR)
			printf("Floor RGB:\t\t");
		else if (col->id == COLCEILING)
			printf("Ceiling RGB:\t\t");
		printf("%u,%u,%u\n", col->r, col->g, col->b);
		col = col->next;
	}
}
