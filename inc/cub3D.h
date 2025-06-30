/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:50:47 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 11:48:27 by dlippelt         ###   ########.fr       */
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
# include "rendering.h"
# include "minimap.h"
# include "cleanup.h"
# include "structs.h"
# define TITLE "cub3D"
# define NUM_OF_IMGS 4  // temporary need to set correct number
# define TEXTURE_SIZE 128
# define DIST_PER_SECOND 5.0
# define RADIAN_PER_SECOND 2.0

#endif
