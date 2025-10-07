/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:44:36 by mozahnou          #+#    #+#             */
/*   Updated: 2025/10/07 16:48:33 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_vertical_line(t_config *cfg, int x, int start, int end, uint32_t color)
{
	int	y;

	y = start;
	while (y <= end)
	{
		if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
			mlx_put_pixel(cfg->img, x, y, color);
		y++;
	}
}

int	init_mlx(t_config *cfg)
{
	cfg->mlx = mlx_init(WIN_W, WIN_H, "Cub3D", true);
	if (!cfg->mlx)
	{
		puts("Error: MLX init failed\n");
		return (0);
	}
	cfg->img = mlx_new_image(cfg->mlx, WIN_W, WIN_H);
	if (!cfg->img)
	{
		puts("Error: Image creation failed\n");
		mlx_terminate(cfg->mlx);
		return (0);
	}
	return (1);
}