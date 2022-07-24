/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_drawers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/23 22:15:09 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <renderer.h>

void	bresenham(t_map *map, int x1, int y1, int clr)
{
 	int	x0;
	int	y0;
	x0 = map->rndr->pvec->x + (PLY_SIZE / 2);
	y0 = map->rndr->pvec->y + (PLY_SIZE / 2);
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;
	for(;;){
		put_pix_to_img(map, x0, y0, clr);
    		if (x0==x1 && y0==y1) break;
    		e2 = err;
    		if (e2 >-dx) { err -= dy; x0 += sx; }
    		if (e2 < dy) { err += dx; y0 += sy; }
 	 }
}

void	draw_square(t_map *map, int x, int y, int clr, long size)
{
	for (int i = y; i < (y + size); i++)
	{
		for (int j = x; j < (x + size); j++)
			put_pix_to_img(map, j, i, clr);
	}
}

void	draw_rect(t_map *map, double x, double y, int width, int height)
{
	
	double	prev_x;
	prev_x = x;
	double	x0;
	double	y0;
	
	x0 = x + width;
	y0 = y + height;
		while (x <= x0)
		{
			while (y <= y0)
			{
				map->txtr->north_vec->y = (y - map->rndr->wall->wall_top_pixel) * (CELL_SIZE / map->rndr->wall->wall_height);
				int pixel = map->txtr->north_data[(int)(map->txtr->north_vec->y * map->txtr->size_line + map->txtr->north_vec->x * (map->txtr->bpp / 8))];
				put_pix_to_img(map, x, y, pixel);
			y++;
		}

		x++;
	}
}


void	draw_line(t_map	*map, double angle, int len)
{
	double	endx;
	double	endy;
	
	endx = (map->rndr->pvec->x + (PLY_SIZE / 2)) + cos(angle) * len;
	endy = (map->rndr->pvec->y + (PLY_SIZE / 2)) + sin(angle) * len;
	bresenham(map, (int)endx, (int)endy , 0x03B965);
}	
