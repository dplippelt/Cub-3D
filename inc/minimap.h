/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:35:20 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 13:43:45 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <stdio.h>
# include "mlx.h"
# include "utils.h"
# include "macros.h"
# include "structs.h"

int		ft_init_minimap(t_cub3d *cub);
void	ft_draw_minimap(t_mmap *mmap);
int		ft_get_cell_id(int line, int i, t_mmap *mmap);
void	ft_add_objects(t_mmap *mmap);
void	ft_set_img_addr(t_imgs *imgs);
void	ft_draw_door_hor(int line, int i, int color, t_mmap *mmap);
void	ft_draw_door_ver(int line, int i, int color, t_mmap *mmap);

#endif
