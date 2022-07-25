/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/25 23:50:00 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	cast(t_map *map, double ray_angl)
{	
	t_start_cast	cast;

	cast.wall_h = cast_h(map, ray_angl);
	cast.wall_v = cast_v(map, ray_angl);
	cast.startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	cast.starty = map->rndr->pvec->y + (PLY_SIZE / 2);
	cast.distanceh = get_dist(cast.startx, cast.wall_h->wall->x,
			cast.starty, cast.wall_h->wall->y);
	cast.distancev = get_dist(cast.startx, cast.wall_v->wall->x,
			cast.starty, cast.wall_v->wall->y);
	if (cast.distanceh <= cast.distancev)
	{
		cast.end = cast.wall_h;
		map->txtr->found_h = true;
		map->txtr->found_v = false;
		map = add_dist(map, cast.distanceh, ray_angl);
	}
	else
	{
		cast.end = cast.wall_v;
		map->txtr->found_v = true;
		map->txtr->found_h = false;
		map = add_dist(map, cast.distancev, ray_angl);
	}
	map = add_ray_coor(map, cast.end->wall->x, cast.end->wall->y);
}
