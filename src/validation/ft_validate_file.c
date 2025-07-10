/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:42:29 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/10 16:06:46 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_validate_file_format(const char *file_path)
{
	size_t	slen;

	slen = ft_strlen(file_path);
	if (slen < 4)
		return (ft_error(EFILEFORMAT));
	slen -= 4;
	if (ft_strcmp(&file_path[slen], FORMAT))
		return (ft_error(EFILEFORMAT));
	return (1);
}

int	ft_validate_file(t_file *f)
{
	if (!ft_validate_file_format(f->file_path))
		return (0);
	if (!ft_validate_file_content(f))
		return (0);
	return (1);
}
