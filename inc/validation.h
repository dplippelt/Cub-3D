/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:46:25 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 16:28:45 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "utils.h"
# include "enums.h"
# include "macros.h"
# include "structs.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	ft_validate_map(t_map *m);
int	ft_validate_file_content(int fd, t_map *m);

#endif
