/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 21:28:37 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	draw_column(t_map *map, double x, double y, double wall_proj_height)
{
	map->clr->clr = map->clr->ceiling;
	draw_rect(map, x, 0, 1, 1080 - y);
	map->clr->clr = 0xffbc9d;
	draw_rect(map, x, y, 1, wall_proj_height);
	map->clr->clr = map->clr->floor;
	draw_rect(map, x, y + wall_proj_height, 1, 1080 - y - wall_proj_height);
}

void	project3d(t_map	*map)
{
	int	i;
	double	x;
	double	y;
	double	wall_proj_height;
	double	proj_plan;

	i = 0;
	// for (size_t i =0 ; i < map->rndr->dist->len; i++)
	// 	printf("dist: %lf\n", map->rndr->dist->arr[i]);	
	while (i < WIDTH)
	{
		// proj_plan = (WIDTH / 2) / tan(map->rndr->fov / 2);
		proj_plan = ((1920 / 2.00) / tan(map->rndr->fov / 2.00));
		map->rndr->wall->arr_dist[i] *= cos(map->rndr->wall->arr_angl[i] - map->rndr->rot_angl);
		wall_proj_height = (16 / map->rndr->wall->arr_dist[i]) * proj_plan;
		x = i * 1;
		y = (1080 / 2.0) - (wall_proj_height / 2.0);

		draw_column(map, x, y, wall_proj_height);
		// map->clr->clr = map->clr->ceiling;
		// draw_rect(map, x, 0, 1, 1080 - y);
		// map->clr->clr = 0xffbc9d;
		// draw_rect(map, x, y, 1, wall_proj_height);
		// map->clr->clr = map->clr->floor;
		// draw_rect(map, x, y + wall_proj_height, 1, 1080 - y - wall_proj_height);
		i++;
	}
	draw_minimap(map);
	// draw_rect(map, 100, 0, 100, 500);
};

double	get_dist(double x0, double x1, double y0, double y1)
{
	return (sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))));
}
bool	ray_is_down(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (true);
	return (false);	
}


bool	ray_is_right(double angle)
{
	if (angle < (M_PI / 2) || angle > (1.5 * M_PI))
		return (true);
	return (false);
}

double	normalize_ang(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

t_wall	*cast_v(t_map *map, double ray_angl)
{
	double	xinter;
	double	yinter;
	int		index_x;
	int		index_y;
	double	nwall_x;
	double	nwall_y;
	t_wall	*tmp;
	bool	found;
	double	startx;
	double	starty;
	
	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->step = malloc(sizeof(*tmp->step))), "Error:\n\tmalloc failed\n", map);
	startx = map->rndr->pvec->x + (4 / 2);
	starty = map->rndr->pvec->y + (4 / 2);
	
	found = false;
	xinter = floor(startx / 16) * 16;
	ray_angl = normalize_ang(ray_angl);
	if (ray_is_right(ray_angl))
		xinter += 16;
	yinter = starty + (xinter - startx) * tan(ray_angl);
	
	tmp->step->x = 16;
	if (!ray_is_right(ray_angl))
		tmp->step->x *= -1;
	tmp->step->y = 16 * tan(ray_angl);
	if (!ray_is_down(ray_angl) && tmp->step->y > 0)
		tmp->step->y *= -1;
	else if (ray_is_down(ray_angl) && tmp->step->y < 0)
		tmp->step->y *= -1;

	nwall_x = xinter;
	nwall_y = yinter;
	
	if (!ray_is_right(ray_angl))
		nwall_x -= 1;
	while (nwall_x >= 0 && nwall_x <= (16 * map->w) && nwall_y >= 0 && nwall_y <= (16 * map->h))
	{
		index_x = nwall_x / 16;
		index_y = nwall_y / 16;
		
		if (map->map[index_y][index_x] == '1')
		{
			if (!ray_is_right(ray_angl))
				nwall_x += 1;
			found = true;
			tmp->wall->x = nwall_x;
			tmp->wall->y = nwall_y;
			
			break;
		}
		else {
			nwall_x += tmp->step->x;
			nwall_y += tmp->step->y;
		}
	}
	if (!found)
	{
		tmp->wall->x = __INT_MAX__;
		tmp->wall->y = __INT_MAX__;
	}
	return (tmp);	
}

t_wall	*cast_h(t_map *map, double ray_angl)
{
	double	xinter;
	double	yinter;
	int		index_x;
	int		index_y;
	double	nwall_x;
	double	nwall_y;
	
	
	double	startx;
	double	starty;

	t_wall	*tmp;
	bool	found;
	
	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->step = malloc(sizeof(*tmp->step))), "Error:\n\tmalloc failed\n", map);
	startx = map->rndr->pvec->x + 2;
	starty = map->rndr->pvec->y + 2;

	
	ray_angl = normalize_ang(ray_angl);	
	found = false;	
	yinter = floor(starty / 16) * 16;
	if (ray_is_down(ray_angl))
		yinter += 16;		
	// xinter = map->rndr->pvec->x + (yinter - map->rndr->pvec->y) / tan(ray_angl);
	xinter = startx + ((yinter - starty) / tan(ray_angl));
	// xinter = startx + (yinter - starty) / tan(ray_angl);
	tmp->step->y = 16;
	if (!ray_is_down(ray_angl))
		tmp->step->y *= -1;
	tmp->step->x = 16 / tan(ray_angl);
	if (ray_is_right(ray_angl) && tmp->step->x < 0)
		tmp->step->x *= -1;
	else if (!ray_is_right(ray_angl) && tmp->step->x > 0)
		tmp->step->x *= -1;
	
	nwall_x = xinter;
	nwall_y = yinter;
	
	if (!ray_is_down(ray_angl))
		nwall_y -= 1;
	while (nwall_x >= 0 && nwall_x <= (16 * map->w) && nwall_y >= 0 && nwall_y <= (16 * map->h))
	{
		index_x = nwall_x / 16;
		index_y = nwall_y / 16;
		if (map->map[index_y][index_x] == '1')
		{
			if (!ray_is_down(ray_angl))
				nwall_y += 1;
			found = true;
			tmp->wall->x = nwall_x;
			tmp->wall->y = nwall_y;
			// printf("x : %lf and y: %lf is inside a wall horizon\n", nwall_x, nwall_y);
			// printf("index: map[%d][%d]\n", (int)(nwall_x  / 16), (int)(nwall_x / 16));
			// draw_point(map, nwall_x, nwall_y, 0x6633AA);
			break;
		}
		else {
			// printf("x : %lf and y: %lf is not inside a wall horizon\n", xinter, yinter);
			// printf("index: map[%d][%d]\n", (int)(yinter  / 16), (int)(xinter / 16));	
			nwall_x += tmp->step->x;
			nwall_y += tmp->step->y;
		}
	}
	if (!found)
	{
		tmp->wall->x = __INT_MAX__;
		tmp->wall->y = __INT_MAX__;
	}
	return (tmp);
}


void	cast(t_map *map, double ray_angl)
{	
	t_wall	*wall_h;
	t_wall	*wall_v;
	t_wall	*end;
	wall_h = cast_h(map, ray_angl);
	wall_v = cast_v(map, ray_angl);
	// printf("distance hori: %lf\n", get_dist(map->rndr->pvec->x, wall_h->wall->x, map->rndr->pvec->y, wall_h->wall->y));
	// printf("distance ver: %lf\n", get_dist(map->rndr->pvec->x, wall_v->wall->x, map->rndr->pvec->y, wall_v->wall->y));
	

	double startx = map->rndr->pvec->x + (16 / 2);
	double starty = map->rndr->pvec->y  + (16 / 2); 
	// // double	endx = wall_h->wall->x + (16 / 2);
	
	double	distanceh = get_dist( startx, wall_h->wall->x, starty, wall_h->wall->y);
	double	distancev = get_dist( startx, wall_v->wall->x, starty, wall_v->wall->y);

	if ( distanceh <= distancev)
	{
		end = wall_h;
		map = add_dist(map, distanceh, ray_angl);
	}
	else
	{
		end = wall_v;
		map = add_dist(map, distancev, ray_angl);
	}
	// for (size_t i = 0; i <= map->rndr->dist->i; i++)
	// {
	// 	printf("distance: %lf\n", map->rndr->dist->arr[i]);
	// }
	// map->rndr->dist = add_dist(map, )
	// end = cast_v(map, ray_angl);
	// if (end->wall->x == INT_MAX || end->wall->y == INT_MAX)
	// {
	// 	printf("value is int max\n");
	// 	exit(1);
	// }
	// if (wall_h->wall->x == INT_MAX || wall_h->wall->y == INT_MAX)
	// 	end = wall_v;
	// if (wall_v->wall->y == INT_MAX || wall_v->wall->y == INT_MAX)
	// 	end = wall_h;
	// printf("end x: %lf and y: %lf\n", end->wall->x, end->wall->y);
	// bresenham(map, end->wall->x, end->wall->y, 0x00FF00);
	map = add_ray_coor(map, end->wall->x, end->wall->y);
	// printf("ray_length in minimap: %zu\n", map->rndr->wall->rys_len);
	// printf("endx: %lf and endy: %lf\n", end->wall->x, end->wall->y);
	
}

void	cast_rays(t_map *map)
{
	double	ray_angl;
	int	i;

	i = 0;
	ray_angl = map->rndr->rot_angl - (map->rndr->fov / 2);
	while (i < WIDTH)
	{
		cast(map, ray_angl);
		ray_angl += (map->rndr->fov / WIDTH);
		i++;
	}
}