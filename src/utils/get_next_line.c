/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:41:49 by dlippelt          #+#    #+#             */
/*   Updated: 2025/01/16 11:22:33 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buf	*ft_init(t_line *l, t_buf **head, int fd)
{
	t_buf	*current;

	l->line = NULL;
	l->tline = NULL;
	l->eof = 0;
	l->size = 0;
	l->cap = 0;
	if (!(*head))
	{
		*head = ft_new_node(fd);
		return (*head);
	}
	current = *head;
	while (current->next)
	{
		if (fd == current->fd)
			return (current);
		current = current->next;
	}
	if (fd == current->fd)
		return (current);
	current->next = ft_new_node(fd);
	return (current->next);
}

static int	ft_malloc_line_exact(t_line *l)
{
	if (l->line)
	{
		l->cap = ft_gnl_strlen(l->line) + 1;
		l->tline = l->line;
		l->line = malloc(l->cap);
		if (!l->line)
			return (0);
		l->line[0] = '\0';
		l->size = ft_strlcat(l->line, l->tline, l->cap);
	}
	return (1);
}

static int	ft_malloc_line(t_line *l, char *buf)
{
	if (!l->cap)
		l->cap = ft_gnl_strlen(buf) + 1;
	else if (l->size * 2 < l->cap)
		l->cap = SIZE_MAX;
	else
		l->cap = l->size * 2;
	l->tline = l->line;
	l->line = malloc(l->cap);
	if (!l->line)
		return (0);
	l->line[0] = '\0';
	if (l->tline && (l->cap == l->size * 2 || l->cap == SIZE_MAX))
		l->size = ft_strlcat(l->line, l->tline, l->cap);
	free(l->tline);
	l->tline = NULL;
	return (1);
}

static int	ft_get_line(t_line *l, char *buf, int fd)
{
	l->i = ft_find_new_line(buf);
	while (l->i == -1)
	{
		l->size = ft_strlcat(l->line, buf, l->cap);
		l->br = read(fd, buf, BUFFER_SIZE);
		if (l->br >= 0)
			buf[l->br] = '\0';
		if (l->br <= 0)
			return (l->br);
		if (l->size + l->br < (size_t)l->br)
			return (-1);
		l->size += l->br;
		l->i = ft_find_new_line(buf);
		if (l->cap <= l->size)
			if (!ft_malloc_line(l, buf))
				return (-1);
	}
	buf[l->i] = '\0';
	l->size = ft_strlcat(l->line, buf, l->cap);
	l->line[l->size] = '\n';
	l->line[l->size + 1] = '\0';
	buf[0] = '\0';
	ft_strlcat(buf, buf + l->i + 1, BUFFER_SIZE + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	t_line			l;
	static t_buf	*head;
	t_buf			*b;

	b = ft_init(&l, &head, fd);
	if (!b)
		return (NULL);
	if (fd < 0)
		return (ft_cleanup_gnl(&l, &head, b, -1));
	if (!ft_malloc_line(&l, b->buf))
		return (ft_cleanup_gnl(&l, &head, b, -1));
	l.ok = ft_get_line(&l, b->buf, fd);
	if (!ft_malloc_line_exact(&l))
		return (ft_cleanup_gnl(&l, &head, b, -1));
	ft_cleanup_gnl(&l, &head, b, l.ok);
	if (l.eof || l.ok == -1)
		return (NULL);
	return (l.line);
}
