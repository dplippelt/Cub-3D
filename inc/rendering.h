/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:47:37 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 11:52:37 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "mlx_int.h" //for t_win_list, can we change to not use t_win_list?

void	ft_init_cub3d(t_cub3d *cub3d, t_map *map);
int		ft_setup_cub3d(t_cub3d *cub3d, t_file file);
void	ft_start_cub3d(t_cub3d *cub3d);
int		ft_init_mlx_setup_win(t_cub3d *cub3d);
int		ft_init_texture_imgs(t_cub3d *cub3d, t_tex *tex);
int		ft_init_field_of_view(t_cub3d *cub3d);
int		ft_init_game_condition(t_cub3d *cub3d, t_file file);
void	ft_update_field_of_view(t_cub3d *cub3d);
int		ft_calc_frame_time(t_cub3d *cub3d);
void	ft_setup_hook(t_win_list *win, int (*funct)(), void *param);
int		ft_key_action(int keycode, t_cub3d *cub3d);
void	ft_ray_casting(t_rcast *rc, t_cub3d *cub3d, int x);
t_imgs	ft_get_target_img(t_cub3d *cub3d, t_dda dda, t_ray ray);
void	ft_draw_vertic_line(t_cub3d *cub3d, t_rcast rc, int screen_x, int texture_x);
void	ft_destroy_all(t_cub3d *cub3d);
void	ft_set_img_addr(t_imgs *imgs);
void	ft_put_img_to_win(void *img, t_cub3d *cub3d);

#endif
