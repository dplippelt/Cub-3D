/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:24 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 12:50:19 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	ft_cleanup_file(t_file *f)
{
	size_t	line;

	if (!f->file)
		return ;
	line = 0;
	while (f->file[line])
	{
		free(f->file[line]);
		line++;
	}
	free(f->file);
}
