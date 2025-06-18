/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:46 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 15:53:57 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include <stdlib.h>
# include "structs.h"

void	ft_cleanup(t_file *f);
void	ft_cleanup_file(char **file);
void	ft_cleanup_tex(t_tex *curr);
void	ft_cleanup_col(t_col *curr);

#endif
