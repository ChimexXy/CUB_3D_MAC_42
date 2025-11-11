/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:42:05 by mozahnou          #+#    #+#             */
/*   Updated: 2025/11/11 10:51:25 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "./../cub3d.h"

# define MOVE_SPEED 0.025
# define ROT_SPEED 0.03
# define WIN_W 1920
# define WIN_H 1080
# define CELL 40   // size of 1 map cell in pixels

typedef struct s_norm
{
	int	px;
	int	py;
	int	size;
	int	y;
	int	x;
	int	start_x;
	int	start_y;
}	t_norm;

//draw_map//
void	draw_map(t_config *cfg);
void	draw_player(t_config *cfg);
void	set_player_position(t_config *cfg);
void	draw_cell(t_config *cfg, int map_x, int map_y, uint32_t color);

//init_data//
void	init_player_flags(t_config *cfg);
void	init_player_direction(t_config *cfg, char c);
void	init_player_direction1(t_config *cfg, char c);
void	*ft_memset(void *b, int c, size_t len);

//key_mlx//
void	set_key_state(mlx_key_data_t key, t_config *cfg, int press);
void	handle_keys(mlx_key_data_t key, void *param);

//move//
int		check_point_wall(t_config *cfg, int mx, int my);
int		is_wall(t_config *cfg, double x, double y);
void	rotate(t_config *cfg, double angle);
void	apply_rotation(t_config *cfg);
void	apply_movement(t_config *cfg, double *nx, double *ny);

//raycasting//
void	raycasting(t_config *cfg);
void	cast_single_ray(t_config *cfg, int x);
void	calc_draw_bounds(double wall_dist, int *start, int *end);
double	calc_wall_dist(t_ray *ray);
void	perform_dda(t_config *cfg, t_ray *ray);

//raycasting2//
int		check_hit(t_config *cfg, t_ray *ray);
void	init_step_y(t_config *cfg, t_ray *ray);
void	init_step_x(t_config *cfg, t_ray *ray);
void	init_delta_dist(t_ray *ray);
void	init_ray_direction(t_config *cfg, int x, t_ray *ray);

//render//
void	update_player_position(t_config *cfg);
void	render_2d_map(t_config *cfg);
void	render_frame(void *param);

//win_mlx//
void	draw_vertical_line(t_config *cfg, int x, int start, int end);
int		init_mlx(t_config *cfg);

#endif
