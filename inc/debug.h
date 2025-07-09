/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:32:50 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/08 11:20:08 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG

# include <stdio.h>
# include "enums.h"
# include "structs.h"

void	debug_print_file(t_file *f);
void	debug_print_element_location(int element_id, size_t x, size_t y);
void	debug_print_tex_paths(t_tex *tex);
void	debug_print_rbg_values(t_col *col);
void	debug_print_map_start(char *s, size_t y);
void	debug_print_map(t_map *map);
void	debug_print_str_array(char **sa);
void	debug_print_tex_list(t_tex *tex);

#endif
