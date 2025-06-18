/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:50:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 15:54:15 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char *av[])
{
	t_file	f;

	if (ac != 2)
	{
		ft_error(ENUMPARAM);
		return (1);
	}
	ft_init(&f, av);
	if (!ft_validate_file(&f))
	{
		ft_cleanup(&f);
		return (1);
	}
	ft_cleanup(&f);
	return (0);
}
