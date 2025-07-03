/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:08:02 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 15:55:17 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define FORMAT ".cub"
# define TITLE "cub3D"
# define NUM_OF_IMGS 4  // temporary need to set correct number, This is identical to NTEX
# define TEXTURE_SIZE 128
# define DIST_PER_SECOND 5.0
# define RADIAN_PER_SECOND 2.0
# define WIN_X_DEFAULT 1920
# define WIN_Y_DEFAULT (WIN_X_DEFAULT * 3/4)
# define MOUSE_SENSITIVITY_DEFAULT 500
# define NTEX 4
# define NCOL 2
# define BGRA(b,g,r,a) ((a << 24) | (r << 16) | (g << 8) | b)
# define MM_MAX_SIZE 300
# define CELL_SIZE_DEFAULT 20
# define PLAYER_BORDER_DEFAULT 5
# define MM_X WIN_X_DEFAULT / 40
# define MM_Y MM_X
# define WALL_COLOR BGRA(128, 128, 128, 0)
# define BG_COLOR BGRA(64, 64, 64, 0)
# define FLOOR_COLOR BGRA(0, 0, 100, 0)
# define PLAYER_COLOR BGRA(0, 100, 0, 0)
// # define SQUIRREL_COLOR BGRA(0, 215, 255, 0)		//Gold
// # define SQUIRREL_COLOR BGRA(63, 133, 205, 0)	//Light Brown
# define SQUIRREL_COLOR BGRA(19, 69, 139, 0)		//Medium Brown
// # define SQUIRREL_COLOR BGRA(33, 67, 101, 0)		//Dark Brown

#endif
