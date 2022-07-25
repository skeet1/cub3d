/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/25 23:23:42 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

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

void	cast_rays(t_map *map)
{
	double	ray_angl;
	int		i;

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
