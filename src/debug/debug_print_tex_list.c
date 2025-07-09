/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_tex_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:18:35 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/08 11:19:58 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_tex_list(t_tex *tex)
{
	while (tex)
	{
		printf("texture path: %s\n", tex->tex_path);
		tex = tex->next;
	}
}
