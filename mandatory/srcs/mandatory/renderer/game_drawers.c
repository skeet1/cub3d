/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:12 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/23 20:21:59by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>
void	draw_rays(t_map *map)
{
	size_t		i;

	i = 0;	
	
	while (i < map->rndr->wall->rys_len)
	{
		
		bresenham(map, map->rndr->wall->rays[i].x * SCL_FAC , map->rndr->wall->rays[i].y * SCL_FAC ,  0x03B965);
		i++;
	}
}


void	draw_minimap(t_map	*map)
{
	size_t	x;
	size_t	y;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (map->map[i])
	{
		x = 0;
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				draw_square(map, x, y, 0xFF0000, CELL_SIZE * SCL_FAC);
			else
				draw_square(map, x , y, 0xFFFFFFF, CELL_SIZE  * SCL_FAC);
			x += (CELL_SIZE * SCL_FAC);
			j++;
		}
		i++;
		y += (CELL_SIZE * SCL_FAC);
	}
	draw_rays(map);
	draw_player(map);
}

// }


void	draw_player(t_map *map)
{	
	// draw_rect(map, map->rndr->pvec->x , map->rndr->pvec->y, PLY_SIZE, PLY_SIZE);

	// drawing a cicle as a player
	// int		x;
	// int		y;
	int		i;


	// x = map->rndr->pvec->x;
	// y = map->rndr->pvec->y;
	i = 0;
	
	double	prev_x;
	double	x0;
	double	y0;
	
	x0 = (map->rndr->pvec->x * SCL_FAC ) + (PLY_SIZE / 2);
	y0 = (map->rndr->pvec->y * SCL_FAC) + (PLY_SIZE / 2);
	prev_x = x0 ;
	while (y0 <= ((map->rndr->pvec->y * SCL_FAC) + PLY_SIZE))
		{
			// x = prev_x;
			x0 = prev_x;
			// if we're at the edge of the intersection move the player u
			while (x0 <= ((map->rndr->pvec->x * SCL_FAC)+ PLY_SIZE))
			{	
				put_pix_to_img(map, x0,y0  , 0xB0B0B0);
				x0++;
			}
			y0++;
}
}
		


void	init_angl(t_map *map, char c)
{
	if (c == 'N')
		map->rndr->rot_angl = degtorad(270);
	if (c == 'W')
		map->rndr->rot_angl = degtorad(180);
	if (c == 'S')
		map->rndr->rot_angl = degtorad(90);
	if (c == 'E')
		map->rndr->rot_angl = degtorad(0);
}

bool	isplayer(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	return (false);
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
			if (isplayer(map->map[i][j]) && !flag)
			{
				init_angl(map, map->map[i][j]);
				p = true;
				map->rndr->pvec->x = x;
				map->rndr->pvec->y = y;
				break;
			}			
			x += CELL_SIZE;
		}
		y += CELL_SIZE;
	}
	if (flag == 1 || p == true)
	{
		// draw_player(map);
		cast_rays(map);	
		// for (size_t i = 0; i < map->rndr->dist->len; i++)
		// {
		// 	printf("dist: %lf\n", map->rndr->dist->arr[i]);
		// }
		project3d(map);
		// draw_minimap(map);
	}
}

