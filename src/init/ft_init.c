/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:29:41 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 11:48:16 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init(t_file *f, char *av[])
{
	f->file = NULL;
	f->file_path = av[1];
	f->nlines = 0;
	f->tex = NULL;
	f->col = NULL;
	f->map.map = NULL;
	f->map.height = 0;
	f->map.width = 0;
}
