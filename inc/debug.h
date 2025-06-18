/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:32:50 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 12:57:23 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG

# include <stdio.h>
# include "enums.h"
# include "structs.h"

void	debug_print_map(t_file *f);
void	debug_print_element_location(int element_id, size_t x, size_t y);

#endif
