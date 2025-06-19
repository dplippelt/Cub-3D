/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:43 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 15:15:15 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>
# include <sys/types.h>

typedef struct s_coord
{
	size_t	x;
	size_t	y;
}			t_coord;

typedef struct s_walls
{
	char	**map;
	t_coord	start;
	t_coord	next;
	int		valid;
	size_t	height;
	size_t	width;
}			t_walls;

typedef struct s_tex
{
	char			*tex_path;
	int				id;
	struct s_tex	*next;
}					t_tex;

typedef struct s_col
{
	u_int8_t		r;
	u_int8_t		g;
	u_int8_t		b;
	int				id;
	struct s_col	*next;
}					t_col;

typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	width;
}			t_map;

typedef struct s_file
{
	const char	*file_path;
	char		**file;
	size_t		nlines;
	t_tex		*tex;
	t_col		*col;
	t_map		map;
}				t_file;

#endif
