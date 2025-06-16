/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:36:58 by dlippelt          #+#    #+#             */
/*   Updated: 2025/01/18 16:15:31 by dlippelt         ###   ########.fr       */
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

typedef struct s_buf
{
	char			buf[BUFFER_SIZE + 1];
	int				fd;
	struct s_buf	*next;
}					t_buf;

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

char	*get_next_line(int fd);
t_buf	*ft_new_node(int fd);
void	*ft_cleanup_gnl(t_line *l, t_buf **head, t_buf *b, int option);
int		ft_find_new_line(char *s);
size_t	ft_gnl_strlen(char *s);
size_t	ft_strlcat(char *dst, char *src, size_t size);

#endif
