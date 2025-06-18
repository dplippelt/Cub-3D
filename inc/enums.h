/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:56:56 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 15:55:56 by dlippelt         ###   ########.fr       */
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

#endif
