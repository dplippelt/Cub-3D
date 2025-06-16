/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:46:25 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 15:19:55 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "utils.h"
# include "enums.h"
# include "macros.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	ft_validate_map(const char *map_path);

#endif
