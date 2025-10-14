/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:38:12 by mozahnou          #+#    #+#             */
/*   Updated: 2025/10/14 13:34:13 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_key_state(mlx_key_data_t key, t_config *cfg, int press)
{
	if (key.key == MLX_KEY_W)
		cfg->player.move_up = press;
	if (key.key == MLX_KEY_S)
		cfg->player.move_down = press;
	if (key.key == MLX_KEY_A)
		cfg->player.move_left = press;
	if (key.key == MLX_KEY_D)
		cfg->player.move_right = press;
	if (key.key == MLX_KEY_LEFT)
		cfg->player.rotate_left = press;
	if (key.key == MLX_KEY_RIGHT)
		cfg->player.rotate_right = press;
}

void	handle_keys(mlx_key_data_t key, void *param)
{
	t_config	*cfg;
	int			press;

	cfg = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(cfg->mlx);
	press = (key.action == MLX_PRESS || key.action == MLX_REPEAT);
	if (key.action == MLX_RELEASE)
		press = 0;
	set_key_state(key, cfg, press);
}
