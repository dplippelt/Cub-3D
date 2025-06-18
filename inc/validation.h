/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:46:25 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 18:10:31 by dlippelt         ###   ########.fr       */
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

int		ft_validate_file(t_file *f);
int		ft_validate_file_content(t_file *f);
int		ft_validate_elements(t_file *f);
int		ft_get_element_info(t_file *f, char *el, int el_id);
int		ft_new_tex(t_tex **head, char *el, int el_id);
int		ft_new_col(t_col **head, char *el, int el_id);

#endif
