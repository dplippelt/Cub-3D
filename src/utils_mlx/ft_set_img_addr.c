/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_img_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:02:43 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/06/25 14:41:23 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_set_img_addr(t_imgs *imgs)
{
	int	bpp;
	int	sl;
	int	endian;

	imgs->data = mlx_get_data_addr(imgs->img, &bpp, &sl, &endian);
	imgs->bpp = bpp;
	imgs->sl = sl;
	imgs->endian = endian;
}
