/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:02:38 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 15:00:46 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

int		ft_error(int e);
ssize_t	ft_strlen(char *s);
int		ft_putstr(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);

#endif
