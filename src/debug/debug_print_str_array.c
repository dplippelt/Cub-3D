/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_str_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:29:14 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 15:30:03 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_print_str_array(char **sa)
{
	while (*sa)
	{
		printf("%s\n", *sa);
		sa++;
	}
}
