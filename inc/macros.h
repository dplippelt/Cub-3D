/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:08:02 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/30 15:42:28 by dlippelt         ###   ########.fr       */
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
# define NTEX 4
# define NCOL 2
# define BGRA(b,g,r,a) ((a << 24) | (r << 16) | (g << 8) | b)
# define CELL_SIZE 20
# define MM_X 50
# define MM_Y 50

#endif
