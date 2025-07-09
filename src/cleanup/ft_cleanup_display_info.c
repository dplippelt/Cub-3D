/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_display_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:18:57 by dlippelt          #+#    #+#             */
/*   Updated: 2025/07/09 17:20:11 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	ft_cleanup_display_info(t_display_info *di)
{
	if (di->value)
	{
		free(di->value);
		di->value = NULL;
	}
}
