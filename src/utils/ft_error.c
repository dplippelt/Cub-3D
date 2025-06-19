/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:53:28 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 13:13:38 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enums.h"
#include "utils.h"

int	ft_error(int e)
{
	ft_putstr("Error\n", 2);
	if (e == ERRNO)
	{
		ft_putstr(strerror(errno), 2);
		ft_putstr("\n", 2);
	}
	if (e == ENUMPARAM)
		ft_putstr("Incorrect number of parameters\n", 2);
	if (e == EFILEFORMAT)
		ft_putstr("Map file has incorrect file format\n", 2);
	if (e == EMALLOC)
		ft_putstr("Failed to allocate memory\n", 2);
	if (e == ECOLORFORMAT)
		ft_putstr("Invalid RGB format\n", 2);
	if (e == EUNEXPECTED)
		ft_putstr("Map file contains unexpected symbol\n", 2);
	if (e == EMISSINGINFO)
		ft_putstr("File is missing necessary information\n", 2);
	if (e == EDUPENTRIES)
		ft_putstr("File contains duplicate entries\n", 2);
	return (0);
}
