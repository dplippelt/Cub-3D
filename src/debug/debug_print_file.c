/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:40:52 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/25 16:53:01 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_file(t_file *f)
{
	size_t	line;

	line = 0;
	printf("\n======================= FILE CONTENT =======================\n");
	while (line < f->nlines)
	{
		if (f->file[line])
			printf("%s\n", f->file[line]);
		else
			printf("NULL\n");
		line++;
	}
	printf("============================================================\n\n");
}
