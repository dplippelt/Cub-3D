/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:00:49 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 11:16:03 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_line
{
	char	*line;
	char	*tline;
	int		eof;
	int		ok;
	int		br;
	int		i;
	size_t	size;
	size_t	cap;
}			t_line;

void		*gnl_cleanup(t_line *l, char *buf, int option);
char		*get_next_line(int fd);
void		gnl_init(t_line *l);
int			gnl_find_new_line(char *s);
size_t		gnl_strlen(char *s);
size_t		gnl_strlcat(char *dst, char *src, size_t size);

#endif
