u/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:29:34 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 18:12:30 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "debug.h"

static int	ft_is_element(char *s, int *el_id)
{
	if (!ft_strncmp(s, "NO ", 3))
		*el_id = TEXNORTH;
	else if (!ft_strncmp(s, "EA ", 3))
		*el_id = TEXEAST;
	else if (!ft_strncmp(s, "SO ", 3))
		*el_id = TEXSOUTH;
	else if (!ft_strncmp(s, "WE ", 3))
		*el_id = TEXWEST;
	else if (!ft_strncmp(s, "F ", 2))
		*el_id = COLFLOOR;
	else if (!ft_strncmp(s, "C ", 2))
		*el_id = COLCEILING;
	else
		*el_id = NOELEMENT;
	return (*el_id);
}

static size_t	ft_move_past_element(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_is_printable(s[i]))
		i++;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && ft_is_printable(s[i]))
		i++;
	return (i);
}

static int	ft_check_for_invalid_symbol(char *s, int *el_id)
{
	if (*s && !ft_is_element(s, el_id))
		return (ft_error(EUNEXPECTED));
	return (1);
}

static int	ft_get_elements(t_file *f)
{
	size_t	y;
	size_t	x;
	int		el_id;

	y = 0;
	while (f->file[y])
	{
		x = 0;
		while (f->file[y][x])
		{
			if (ft_is_element(&f->file[y][x], &el_id))
			{
				if (!ft_get_element_info(f, &f->file[y][x], el_id))
					return (0);
				x += ft_move_past_element(&f->file[y][x]);
			}
   while(f->file[y][x] == ' ')
			   x++;
   if (!ft_check_for_invalid_symbol(&f->file[y][x], &el_id))
			   return (0);
		}
		y++;
	}
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

int	ft_validate_elements(t_file *f)
{
	if (!ft_get_elements(f))
		return (0);
	#ifdef DEBUG
		debug_print_map(f);
		debug_print_tex_paths(f->tex);
		debug_print_rbg_values(f->col);
	#endif
	if (!ft_texture_files_readable(f->tex))
		return (0);
	return (1);
}
