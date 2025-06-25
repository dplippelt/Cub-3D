/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture_imgs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:29:29 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/25 16:13:52 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_get_path(int i) // temprarily set texture's path
{
	if (i == NO)
		return (P_NO);
	else if (i == SO)
		return (P_SO);
	else if (i == WE)
		return (P_WE);
	else if (i == EA)
		return (P_EA);
	else
		return (NULL);
}

static void	ft_loading_texture(t_xvar *mlx, t_imgs *imgs, int i, char *path)
{
	if (!path)
		imgs[i].img = NULL;
	else
	{
		imgs[i].img = mlx_xpm_file_to_image(mlx, path, &imgs[i].x, &imgs[i].y);
		if (imgs[i].img)
			ft_set_img_addr(&imgs[i]);
	}
}

static int	ft_is_loading_success(t_imgs *imgs)
{
	int	i;

	i = 0;
	while (i < NUM_OF_IMGS)
	{
		if (!imgs[i].img)
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_texture_imgs(t_cub3d *cub3d)
{
	int	i;

	cub3d->imgs = (t_imgs *)malloc(sizeof(t_imgs) * (NUM_OF_IMGS + 1));
	if (!cub3d->imgs)
		return (0);
	i = 0;
	while (i < NUM_OF_IMGS)
	{
		ft_loading_texture(cub3d->mlx, cub3d->imgs, i, ft_get_path(i)); // to get path from the map
		i++;
	}
	cub3d->imgs[NUM_OF_IMGS].img = NULL;
	if (!ft_is_loading_success(cub3d->imgs))
		return (0);
	return (1);
}
