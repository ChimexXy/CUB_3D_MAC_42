/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:41:36 by mozahnou          #+#    #+#             */
/*   Updated: 2025/10/19 11:59:22 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	perform_dda(t_config *cfg, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		hit = check_hit(cfg, ray);
	}
}

double	calc_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	else
		return (ray->side_dist_y - ray->delta_dist_y);
}

void	calc_draw_bounds(double wall_dist, int *start, int *end)
{
	int	line_height;

	line_height = (int)(WIN_H / wall_dist);
	*start = -line_height / 2 + WIN_H / 2;
	if (*start < 0)
		*start = 0;
	*end = line_height / 2 + WIN_H / 2;
	if (*end >= WIN_H)
		*end = WIN_H - 1;
}

void	cast_single_ray(t_config *cfg, int x)
{
	t_ray		ray;
	double		wall_dist;
	int			draw_start;
	int			draw_end;
	uint32_t	color;

	init_ray_direction(cfg, x, &ray);
	init_delta_dist(&ray);
	init_step_x(cfg, &ray);
	init_step_y(cfg, &ray);
	perform_dda(cfg, &ray);
	wall_dist = calc_wall_dist(&ray);
	calc_draw_bounds(wall_dist, &draw_start, &draw_end);
	if (ray.side == 1)
		color = 0xFF0000FF;
	else
		color = 0x0000FFFF;
	draw_vertical_line(cfg, x, draw_start, draw_end, color);
}

void	raycasting(t_config *cfg)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		cast_single_ray(cfg, x);
		x++;
	}
}
