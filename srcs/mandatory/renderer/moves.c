/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/23 14:23:03 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	update_pos(double *x, double *y, t_map *map)
{
	int	move_step;

	move_step = map->rndr->walk_dir * map->rndr->walk_spd;

	*x += (cos(map->rndr->rot_angl) * move_step);
	*y += (sin(map->rndr->rot_angl) * move_step);
}

void	update_ang(t_map *map) 
{
	map->rndr->rot_angl += (map->rndr->turn_dir * map->rndr->turn_spd);
}

bool	inside_wall(double x, double y, t_map *map)
{
	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + incx;
		y = map->rndr->pvec->y + incy;
		update_pos(&x, &y, map);

		int index_x = x / 16;
		int index_y = y / 16;
		
		if (map->map[index_y][index_x] == '1')
			return (true);
		if (i == 0)
			incx += 4;
		else if (i == 1)
			incy += 4;
		else if (i == 2)
			incx -= 4;
	}
	return (false);
}

void	move_right(t_map *map)
{
	double	x;
	double	y;
	int		index_x;
	int		index_y;

	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + cos(map->rndr->rot_angl + degtorad(90));
		y = map->rndr->pvec->y + sin(map->rndr->rot_angl + degtorad(90));

		index_x = (x + incx) / 16;
		index_y = (y + incy) / 16;
		
		if (map->map[index_y][index_x] == '1')
			return ;
		if (i == 0)
			incx += 4;
		else if (i == 1)
			incy += 4;
		else if (i == 2)
			incx -= 4;
	}

	map->rndr->pvec->x = x;
	map->rndr->pvec->y = y;
}
void	move_left(t_map *map)
{
	double	x;
	double	y;
	int		index_x;
	int		index_y;

	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + cos(map->rndr->rot_angl - degtorad(90));
		y = map->rndr->pvec->y + sin(map->rndr->rot_angl - degtorad(90));

		index_x = (x + incx) / 16;
		index_y = (y + incy) / 16;
		
		if (map->map[index_y][index_x] == '1')
			return ;
		if (i == 0)
			incx += 4;
		else if (i == 1)
			incy += 4;
		else if (i == 2)
			incx -= 4;
	}
	map->rndr->pvec->x = x;
	map->rndr->pvec->y = y;
}

void	update_one_direction(double *direction, int x, t_map *map)
{
	int	move_step;

	move_step = map->rndr->walk_dir * map->rndr->walk_spd;

	if (x)
		*direction += (cos(map->rndr->rot_angl) * (move_step));
	else
		*direction += (sin(map->rndr->rot_angl) * (move_step));
}

bool	possible_y_move(double x, double y, t_map *map)
{
	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + incx;
		y = map->rndr->pvec->y + incy;
		update_one_direction(&x, 1, map);
		int index_x = x / 16;
		int index_y = y / 16;
		
		printf("x : %lf , y : %lf , i_x : %d, i_y : %d\n", map->rndr->pvec->x, map->rndr->pvec->y, index_x, index_y);
		if (map->map[index_y][index_x] == '1')
			return (true);
		if (i == 0)
			incx += 4;
		else if (i == 1)
			incy += 4;
		else if (i == 2)
			incx -= 4;
	}
	return (false);
}

bool	possible_x_move(double x, double y, t_map *map)
{
	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + incx;
		y = map->rndr->pvec->y + incy;
		update_one_direction(&y, 0, map);
		int index_x = x / 16;
		int index_y = y / 16;
		// printf("x : %lf , y : %lf , i_x : %d, i_y : %d\n", map->rndr->pvec->x, map->rndr->pvec->y, index_x, index_y);
		if (map->map[index_y][index_x] == '1')
			return (true);
		if (i == 0)
			incx += 4;
		else if (i == 1)
			incy += 4;
		else if (i == 2)
			incx -= 4;
	}
	return (false);
}

void	move(t_map *map, int mv)
{
	if (mv == LEFT)
		map->rndr->turn_dir = -1;
	else if (mv == RIGHT)
		map->rndr->turn_dir = 1;
	if (mv == LEFT || mv == RIGHT)
	{
		update_ang(map);
	}
	if (mv == KEY_W)
		map->rndr->walk_dir = 1;
	else if (mv == KEY_S)
		map->rndr->walk_dir = -1;
	if (mv == KEY_A)
		move_left(map);
	if (mv == KEY_D)
		move_right(map);
	// static int i = 0;
	if (mv == KEY_S || mv == KEY_W)
	{
		if (inside_wall(map->rndr->pvec->x, map->rndr->pvec->y, map))
		{
			// if (possible_y_move(map->rndr->pvec->x, map->rndr->pvec->y, map))
			// {
			// 	printf("posible move y  %d\n", i++);
			// 	printf("x: %lf, y = %lf\n", map->rndr->pvec->x, map->rndr->pvec->y);
			// 	update_one_direction(&map->rndr->pvec->y, 0, map);
			// }
			// else if (possible_x_move(map->rndr->pvec->x, map->rndr->pvec->y, map))
			// {
			// 	printf("posible move x %d\n", i++);
			// 	printf("x: %lf, y = %lf\n", map->rndr->pvec->x, map->rndr->pvec->y);
			// 	update_one_direction(&map->rndr->pvec->x, 1, map);
			// }
			return;
		}
		else 
			update_pos(&map->rndr->pvec->x, &map->rndr->pvec->y, map);
	}
}

int	move_player(int key_code, t_map *map)
{
	move(map, key_code);
	if (key_code == EXIT)
		red_cross(map);
	mlx_clear_window(map->mlx->mlx, map->mlx->win);
	map = new_img(map);
	draw_map(map, 1);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
	return (0);

}
