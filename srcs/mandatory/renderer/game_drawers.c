/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:12 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 02:19:04 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	draw_player(t_map *map)
{
		
	draw_rect(map, map->rndr->pvec->x, map->rndr->pvec->y, PLY_SIZE, PLY_SIZE);
}

void	draw_map(t_map *map, int flag) {
	int	x;
	int	y;
	bool	p;

	p = false;
	x = 0;  
	y = 0;
	for (int i = 0; map->map[i]; i++)
	{
		x = 0;
		for (int j = 0; map->map[i][j]; j++)
		{
			if (map->map[i][j] == '1' )
				draw_square(map, x, y, 0xFF0000);
			else
				draw_square(map, x , y, 0xFFFFFFF);
			if (map->map[i][j] == 'N' && !flag)
			{
				p = true;
				map->rndr->pvec->x = x;
				map->rndr->pvec->y = y;
			}			
			x += CELL_SIZE;
		}
		y += CELL_SIZE;
	}
	if (flag == 1 || p == true)
	{
		draw_player(map);
		cast_rays(map);
		printf("%lf %lf %lf %lf %lf\n", map->rndr->dist->arr[100], map->rndr->dist->arr[200], map->rndr->dist->arr[300], map->rndr->dist->arr[400], map->rndr->dist->arr[500]);
		project3d(map);
	}
}

