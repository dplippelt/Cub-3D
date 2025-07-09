/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:56:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/09 18:30:15 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum e_errors
{
	ERRNO = 0,
	ENUMPARAM = 1,
	EFILEFORMAT = 2,
	EMALLOC = 3,
	EUNEXPECTED = 4,
	EMISSINGTEX = 5,
	EMISSINGCOL = 6,
	EDUPENTRIES = 7,
	EWALL = 8,
	ENUMPLAYERS = 9,
	EMLXINIT = 10,
	EMLXWIN = 11,
	EMLXLOADTEX = 12,
	EMLXNEWIMG = 13,
	EGETTIME = 14,
	EMAP = 15,
	EDOOR = 16,
	ECOLORFORMAT = 999
};

enum e_elements
{
	NOELEMENT,
	TEXNORTH,
	TEXEAST,
	TEXWEST,
	TEXSOUTH,
	TEXDOOR,
	TEXSQUIRREL_ZERO,
	TEXSQUIRREL_ONE,
	TEXSQUIRREL_TWO,
	TEXSQUIRREL_THREE,
	COLFLOOR,
	COLCEILING
};

enum e_colors
{
	RED,
	GREEN,
	BLUE
};

enum e_cell
{
	FLOOR_CELL,
	WALL_CELL,
	CLOSED_DOOR_CELL,
	OPEN_DOOR_CELL,
	PLAYER_CELL,
	SQUIRREL_CELL,
	BACKGROUND_CELL
};

// enum e_wall_side
// {
// 	TOP,
// 	RIGHT,
// 	BOTTOM,
// 	LEFT
// };

enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef enum e_side
{
	ROW_SIDE,
	COL_SIDE,
}	t_side;

typedef enum e_img_field
{
	NO,
	SO,
	WE,
	EA,
	SPRITE_0,
	SPRITE_1,
	SPRITE_2,
	SPRITE_3,
	DOOR,
	MAX_IMAGE,
}	t_img_field;

typedef enum e_status
{
	CLOSE,
	CLOSING,
	OPENING,
	OPEN,
}	t_status;

#endif
