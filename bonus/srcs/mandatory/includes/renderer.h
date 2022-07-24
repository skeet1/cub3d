/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:20:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/24 10:59:36 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RENDERER_H
# define RENDERER_H  

# include <mlx.h>
# include <parser.h>
# include <errors.h>
# include <math.h>
# include <stdlib.h>
#include <limits.h>
# define SCL_FAC 1
# define CELL_SIZE 64

// # define SPEED 2
# define PLY_SIZE 4 * SCL_FAC
# define NUM_RAYS WIDTH / 2

// key codes
# define KEY_W 13   
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define RIGHT 124
# define LEFT 123
# define EXIT 53

void    renderer(t_map *map);
void    render_map(t_map *map);
void    rasterize_vector(int x1, int y1, int x2, int y2, int c, t_map *map);

// initilization stuff 
t_map	*new_img(t_map *map);
t_map	*init_mlx(t_map *map);
t_map   *init_rndr(t_map *map);

// math utils
double  degtorad(double degree);

// mlx utils 
void	put_pix_to_img(t_map *map, int x, int y, int clr);


// drawers 
void	draw_rect(t_map *map, double x, double y, int height, int width);
void	draw_square(t_map *map, int x, int y, int clr, long size);
void	draw_map(t_map *map, int flag);
void	draw_player(t_map *map);
void	draw_line(t_map *map, double angle, int len);
void	draw_minimap(t_map	*map);


// void	draw_rect2(t_map *map, double x, double y, int width, int height);


// moves
int     move_player(int key_code, t_map *map);
void	update_ang(t_map *map);
void	bresenham(t_map *map, int x1, int y1, int clr);
void	update_pos(double *x, double *y, t_map *map);

// rays
void	cast_rays(t_map *map);


// 3d projection 
void	project3d(t_map	*map);

// normalize ang
double  normalize_ang(double angle);

// double arr distance 
t_map  *add_dist(t_map *map, double value, double ray_angl);
t_map   *add_ray_coor(t_map *map, double x, double y);

// draw top the wall 
void	draw_top_wall(t_map *map, double x, double y, int width, int height);
void	draw_bottom_wall(t_map *map, double x, double y, int width, int height);


// utils
bool    is_ne(double ray_angl);
bool    is_nw(double ray_angl);
bool    is_sw(double ray_angl);
bool    is_se(double ray_angl);
bool	ray_is_down(double angle);
bool	ray_is_right(double angle);
double	normalize_ang(double angle);
#endif
