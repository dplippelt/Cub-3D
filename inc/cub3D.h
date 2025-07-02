/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:50:47 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/02 18:20:28 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D_H
# define cub3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>
# include "mlx.h"
# include "mlx_int.h"
# include "enums.h"
# include "macros.h"
# include "init.h"
# include "utils.h"
# include "validation.h"
# include "cleanup.h"
# define TITLE "cub3D"
// # define NUM_OF_IMGS 4
# define P_SPRITE_0 "textures/sprite_x256_0.xpm"
# define P_SPRITE_1 "textures/sprite_x256_1.xpm"
# define P_SPRITE_2 "textures/sprite_x256_2.xpm"
# define P_SPRITE_3 "textures/sprite_x256_3.xpm"
// # define M_PI 3.14159265358979323846
// # define TEXTURE_SIZE 128
# define DIST_PER_SECOND 5.0
# define RADIAN_PER_SECOND 2.0
# define SP_SIZE_DOWN 2
# define EPSILON 1e-6
# define ANIMATION_SPEED_MILISEC 500

enum e_img_field
{
	NO,
	SO,
	WE,
	EA,
	SPRITE_0,
	SPRITE_1,
	SPRITE_2,
	SPRITE_3,
	MAX_IMAGE,
};

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

typedef struct s_draw
{
	int		len_win;
	int		len_tex;
	int		begin;
	int		end;
}			t_draw;

typedef struct s_sprite
{
	int		id;
	int		map_row;
	int		map_col;
	double	pos_row;
	double	pos_col;
	double	x_on_camera;
	double	y_on_camera;
	int		x_on_win;
	int		y_on_win;
	int		hight;
	int		width;
	double	dist;
}			t_sprite;

enum e_side
{
	ROW_SIDE,
	COL_SIDE,
};

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
	size_t			num_sprite;
	t_sprite		*sprite;
	double			*wall_dists;
}					t_cub3d;

void	ft_init_cub3d(t_cub3d *cub3d, t_map *map);
int		ft_setup_cub3d(t_cub3d *cub3d, t_file file);
void	ft_start_cub3d(t_cub3d *cub3d);
int		ft_init_mlx_setup_win(t_cub3d *cub3d);
int		ft_init_texture_imgs(t_cub3d *cub3d, t_tex *tex);
int		ft_init_field_of_view(t_cub3d *cub3d);
int		ft_init_game_condition(t_cub3d *cub3d, t_file file);
char	*ft_get_path(int i, t_tex *tex);
void	ft_update_field_of_view(t_cub3d *cub3d);
int		ft_calc_frame_time(t_cub3d *cub3d);
void	ft_setup_key_hook(t_win_list *win, int (*funct)(), void *param);
void	ft_setup_loop_hook(void *mlx, int (*funct)(), void *param);
int		ft_key_action(int keycode, t_cub3d *cub3d);
int		ft_mouse(int key, t_cub3d *cub3d);
void	ft_ray_casting(t_rcast *rc, t_cub3d *cub3d, int x);
t_imgs	ft_get_target_img(t_cub3d *cub3d, t_dda dda, t_ray ray);
void	ft_draw_vertic_line(t_cub3d *cub3d, t_imgs img, int win_x, int tex_x);
void	ft_destroy_all(t_cub3d *cub3d);
void	ft_set_img_addr(t_imgs *imgs);
void	ft_put_img_to_win(void *img, t_cub3d *cub3d);
void	ft_vector_rotation(t_cub3d *cub3d, double x);
double	ft_get_time_diff_sec(struct timeval curr, struct timeval prev);
int		ft_init_sprite(t_cub3d *cub3d);
void	ft_sort_sprite(t_sprite *sprite, size_t num);
void	ft_draw_sprite(t_sprite sprite, t_cub3d *cub3d);
void	ft_sprite_casting(t_cub3d *cub3d, t_sprite *sprite);
int		ft_sprite_animation(t_cub3d *cub3d);
void	ft_destroy_sprite(t_cub3d *cub3d);
// void	ft_print_sprite(t_sprite *sprite, size_t num);

#endif
