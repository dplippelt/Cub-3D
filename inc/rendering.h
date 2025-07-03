/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:47:37 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 17:12:36 by dlippelt         ###   ########.fr       */
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
void	ft_draw_vertic_line(t_cub3d *cub3d, t_rcast rc, int screen_x, int texture_x);
void	ft_destroy_all(t_cub3d *cub3d);
void	ft_set_img_addr(t_imgs *imgs);
void	ft_put_img_to_win(void *img, t_cub3d *cub3d);
int		ft_rendering_loop(void *param);

#endif
