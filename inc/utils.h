/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:02:38 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 15:26:29 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

int		ft_error(int e);
ssize_t	ft_strlen(const char *s);
int		ft_putstr(const char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);

#endif
