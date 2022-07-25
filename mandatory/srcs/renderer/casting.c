/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/25 23:23:09 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

double	denormalize_angle(double angle)
{
	angle = remainder(angle - M_PI, 2 * M_PI);
	if (angle < 0)
		angle += M_PI * 2;
	return (angle);
}

void	get_txtr(t_map *map, double ray_angl)
{
	ray_angl = denormalize_angle(ray_angl);
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
}

void	project3d_assistant(t_map *map, t_p3d *p3d)
{
	p3d->proj_plan = ((WIDTH / 2) / tan(map->rndr->fov / 2.00));
	map->rndr->wall->arr_dist[p3d->i]
		*= cos(map->rndr->wall->arr_angl[p3d->i] - map->rndr->rot_angl);
	p3d->wall_proj_height = (CELL_SIZE / map->rndr->wall->arr_dist[p3d->i])
		* p3d->proj_plan;
	map->rndr->wall->wall_height = (int)p3d->wall_proj_height;
	p3d->top_pix = (int)(HEIGHT / 2) - (int)(p3d->wall_proj_height / 2);
	if (p3d->top_pix < 0 || p3d->top_pix > HEIGHT)
		p3d->top_pix = 0;
	p3d->botom_pix = (HEIGHT / 2) + (map->rndr->wall->wall_height / 2);
	if (p3d->botom_pix > HEIGHT || p3d->botom_pix < 0)
		p3d->botom_pix = HEIGHT;
	p3d->y = -1;
	while (++p3d->y < p3d->top_pix)
		map->mlx->img_data[(p3d->y * WIDTH + p3d->i)] = 0x87ceeb;
	if (map->rndr->wall->vert[p3d->i] == true)
		p3d->txtr_x = (int)map->rndr->wall->rays[p3d->i].y % 64;
	else
		p3d->txtr_x = (int)map->rndr->wall->rays[p3d->i].x % 64;
	get_txtr(map, map->rndr->wall->arr_angl[p3d->i]);
	p3d->y = p3d->top_pix;
}

void	project3d(t_map	*map)
{
	t_p3d	p3d;

	p3d.i = -1;
	while (++p3d.i < WIDTH)
	{
		project3d_assistant(map, &p3d);
		while (p3d.y < p3d.botom_pix)
		{
			if (map->rndr->wall->vert[p3d.i] == true)
				map->txtr->data = map->txtr->data_v;
			else
				map->txtr->data = map->txtr->data_h;
			p3d.dist_from_top = p3d.y + (map->rndr->wall->wall_height / 2)
				- (HEIGHT / 2);
			p3d.txtr_y = (int)(p3d.dist_from_top * ((float)CELL_SIZE
						/ (int)map->rndr->wall->wall_height));
			map->mlx->img_data[(p3d.y * WIDTH + p3d.i)]
				= map->txtr->data[(p3d.txtr_y * 64 + p3d.txtr_x)];
			p3d.y++;
		}
		p3d.y = p3d.botom_pix - 1;
		while (++p3d.y < HEIGHT)
			map->mlx->img_data[(p3d.y * WIDTH + p3d.i)] = 0x9b7653;
	}
}
