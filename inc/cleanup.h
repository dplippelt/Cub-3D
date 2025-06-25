/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:46 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 11:54:44 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include <stdlib.h>
# include "structs.h"

void	ft_cleanup(t_file *f);
void	ft_cleanup_str_array(char **sa);
void	ft_cleanup_tex(t_tex *curr);
void	ft_cleanup_col(t_col *curr);

#endif
