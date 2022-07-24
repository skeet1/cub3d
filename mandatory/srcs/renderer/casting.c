/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/24 16:41:02 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>


void	draw_column(t_map *map, double x, double y, double wall_proj_height)
{
	draw_rect(map, x, y, 1, wall_proj_height);
}

void y_drawing(t_map *map, int y0, int y1, int x)
{
	
	// int	pixel;
	// printf("y0: %d	y1; %d", y0, y1);
	
	int	top_pix;
	// if (top_pix < 0)
	// 	top_pix = 0;
	int	i;
	top_pix = y0;
	
	while (y0 < y1)
	{
		int  dist_from_top = y0 + (map->rndr->wall->wall_height / 2) - (HEIGHT / 2);
	
		int	offy = dist_from_top * ((float)CELL_SIZE / (int)map->rndr->wall->wall_height);
		int	offset = (offy * CELL_SIZE) + (int)map->txtr->north_vec->x;
		map->mlx->img_data[(y0 * WIDTH + x)] = map->txtr->north_data[offset];
		y0 += 1;
	}
	
	i = 0;

	
}
double	denormalize_angle(double angle)
{

	// denormalize angle
	angle = remainder(angle - M_PI,  2 * M_PI);
	if (angle < 0)
		angle += M_PI * 2;
	
	return (angle);
}

void	get_txtr(t_map *map, double ray_angl)
{
	// int	i;
	
	// i = 0;
	// while (i < WIDTH)
	// {
	ray_angl = denormalize_angle(ray_angl);
	// denormilizing the angle first to avoid issues with the texture
	// ray_angl = denormalize_angle(ray_angl);
		if (!ray_is_down(ray_angl) && ray_is_right(ray_angl))
		{
			map->txtr->data_h = map->txtr->south_data;
			map->txtr->data_v = map->txtr->west_data;
		}
		if (!ray_is_down(ray_angl) && !ray_is_right(ray_angl))
		{
			map->txtr->data_h = map->txtr->south_data;
			map->txtr->data_v = map->txtr->east_data;
		}
		if (ray_is_down(ray_angl) && ray_is_right(ray_angl))
		{
			map->txtr->data_h = map->txtr->north_data;
			map->txtr->data_v = map->txtr->west_data;
		}
		if (ray_is_down(ray_angl) && !ray_is_right(ray_angl))
		{
			map->txtr->data_h = map->txtr->north_data;
			map->txtr->data_v = map->txtr->east_data;
		}
		// if (ray_is_down))
	// if (is_ne(ray_angl))
	// {
	// 	// map->txtr->data  = map->txtr->north_data;
	// 		if (ray_is_down(ray_angl))
	// 			map->txtr->data_h = map->txtr->north_data;
	// 		else 
	// 			map->txtr->data_h = map->txtr->south_data;
	// 		map->txtr->data_v = map->txtr->west_data;
	// }
	// if (is_nw(ray_angl))
	// {
	// 		if (ray_is_down(ray_angl))
	// 			map->txtr->data_h = map->txtr->north_data;
	// 		else 
	// 			map->txtr->data_h = map->txtr->south_data;
	// 		map->txtr->data_v = map->txtr->east_data;
	// 		// map->txtr->data_h = map->txtr->south_data;
	// 	// map->txtr->data = map->txtr->west_data;

	// }
	// if (is_sw(ray_angl))
	// {
	// 	// if (map->rndr->wall->vert[i] == true)
	// 	// map->txtr->data = map->txtr->south_data;
		
	// 		map->txtr->data_v = map->txtr->east_data;
	// 	// // else
	// 		map->txtr->data_h = map->txtr->north_data;
	// }
	//  if (is_se(ray_angl))
	// {
	// 	// map->txtr->data = map->txtr->east_data;
	// 		map->txtr->data_v = map->txtr->west_data;
	// 		map->txtr->data_h = map->txtr->north_data;
	
	// }
}
void	project3d(t_map	*map)
{
	int	i;
	// double	x;
	// double	y;
	int	botom_pix;
	double	proj_plan;
	double	wall_proj_height;
	int	top_pix;
	i = 0;
		
	while (i < WIDTH)
	{
		// get_txtr(map, map->rndr->wall->arr_angl[i]);
		proj_plan = ((WIDTH / 2) / tan(map->rndr->fov / 2.00));
		map->rndr->wall->arr_dist[i] *= cos(map->rndr->wall->arr_angl[i] - map->rndr->rot_angl);
		wall_proj_height = (CELL_SIZE / map->rndr->wall->arr_dist[i]) * proj_plan;
		map->rndr->wall->wall_height = (int)wall_proj_height;
		top_pix = (int)(HEIGHT / 2) - (int)(wall_proj_height / 2);
		if (top_pix < 0 || top_pix > HEIGHT)
			top_pix = 0;
		botom_pix = (HEIGHT / 2) + (map->rndr->wall->wall_height / 2);
		if (botom_pix > HEIGHT || botom_pix < 0)
			botom_pix = HEIGHT;
		for (int y = 0; y < top_pix; y++)
		{
			map->mlx->img_data[(y * WIDTH + i)] = 0x87ceeb;
			// map->mlx->img_data[(y * WIDTH + i)] = map->clr->ceiling;
		}
		int	txtr_x;
		if (map->rndr->wall->vert[i] == true)
			txtr_x = (int)map->rndr->wall->rays[i].y % 64;
		else
			txtr_x = (int)map->rndr->wall->rays[i].x % 64;
				

		// render the wall from top pixel to botom pixel
			get_txtr(map, map->rndr->wall->arr_angl[i]);
		for (int y = top_pix; y < botom_pix; y++)
		{
			
			if (map->rndr->wall->vert[i] == true)
				map->txtr->data = map->txtr->data_v;
			else
				map->txtr->data = map->txtr->data_h;
			int	dist_from_top = y + (map->rndr->wall->wall_height / 2) - (HEIGHT / 2);
			int	txtr_y = (int)(dist_from_top * ((float)CELL_SIZE / (int)map->rndr->wall->wall_height));
		
			
			map->mlx->img_data[(y * WIDTH + i)] = map->txtr->data[(txtr_y * 64 + txtr_x)];
		}
		
		// set the floor color
		for (int y = botom_pix; y < HEIGHT; y++)
		{
			map->mlx->img_data[(y * WIDTH + i)] = 0x9b7653;
			// map->mlx->img_data[(y * WIDTH + i)] = map->clr->floor;
		}
		
		//
	
		i++;
	}
	
	// draw_minimap(map);
	
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
	// angle = (angle + degree) % 360;
	// if (angle < 0)
	// 	angle = 360 + angle;
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
	double	startx;
	double	starty;
	
	
	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->step = malloc(sizeof(*tmp->step))), "Error:\n\tmalloc failed\n", map);
	startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	starty = map->rndr->pvec->y + (PLY_SIZE / 2);
	
	xinter = floor(startx / CELL_SIZE) * CELL_SIZE;
	ray_angl = normalize_ang(ray_angl);
	if (ray_is_right(ray_angl))
		xinter += CELL_SIZE;
	yinter = starty + (xinter - startx) * tan(ray_angl);
	
	tmp->step->x = CELL_SIZE;
	if (!ray_is_right(ray_angl))
		tmp->step->x *= -1;
	tmp->step->y = CELL_SIZE * tan(ray_angl);
	if (!ray_is_down(ray_angl) && tmp->step->y > 0)
		tmp->step->y *= -1;
	else if (ray_is_down(ray_angl) && tmp->step->y < 0)
		tmp->step->y *= -1;

	nwall_x = xinter;
	nwall_y = yinter;
	
	if (!ray_is_right(ray_angl))
		nwall_x -= 1;
	while (nwall_x >= 0 && nwall_x <= (CELL_SIZE * map->w) && nwall_y >= 0 && nwall_y <= (CELL_SIZE * map->h))
	{
		index_x = nwall_x / CELL_SIZE;
		index_y = nwall_y / CELL_SIZE;
		
		if (map->map[index_y][index_x] == '1')
		{
			if (!ray_is_right(ray_angl))
				nwall_x += 1;
			map->txtr->found_v = true;
			tmp->wall->x = nwall_x;
			tmp->wall->y = nwall_y;
			
			break;
		}
		else {
			nwall_x += tmp->step->x;
			nwall_y += tmp->step->y;
		}
	}
	if (!map->txtr->found_v)
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
	
		
	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->step = malloc(sizeof(*tmp->step))), "Error:\n\tmalloc failed\n", map);
	startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	starty = map->rndr->pvec->y + (PLY_SIZE / 2);

	
	ray_angl = normalize_ang(ray_angl);	
	yinter = floor(starty / CELL_SIZE) * CELL_SIZE;
	if (ray_is_down(ray_angl))
		yinter += CELL_SIZE;		
	xinter = startx + ((yinter - starty) / tan(ray_angl));
	tmp->step->y = CELL_SIZE;
	if (!ray_is_down(ray_angl))
		tmp->step->y *= -1;
	tmp->step->x = CELL_SIZE / tan(ray_angl);
	if (ray_is_right(ray_angl) && tmp->step->x < 0)
		tmp->step->x *= -1;
	else if (!ray_is_right(ray_angl) && tmp->step->x > 0)
		tmp->step->x *= -1;
	
	nwall_x = xinter;
	nwall_y = yinter;
	
	if (!ray_is_down(ray_angl))
		nwall_y -= 1;
	while (nwall_x >= 0 && nwall_x <= (CELL_SIZE * map->w) && nwall_y >= 0 && nwall_y <= (CELL_SIZE * map->h))
	{
		index_x = nwall_x / CELL_SIZE;
		index_y = nwall_y / CELL_SIZE;
		if (map->map[index_y][index_x] == '1')
		{
			if (!ray_is_down(ray_angl))
				nwall_y += 1;
			map->txtr->found_h = true;
			tmp->wall->x = nwall_x;
			tmp->wall->y = nwall_y;
			
			break;
		}
		else {
			
			nwall_x += tmp->step->x;
			nwall_y += tmp->step->y;
		}
	}
	if (!map->txtr->found_h)
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
	// double	ray_angl_tmp;

	// ray_angl_tmp = ray_angl;	
	wall_h = cast_h(map, ray_angl);
	wall_v = cast_v(map, ray_angl);
	

	double startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	double starty = map->rndr->pvec->y  + (PLY_SIZE / 2); 
	
	
	double	distanceh = get_dist( startx, wall_h->wall->x, starty, wall_h->wall->y);
	double	distancev = get_dist( startx, wall_v->wall->x, starty, wall_v->wall->y);

	if ( distanceh <= distancev)
	{
		end = wall_h;
		map->txtr->found_h = true;
		map->txtr->found_v = false;
		
		map = add_dist(map, distanceh, ray_angl);
	}
	else
	{
		end = wall_v;
		map->txtr->found_v = true;
		map->txtr->found_h = false;
		map = add_dist(map, distancev, ray_angl);
	}
	
	map = add_ray_coor(map, end->wall->x, end->wall->y);
	
	
}

void	cast_rays(t_map *map)
{
	double	ray_angl;
	int	i;

	i = 0;
	ray_angl = map->rndr->rot_angl - (map->rndr->fov / 2);
	while (i < WIDTH)
	{
		map->txtr->found_v = false;
		map->txtr->found_h = false;
		cast(map, ray_angl);
		if (map->txtr->found_v)
		{
			map->rndr->wall->vert[i] = true;
			map->rndr->wall->horiz[i] = false;
		}
		else
		{
			map->rndr->wall->vert[i] = false;
			map->rndr->wall->horiz[i] = true;
		}
		ray_angl += (map->rndr->fov / WIDTH);
		i++;
	}
}
