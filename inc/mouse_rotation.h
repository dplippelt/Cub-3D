/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:08:12 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 16:36:52 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_ROTATION_H
# define MOUSE_ROTATION_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "structs.h"
# include "macros.h"

int		ft_mouse_move(int x, int y, void *param);
void	ft_init_mouse(t_cub3d *cub);

#endif
