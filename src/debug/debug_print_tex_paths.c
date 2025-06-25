/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_tex_paths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:30:14 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 16:07:42 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_tex_paths(t_tex *tex)
{
	printf("\n");
	while (tex)
	{
		if (tex->id == TEXNORTH)
			printf("North wall texture:\t");
		else if (tex->id == TEXEAST)
			printf("East wall texture:\t");
		else if (tex->id == TEXSOUTH)
			printf("South wall texture:\t");
		else if (tex->id == TEXWEST)
			printf("West wall texture:\t");
		printf("%s\n", tex->tex_path);
		tex = tex->next;
	}
}
