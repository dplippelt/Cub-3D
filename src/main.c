/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:50:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/25 19:02:10 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char *av[])
{
	t_cub3d	cub3d;
	t_file	f;

	if (ac != 2)
	{
		ft_error(ENUMPARAM);
		return (EXIT_FAILURE);
	}
	ft_init(&f, av);
	if (!ft_validate_file(&f))
	{
		ft_cleanup(&f);
		return (EXIT_FAILURE);
	}
	ft_init_cub3d(&cub3d, f.map.map);
	if (!ft_setup_cub3d(&cub3d, f))
	{
		ft_destroy_all(&cub3d);
		ft_cleanup(&f);
		return (EXIT_FAILURE);
	}
	ft_start_cub3d(&cub3d);
	ft_destroy_all(&cub3d);
	ft_cleanup(&f);
	return (EXIT_SUCCESS);
}
