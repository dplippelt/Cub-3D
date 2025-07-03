/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:47:37 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 18:04:51 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "minimap.h"
# include "structs.h"

void	ft_init_cub3d(t_cub3d *cub3d, t_map *map);
int		ft_setup_cub3d(t_cub3d *cub3d, t_file file);
void	ft_start_cub3d(t_cub3d *cub3d);
int		ft_init_mlx_setup_win(t_cub3d *cub3d);
int		ft_init_texture_imgs(t_cub3d *cub3d, t_tex *tex);
int		ft_init_field_of_view(t_cub3d *cub3d);
int		ft_init_game_condition(t_cub3d *cub3d, t_file file);
void	ft_update_field_of_view(t_cub3d *cub3d);
int		ft_calc_frame_time(t_cub3d *cub3d);
void	ft_setup_hooks(void *win, t_cub3d *cub, t_mouse *mouse, t_keys *keys);
void	ft_key_action(t_cub3d *cub3d, t_keys *keys);
int		ft_key_press(int key, void *param);
int		ft_key_release(int key, void *param);
void	ft_ray_casting(t_rcast *rc, t_cub3d *cub3d, int x);
t_imgs	ft_get_target_img(t_cub3d *cub3d, t_dda dda, t_ray ray);
void	ft_destroy_all(t_cub3d *cub3d);
void	ft_set_img_addr(t_imgs *imgs);
void	ft_put_img_to_win(void *img, t_cub3d *cub3d);
int		ft_rendering_loop(void *param);
char	*ft_get_path(int i, t_tex *tex);
// void	ft_setup_key_hook(t_win_list *win, int (*funct)(), void *param);
// void	ft_setup_loop_hook(void *mlx, int (*funct)(), void *param);
void	ft_set_target_img(t_dda *dda, t_ray ray, char c);
void	ft_draw_vertic_line(t_cub3d *cub3d, t_imgs img, int win_x, int tex_x);
void	ft_vector_rotation(t_cub3d *cub3d, double x);
double	ft_get_time_diff_sec(struct timeval curr, struct timeval prev);
int		ft_init_sprite(t_cub3d *cub3d);
void	ft_sort_sprite(t_sprite *sprite, size_t num);
void	ft_draw_sprite(t_sprite sprite, t_cub3d *cub3d);
void	ft_sprite_casting(t_cub3d *cub3d, t_sprite *sprite);
int		ft_sprite_animation(t_cub3d *cub3d);
void	ft_destroy_sprite(t_cub3d *cub3d);
int		ft_init_doors(t_cub3d *cub3d, t_map map);
void	ft_destroy_doors(t_cub3d *cub3d);
void	ft_print_doors(t_door **doors, size_t width);
// void	ft_print_sprite(t_sprite *sprite, size_t num);

#endif
