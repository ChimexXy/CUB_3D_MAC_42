/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:22:53 by mozahnou          #+#    #+#             */
/*   Updated: 2025/10/14 13:34:21 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_point_wall(t_config *cfg, int mx, int my)
{
	if (my < 0 || mx < 0)
		return (1);
	if (!cfg->map[my] || !cfg->map[my][mx])
		return (1);
	if (cfg->map[my][mx] == '1')
		return (1);
	return (0);
}

int	is_wall(t_config *cfg, double x, double y)
{
	double	m;
	int		i;
	int		mx;
	int		my;

	m = (1.0 / 6.0) * 0.5;
	i = 0;
	while (i < 4)
	{
		if (i == 0)
			mx = (int)(x - m);
		else if (i == 1)
			mx = (int)(x + m);
		else if (i == 2)
			mx = (int)(x - m);
		else
			mx = (int)(x + m);
		if (i < 2)
			my = (int)(y - m);
		else
			my = (int)(y + m);
		if (check_point_wall(cfg, mx, my))
			return (1);
		i++;
	}
	return (0);
}

void	rotate(t_config *cfg, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cfg->dir_x;
	cfg->dir_x = cfg->dir_x * cos(angle) - cfg->dir_y * sin(angle);
	cfg->dir_y = old_dir_x * sin(angle) + cfg->dir_y * cos(angle);
	old_plane_x = cfg->plane_x;
	cfg->plane_x = cfg->plane_x * cos(angle) - cfg->plane_y * sin(angle);
	cfg->plane_y = old_plane_x * sin(angle) + cfg->plane_y * cos(angle);
}

void	apply_rotation(t_config *cfg)
{
	if (cfg->player.rotate_right)
		rotate(cfg, ROT_SPEED);
	if (cfg->player.rotate_left)
		rotate(cfg, -ROT_SPEED);
}

void	apply_movement(t_config *cfg, double *nx, double *ny)
{
	if (cfg->player.move_up)
	{
		*nx += cfg->dir_x * MOVE_SPEED;
		*ny += cfg->dir_y * MOVE_SPEED;
	}
	if (cfg->player.move_down)
	{
		*nx -= cfg->dir_x * MOVE_SPEED;
		*ny -= cfg->dir_y * MOVE_SPEED;
	}
	if (cfg->player.move_left)
	{
		*nx += cfg->dir_y * MOVE_SPEED;
		*ny -= cfg->dir_x * MOVE_SPEED;
	}
	if (cfg->player.move_right)
	{
		*nx -= cfg->dir_y * MOVE_SPEED;
		*ny += cfg->dir_x * MOVE_SPEED;
	}
}
