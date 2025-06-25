/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_texture_info.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:05:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 13:15:28 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_got_tex_info(t_tex *tex, int type)
{
	while (tex)
	{
		if (tex->id == type)
			return (1);
		tex = tex->next;
	}
	return (0);
}

static size_t	ft_num_textures(t_tex *tex)
{
	size_t	n;

	n = 0;
	while (tex)
	{
		n++;
		tex = tex->next;
	}
	return (n);
}

static int	ft_got_all_necessary_tex_info(t_tex *tex)
{
	if (!ft_got_tex_info(tex, TEXNORTH))
		return (ft_error(EMISSINGINFO));
	if (!ft_got_tex_info(tex, TEXEAST))
		return (ft_error(EMISSINGINFO));
	if (!ft_got_tex_info(tex, TEXSOUTH))
		return (ft_error(EMISSINGINFO));
	if (!ft_got_tex_info(tex, TEXWEST))
		return (ft_error(EMISSINGINFO));
	if (ft_num_textures(tex) > NTEX)
		return (ft_error(EDUPENTRIES));
	return (1);
}

static int	ft_texture_files_readable(t_tex *tex)
{
	int	fd;

	while (tex)
	{
		if (!ft_open(tex->tex_path, &fd))
			return (0);
		close(fd);
		tex = tex->next;
	}
	return (1);
}

int	ft_validate_texture_info(t_tex *tex)
{
	if (!ft_got_all_necessary_tex_info(tex))
		return (0);
	if (!ft_texture_files_readable(tex))
		return (0);
	return (1);
}
