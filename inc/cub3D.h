/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:50:47 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 18:15:28 by tmitsuya         ###   ########.fr       */
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
# include "utils.h"
# define TITLE "cub3D"
# define NUM_OF_IMGS 4  // temporary need to set correct number
# define P_NO "textures/block_x64.xpm" // temporary for test
# define P_SO "textures/item_x64.xpm" // temporary for test
# define P_WE "textures/goal_x64.xpm" // temporary for test
# define P_EA "textures/player_x64_0.xpm" // temporary for test
# define TEXTURE_SIZE 64
# define DIST_PER_SECOND 5.0
# define RADIAN_PER_SECOND 2.0

enum e_img_field
{
	NO,
	SO,
	WE,
	EA,
};

typedef struct s_imgs
{
	t_img	*img;
	char	*data;
	int		sl;
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

enum e_side
{
	ROW_SIDE,
	COL_SIDE,
};

#define mapWidth 10 // temporary for test
#define mapHeight 10 // temporary for test

typedef struct	s_cub3d
{
	t_xvar			*mlx;
	t_win_list		*win;
	t_imgs			*imgs;
	t_imgs			fov;
	int				win_x;
	int				win_y;
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
	char			map[mapWidth][mapHeight]; // temporary for test
	int				f_color;
	int				c_color;
}					t_cub3d;

void	ft_init_mlx_setup_win(t_cub3d *cub3d);
void	ft_init_texture_imgs(t_cub3d *cub3d);
void	ft_calc_frame_time(t_cub3d *cub3d);
void	ft_start_cub3d(t_cub3d *cub3d);
void	ft_setup_hook(t_win_list *win, int (*funct)(), void *param);
int		ft_key_action(int keycode, t_cub3d *cub3d);
void	ft_ray_casting(t_rcast *rc, t_cub3d *cub3d, int x);
t_imgs	ft_get_target_img(t_cub3d *cub3d, t_dda dda, t_ray ray);
void	ft_draw_vertic_line(t_cub3d *cub3d, t_rcast rc, int screen_x, int texture_x);
void	ft_update_field_of_view(t_cub3d *cub3d);
void	ft_destroy_mlx_win(t_cub3d *cub3d);
void	ft_destroy_texture_imgs(t_xvar *mlx, t_imgs *imgs);
void	ft_destroy_all(t_cub3d *cub3d);
void	ft_set_img_addr(t_imgs *imgs);
void	ft_put_img_to_win(t_img *img, t_cub3d *cub3d);
void	test_map_data(t_cub3d *cub3d); // temporary for test

#endif
