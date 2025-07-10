/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:53:28 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 15:41:53 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_errno(int e)
{
	if (e == ERRNO)
	{
		ft_putstr(strerror(errno), 2);
		ft_putstr("\n", 2);
	}
}

static void	ft_validation_error(int e)
{
	if (e == ENUMPARAM)
		ft_putstr("Incorrect number of parameters\n", 2);
	else if (e == EFILEFORMAT)
		ft_putstr("Configuration file has incorrect file format\n", 2);
	else if (e == EMALLOC)
		ft_putstr("Failed to allocate memory\n", 2);
	else if (e == ECOLORFORMAT)
		ft_putstr("Invalid RGB format\n", 2);
	else if (e == EUNEXPECTED)
		ft_putstr("Configuration file contains unexpected symbol\n", 2);
	else if (e == EMISSINGTEX)
		ft_putstr("Configuration file is missing a required texture path\n", 2);
	else if (e == EMISSINGCOL)
		ft_putstr("Configuration file is missing required color info\n", 2);
	else if (e == EDUPENTRIES)
		ft_putstr("Configuration file contains duplicate entries\n", 2);
	else if (e == EWALL)
		ft_putstr("The map is not fully surrounded by a wall\n", 2);
	else if (e == ENUMPLAYERS)
		ft_putstr("Incorrect number of players found\n", 2);
	else if (e == EDOORS)
		ft_putstr("Incorrect door placement\n", 2);
	else if (e == EMAP)
		ft_putstr("Map contains space characters in playable area\n", 2);
}

static void	ft_mlx_error(int e)
{
	if (e == EMLXINIT)
		ft_putstr("Failed to initialize MLX\n", 2);
	else if (e == EMLXWIN)
		ft_putstr("Failed to create MLX window\n", 2);
	else if (e == EMLXLOADTEX)
		ft_putstr("Failed to load a texture\n", 2);
	else if (e == EMLXNEWIMG)
		ft_putstr("Failed to create new image buffer\n", 2);
}

static void	ft_misc_error(int e)
{
	if (e == EGETTIME)
		ft_putstr("Failed to get current time\n", 2);
}

int	ft_error(int e)
{
	ft_putstr("Error\n", 2);
	ft_errno(e);
	ft_validation_error(e);
	ft_mlx_error(e);
	ft_misc_error(e);
	return (0);
}
