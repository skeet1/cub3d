/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/24 19:06:19 by ren-nasr         ###   ########.fr       */
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

		int index_x = x / CELL_SIZE;
		int index_y = y / CELL_SIZE;
		
		if (map->map[index_y][index_x] == '1')
			return (true);
		if (i == 0)
			incx += PLY_SIZE;
		else if (i == 1)
			incy += PLY_SIZE;
		else if (i == 2)
			incx -= PLY_SIZE;
	}
	return (false);
}

void	move_right(t_map *map)
{
	// printf("right : x =%lf, y = %lf\n", map->rndr->pvec->x, map->rndr->pvec->y);
	double	x;
	double	y;
	int		index_x;
	int		index_y;

	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + cos(map->rndr->rot_angl + degtorad(90));
		y = map->rndr->pvec->y + sin(map->rndr->rot_angl + degtorad(90));

		index_x = (x + incx) / CELL_SIZE;
		index_y = (y + incy) / CELL_SIZE;
		
		if (map->map[index_y][index_x] == '1')
			return ;
		if (i == 0)
			incx += PLY_SIZE;
		else if (i == 1)
			incy += PLY_SIZE;
		else if (i == 2)
			incx -= PLY_SIZE;
	}
	
	map->rndr->pvec->x = x;
	map->rndr->pvec->y = y;
}
void	move_left(t_map *map)
{
	// printf("left : x = %lf, y = %lf\n", map->rndr->pvec->x, map->rndr->pvec->y);
	double	x;
	double	y;
	int		index_x;
	int		index_y;

	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + cos(map->rndr->rot_angl - degtorad(90));
		y = map->rndr->pvec->y + sin(map->rndr->rot_angl - degtorad(90));

		index_x = (x                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               + incx) / CELL_SIZE;
		index_y = (y + incy) / CELL_SIZE;
		// printf("left inside: x: %lf, y: %lf, i_x : %d, i_y: %d\n", x+ incx, y+ incy, index_x, index_y);
		if (map->map[index_y][index_x] == '1')
			return ;
		if (i == 0)
			incx += PLY_SIZE;
		else if (i == 1)
			incy += PLY_SIZE;
		else if (i == 2)
			incx -= PLY_SIZE;
	}
	map->rndr->pvec->x = x;
	map->rndr->pvec->y = y;
}

void	move(t_map *map, int mv)
{
	if (mv == LEFT)
		map->rndr->turn_dir = -1;
	else if (mv == RIGHT)
		map->rndr->turn_dir = 1;
	if (mv == LEFT || mv == RIGHT)
		update_ang(map);
	if (mv == KEY_W)
		map->rndr->walk_dir = 1;
	else if (mv == KEY_S)
		map->rndr->walk_dir = -1;
	if (mv == KEY_A)
	{
		move_left(map);
	}
	if (mv == KEY_D)
	{
		move_right(map);
	}
	if (mv == KEY_S || mv == KEY_W)
	{
		if (inside_wall(map->rndr->pvec->x, map->rndr->pvec->y, map))
			return;
		else 
			update_pos(&map->rndr->pvec->x, &map->rndr->pvec->y, map);
	}
}




int	mouse_hook(int x, int y, t_map *map)
{
	// keep of last position of x and decrease or increase angle of rotation based on difference between last and current position of x
	(void)y;
	static	int last_x;
	if (x > WIDTH || x < 0)
		return (0);
	map->rndr->turn_spd = get_turn_spd(last_x, x);
	
	x = get_mouse_x(map);
	
	if (x - last_x > 0)
		move(map, RIGHT);
	else if (x - last_x < 0)
		move(map, LEFT);
	map->rndr->turn_spd = degtorad(10);
	update_screen(map);
	last_x = x;
	return (0);
}

int	move_player(int key_code, t_map *map)
{

	move(map, key_code);
	if (key_code == EXIT)
		exit_free_if(true, NULL, NULL);
	update_screen(map);
	return (0);

}
