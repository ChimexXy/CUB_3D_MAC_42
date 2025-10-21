/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:46:41 by mozahnou          #+#    #+#             */
/*   Updated: 2025/10/19 10:52:25 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_ray_direction(t_config *cfg, int x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_W - 1;
	ray->dir_x = cfg->dir_x + cfg->plane_x * camera_x;
	ray->dir_y = cfg->dir_y + cfg->plane_y * camera_x;
	ray->map_x = (int)cfg->player.x;
	ray->map_y = (int)cfg->player.y;
}

void	init_delta_dist(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	init_step_x(t_config *cfg, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cfg->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cfg->player.x)
			* ray->delta_dist_x;
	}
}

void	init_step_y(t_config *cfg, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cfg->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cfg->player.y)
			* ray->delta_dist_y;
	}
}

int	check_hit(t_config *cfg, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_x < 0)
		return (1);
	if (!cfg->map[ray->map_y] || !cfg->map[ray->map_y][ray->map_x])
		return (1);
	if (cfg->map[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}
