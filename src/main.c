/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:50:19 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/25 16:15:25 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char *av[])
{
	t_cub3d	cub3d;
	// if (ac != 2)
	// {
	// 	ft_error(ENUMPARAM);
	// 	return (1);
	// }
	(void)ac;
	(void)av;
	// TODO: Loading map into a 2D array
	// TODO: Validation check for the map
	test_map_data(&cub3d); // temporary
	ft_init_cub3d(&cub3d);
	if (!ft_setup_cub3d(&cub3d))
	{
		ft_destroy_all(&cub3d);
		return (EXIT_FAILURE);
	}
	ft_start_cub3d(&cub3d);
	ft_destroy_all(&cub3d);
	return (EXIT_SUCCESS);
}
