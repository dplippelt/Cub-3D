/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_file_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:58:08 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 16:43:32 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	ft_read(int fd, t_map *m)
{
	static ssize_t	br;
	static char		buffer[1];

	br = read(fd, buffer, 1);
	if (br == -1)
		return (ft_error(ERRNO));
	if (br == 0)
		return (1);
	if (*buffer == '\n')
		m->nlines++;
	return (ft_read(fd, m));
}

static ssize_t	ft_get_num_lines(int fd, t_map *m)
{
	if (!ft_read(fd, m))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_validate_file_content(int fd, t_map *m)
{
	if (!ft_get_num_lines(fd, m))
		return (0);
	return (1);
}
