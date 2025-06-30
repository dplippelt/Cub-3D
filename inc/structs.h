/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:43 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 11:34:37 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_walls
{
	char	**map;
	t_pos	pos;
	int		valid;
	int		height;
	int		width;
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
	t_pos	player;
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


// Takato's structs

typedef struct s_imgs
{
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
	int		x;
	int		y;
}			t_imgs;

typedef struct s_ray
{
	double	dir_row;
	double	dir_col;
}			t_ray;

typedef struct s_dist
{
	double	side_row;
	double	side_col;
	double	delta_row;
	double	delta_col;
}			t_dist;

typedef struct s_dda
{
	double	wall_dist;
	int		step_row;
	int		step_col;
	int		map_row;
	int		map_col;
	double	hit;
	double	side;
}			t_dda;

typedef struct s_rcast
{
	t_ray	ray;
	t_dist	dist;
	t_dda	dda;
}			t_rcast;

typedef struct s_line
{
	int		hight;
	int		begin;
	int		end;
}			t_line;

typedef struct s_mmap
{
	void	*mlx;
	void	*win;
	int		screen_width;
	int		screen_height;
	int		width;
	int		height;
	t_imgs	*img;
	char	**map;
	char	*mmap;
}			t_mmap;

typedef struct	s_cub3d
{
	void			*mlx;
	void			*win;
	t_imgs			*imgs;
	t_imgs			fov;
	int				win_x;
	int				win_y;
	char			**map;
	double			pos_row;
	double			pos_col;
	double			dir_row;
	double			dir_col;
	double			plane_row;
	double			plane_col;
	struct timeval	time;
	struct timeval	prev_time;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	int				f_color;
	int				c_color;
	t_mmap			mmap;
}					t_cub3d;



#endif
