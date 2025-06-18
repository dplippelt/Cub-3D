/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:02:38 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 12:08:02 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "enums.h"

int		ft_error(int e);
ssize_t	ft_strlen(const char *s);
int		ft_putstr(const char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		strncmp(const char *s1, const char *s2, size_t n);
int		ft_open(const char *path, int *fd);

#endif
