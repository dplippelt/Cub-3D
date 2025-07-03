/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:56:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/03 17:59:05 by dlippelt         ###   ########.fr       */
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
	EMISSINGINFO = 5,
	EDUPENTRIES = 6,
	EWALL = 7,
	ENUMPLAYERS = 8,
	EMLXINIT = 9,
	EMLXWIN = 10,
	EMLXLOADTEX = 11,
	EMLXNEWIMG = 12,
	EGETTIME = 13,
	EMAP = 14,
	ECOLORFORMAT = 999
};

enum e_elements
{
	NOELEMENT = 0,
	TEXNORTH,
	TEXEAST,
	TEXWEST,
	TEXSOUTH,
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
	FLOOR,
	WALL,
	DOOR,
	PLAYER,
	SQUIRREL,
	BACKGROUND
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

enum e_side
{
	ROW_SIDE,
	COL_SIDE,
};

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

enum e_status
{
	CLOSE,
	CLOSING,
	OPENING,
	OPEN,
};

#endif
