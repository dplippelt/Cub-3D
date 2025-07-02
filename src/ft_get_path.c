/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:55:58 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/02 13:56:14 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_field_to_texid(int i)
{
	if (i == NO)
		return (TEXNORTH);
	else if (i == SO)
		return (TEXSOUTH);
	else if (i == WE)
		return (TEXEAST);
	else if (i == EA)
		return (TEXEAST);
	else
		return (NOELEMENT);
}

static char	*ft_field_to_sprite(int i)
{
	if (i == SPRITE_0)
		return (P_SPRITE_0);
	else if (i == SPRITE_1)
		return (P_SPRITE_1);
	else if (i == SPRITE_2)
		return (P_SPRITE_2);
	else if (i == SPRITE_3)
		return (P_SPRITE_3);
	else
		return (NULL);
}

char	*ft_get_path(int i, t_tex *tex)
{
	int	tex_id;

	tex_id = ft_field_to_texid(i);
	if (tex_id == NOELEMENT)
		return (ft_field_to_sprite(i));
	while (tex)
	{
		if (tex->id == tex_id)
			return (tex->tex_path);
		tex = tex->next;
	}
	return (NULL);
}
