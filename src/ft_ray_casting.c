/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmitsuya <tmitsuya@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:16:42 by tmitsuya          #+#    #+#             */
/*   Updated: 2025/07/03 20:41:18 by tmitsuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_ray_dir(t_ray *ray, t_cub3d *cub3d, int i)
{
	double	x_coordinate_on_camera;

	x_coordinate_on_camera = 2 * i / (double)(cub3d->win_x - 1) - 1;
	ray->dir_row = cub3d->dir_row + cub3d->plane_row * x_coordinate_on_camera;
	ray->dir_col = cub3d->dir_col + cub3d->plane_col * x_coordinate_on_camera;
}

static void	ft_calc_dist_for_dda(t_dist *dist, t_ray ray, t_cub3d *cub3d)
{
	int	map_row;
	int	map_col;

	if (fabs(ray.dir_row) < EPSILON)
		dist->delta_row = INFINITY;
	else
		dist->delta_row = fabs(1 / ray.dir_row);
	if (fabs(ray.dir_col) < EPSILON)
		dist->delta_col = INFINITY;
	else
		dist->delta_col = fabs(1 / ray.dir_col);
	map_row = (int)cub3d->pos_row;
	map_col = (int)cub3d->pos_col;
	if (ray.dir_row < 0)
		dist->side_row = (cub3d->pos_row - map_row) * dist->delta_row;
	else
		dist->side_row = (map_row + 1 - cub3d->pos_row) * dist->delta_row;
	if (ray.dir_col < 0)
		dist->side_col = (cub3d->pos_col - map_col) * dist->delta_col;
	else
		dist->side_col = (map_col + 1 - cub3d->pos_col) * dist->delta_col;
}

static void	ft_set_step_for_dda(t_dda *dda, t_ray ray)
{
	if (ray.dir_row < 0)
		dda->step_row = -1;
	else
		dda->step_row = 1;
	if (ray.dir_col < 0)
		dda->step_col = -1;
	else
		dda->step_col = 1;
}

int	ft_is_door(t_dda *dda, t_dist dist, t_ray ray, t_cub3d *cub3d)
{
	t_door	door;
	double	door_dist;
	double	intsec;

	if (cub3d->map[dda->map_row][dda->map_col] != 'D')
		return (0);
	door = cub3d->doors[dda->map_row][dda->map_col];
	if (dda->side == ROW_SIDE)
	{
		door_dist = dist.side_row - (dist.delta_row / 2);
		intsec = cub3d->pos_col + door_dist * ray.dir_col;
		if (intsec - (door.col + door.open_ratio) > EPSILON && ((int)door.col + 1) - intsec > EPSILON)
			return (1);
	}
	else
	{
		door_dist = dist.side_col - (dist.delta_col / 2);
		intsec = cub3d->pos_row + door_dist * ray.dir_row;
		if (intsec - (door.row + door.open_ratio) > EPSILON && ((int)door.row + 1) - intsec > EPSILON)
			return (1);
	}
	return (0);	
}

void	ft_get_dist(t_dda *dda, t_dist dist, t_cub3d *cub3d)
{
	if (dda->side == ROW_SIDE)
	{
		if (cub3d->map[dda->map_row][dda->map_col] == '1')
			dda->wall_dist = dist.side_row - dist.delta_row;
		else
			dda->wall_dist = dist.side_row - (dist.delta_row / 2);
	}
	else
	{
		if (cub3d->map[dda->map_row][dda->map_col] == '1')
			dda->wall_dist = dist.side_col - dist.delta_col;
		else
			dda->wall_dist = dist.side_col - (dist.delta_col / 2);			
	}
}

static void	ft_digi_diff_analyze(t_dda *dda, t_dist dist, t_ray ray, t_cub3d *cub3d)
{
	dda->map_row = (int)cub3d->pos_row;
	dda->map_col = (int)cub3d->pos_col;
	dda->hit = 0;
	while (!dda->hit)
	{
		if (dist.side_row < dist.side_col)
		{
			dist.side_row += dist.delta_row;
			dda->map_row += dda->step_row;
			dda->side = ROW_SIDE;
		}
		else
		{
			dist.side_col += dist.delta_col;
			dda->map_col += dda->step_col;
			dda->side = COL_SIDE;
		}
		if (cub3d->map[dda->map_row][dda->map_col] == '1')
			dda->hit = 1;
		if (ft_is_door(dda, dist, ray, cub3d))
			dda->hit = 1;
	}
	ft_get_dist(dda, dist, cub3d);;
}

void	ft_ray_casting(t_rcast *rc, t_cub3d *cub3d, int win_x)
{
	ft_set_ray_dir(&rc->ray, cub3d, win_x);
	ft_calc_dist_for_dda(&rc->dist, rc->ray, cub3d);
	ft_set_step_for_dda(&rc->dda, rc->ray);
	ft_digi_diff_analyze(&rc->dda, rc->dist, rc->ray, cub3d);
	ft_set_target_img(&rc->dda, rc->ray, cub3d->map[rc->dda.map_row][rc->dda.map_col]);
	cub3d->wall_dists[win_x] = rc->dda.wall_dist;
}
