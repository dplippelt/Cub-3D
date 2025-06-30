/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:35:20 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 12:42:22 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include <stdio.h>
# include "structs.h"
# include "mlx.h"
# include "utils.h"
# include "rendering.h"
# include "macros.h"

int	ft_init_minimap(t_cub3d *cub);
int	ft_draw_minimap(t_mmap *mmap);

#endif
