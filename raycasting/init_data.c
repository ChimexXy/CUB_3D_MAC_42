/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:38:10 by mozahnou          #+#    #+#             */
/*   Updated: 2025/11/07 18:55:56 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_player_flags(t_config *cfg)
{
	cfg->player.move_up = 0;
	cfg->player.move_down = 0;
	cfg->player.move_left = 0;
	cfg->player.move_right = 0;
	cfg->player.rotate_left = 0;
	cfg->player.rotate_right = 0;
}

void	init_player_direction(t_config *cfg, char c)
{
	if (c == 'N')
	{
		cfg->dir_x = 0.0;
		cfg->dir_y = -1.0;
		cfg->plane_x = 0.66;
		cfg->plane_y = 0.0;
	}
	else if (c == 'S')
	{
		cfg->dir_x = 0.0;
		cfg->dir_y = 1.0;
		cfg->plane_x = -0.66;
		cfg->plane_y = 0.0;
	}
	init_player_direction1(cfg, c);
}

void	init_player_direction1(t_config *cfg, char c)
{
	if (c == 'E')
	{
		cfg->dir_x = 1.0;
		cfg->dir_y = 0.0;
		cfg->plane_x = 0.0;
		cfg->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		cfg->dir_x = -1.0;
		cfg->dir_y = 0.0;
		cfg->plane_x = 0.0;
		cfg->plane_y = -0.66;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	p;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)b;
	p = (unsigned char)c;
	while (i < len)
	{
		ptr[i] = p;
		i++;
	}
	return (ptr);
}
