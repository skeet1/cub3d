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
	draw_player(map);
}
void	draw_player(t_map *map)
{
	int		i;

	i = 0;
	
	double	prev_x;
	double	x0;
	double	y0;
	
	x0 = (map->rndr->pvec->x * SCL_FAC);
	y0 = (map->rndr->pvec->y * SCL_FAC);
	prev_x = x0 ;
	while (y0 <= ((map->rndr->pvec->y * SCL_FAC) + PLY_SIZE))
	{
		x0 = prev_x;
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

void	draw_map(t_map *map, int flag)
{
	int		x;
	int		y;
	bool	p;
	int		i;
	int		j;

	p = false;
	y = 0;
	i = -1;
	while (map->map[++i])
	{
		x = 0;
		j = -1;
		while (map->map[i][++j])
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
		cast_rays(map);
		project3d(map);
	}
}

