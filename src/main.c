/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:50:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/16 14:47:38 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_error(ENUMPARAM);
		return (1);
	}
	if (!ft_validate_map(av[1]))
		return (1);
	return (0);
}
