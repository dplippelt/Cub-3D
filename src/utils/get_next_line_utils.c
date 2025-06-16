/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:43:14 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 17:32:29 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dl;
	size_t	sl;

	dl = ft_gnl_strlen(dst);
	sl = ft_gnl_strlen(src);
	if (size <= dl)
		return (sl + size);
	i = 0;
	while (src[i] && i < size - dl - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}

int	ft_find_new_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_buf	*ft_new_node(int fd)
{
	t_buf	*b;

	b = malloc(sizeof(t_buf));
	if (!b)
		return (NULL);
	b->fd = fd;
	b->buf[0] = '\0';
	b->next = NULL;
	return (b);
}

void	*ft_cleanup_gnl(t_line *l, t_buf **head, t_buf *b, int ok)
{
	t_buf	*temp;

	if (l->tline != l->line)
	{
		free(l->tline);
		l->tline = NULL;
	}
	if ((ok == -1) || (ok == 0 && l->line[0] == '\0'))
	{
		free(l->line);
		l->line = NULL;
		l->eof = 1;
	}
	if (ok <= 0 && b && head)
	{
		temp = *head;
		while (temp && temp != b && temp->next != b)
			temp = temp->next;
		if (temp == b)
			*head = b->next;
		else
			temp->next = b->next;
		free(b);
	}
	return (free(*head), NULL);
}
