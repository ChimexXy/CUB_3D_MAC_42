/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:39:26 by mozahnou          #+#    #+#             */
/*   Updated: 2025/10/07 16:39:26 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	update_player_position(t_config *cfg)
{
	double	nx;
	double	ny;

	nx = cfg->player.x;
	ny = cfg->player.y;
	apply_rotation(cfg);
	apply_movement(cfg, &nx, &ny);
	if (!is_wall(cfg, nx, cfg->player.y))
		cfg->player.x = nx;
	if (!is_wall(cfg, cfg->player.x, ny))
		cfg->player.y = ny;
}

void	render_2d_map(t_config *cfg)
{
	if (!init_mlx(cfg))
		exit(1);
	mlx_image_to_window(cfg->mlx, cfg->img, 0, 0);
	init_player_flags(cfg);
	set_player_position(cfg);
	mlx_key_hook(cfg->mlx, &handle_keys, cfg);
	mlx_loop_hook(cfg->mlx, &render_frame, cfg);
	mlx_loop(cfg->mlx);
	mlx_terminate(cfg->mlx);
}

void	render_frame(void *param)
{
	t_config	*cfg;

	cfg = (t_config *)param;
	memset(cfg->img->pixels, 0,
		cfg->img->width * cfg->img->height * sizeof(uint32_t));
	update_player_position(cfg);
	raycasting(cfg);
}