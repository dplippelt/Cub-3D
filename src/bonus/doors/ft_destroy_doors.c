/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_doors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:36:04 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/09 19:30:47 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_destroy_doors(t_cub3d *cub3d)
{
	size_t	i;

	if (cub3d->doors)
	{
		i = 0;
		while (cub3d->doors[i])
		{
			free(cub3d->doors[i]);
			i++;
		}
		free(cub3d->doors);
	}
}
