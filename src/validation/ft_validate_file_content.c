/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_file_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:58:08 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 11:16:41 by dlippelt         ###   ########.fr       */
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

static int	ft_get_map_file_content(int fd, t_map *m)
{
	size_t	line;

	m->map = malloc(sizeof(char *) * (m->nlines + 1));
	if (!m->map)
		return (ft_error(EMALLOC));
	line = 0;
	while (line <= m->nlines)
		m->map[line++] = NULL;
	line = 0;
	while (line < m->nlines)
	{
		m->map[line] = get_next_line(fd);
		if (!m->map[line])
			return (ft_error(EMALLOC));
		printf("%s\n", m->map[line]);
		line++;
	}
	return (1);
}

int	ft_validate_file_content(int fd, t_map *m)
{
	if (!ft_get_num_lines(fd, m))
		return (0);
	if (!ft_open(m->map_path, &fd))
		return (0);
	if (!ft_get_map_file_content(fd, m))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
