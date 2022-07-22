/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_drawers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 21:20:56 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <renderer.h>

void	bresenham(t_map *map, int x1, int y1, int clr)
{
 	int	x0;
	int	y0;
	x0 = map->rndr->pvec->x + 2;
	y0 = map->rndr->pvec->y + 2;
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

void	draw_square(t_map *map, int x, int y, int clr)
{
	for (int i = y; i < (y + 16); i++)
	{
		for (int j = x; j < (x + 16); j++)
			put_pix_to_img(map, j, i, clr);
	}
}

// void	draw_bottom_wall(t_map *map, double x, double y, int width, int height)
// {
// 	// int	x;
// 	// int	y;
	
// 	// x = map->rndr->pvec->x;
// 	// y = map->rndr->pvec->y;
// 	// while (y < (map->rndr->pvec->y + 4))
// 	// {
// 	// 	x = map->rndr->pvec->x;
// 	// 	while (x < (map->rndr->pvec->x + 4))
// 	// 	{
// 	// 		put_pix_to_img(map, x, y, 0x0000FF);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	double	prev_x;
// 	prev_x = x;
// 	double	x0;
// 	double	y0;
	
// 	x0 = x + width;
// 	y0 = y + height;
// 	while (y <= y0)
// 	{
// 		x = prev_x;
// 		while (x <= x0)
// 		{	
// 			put_pix_to_img(map, x, y, 0x66502e);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_top_wall(t_map *map, double x, double y, int width, int height)
// {
// 	// int	x;
// 	// int	y;
	
// 	// x = map->rndr->pvec->x;
// 	// y = map->rndr->pvec->y;
// 	// while (y < (map->rndr->pvec->y + 4))
// 	// {
// 	// 	x = map->rndr->pvec->x;
// 	// 	while (x < (map->rndr->pvec->x + 4))
// 	// 	{
// 	// 		put_pix_to_img(map, x, y, 0x0000FF);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	double	prev_x;
// 	prev_x = x;
// 	double	x0;
// 	double	y0;
	
// 	x0 = x + width;
// 	y0 = y + height;
// 	while (y <= y0)
// 	{
// 		x = prev_x;
// 		while (x <= x0)
// 		{	
// 			put_pix_to_img(map, x, y, 0xc6e2ff);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_rect(t_map *map, double x, double y, int width, int height)
{
	// int	x;
	// int	y;
	
	// x = map->rndr->pvec->x;
	// y = map->rndr->pvec->y;
	// while (y < (map->rndr->pvec->y + 4))
	// {
	// 	x = map->rndr->pvec->x;
	// 	while (x < (map->rndr->pvec->x + 4))
	// 	{
	// 		put_pix_to_img(map, x, y, 0x0000FF);
	// 		x++;
	// 	}
	// 	y++;
	// }
	double	prev_x;
	prev_x = x;
	double	x0;
	double	y0;
	
	x0 = x + width;
	y0 = y + height;
	while (y <= y0)
	{
		x = prev_x;
		while (x <= x0)
		{	
			put_pix_to_img(map, x, y, map->clr->clr);
			x++;
		}
		y++;
	}
}

void	draw_line(t_map	*map, double angle, int len)
{
	double	endx;
	double	endy;
	
	endx = (map->rndr->pvec->x + (4 / 2)) + cos(angle) * len;
	endy = (map->rndr->pvec->y + (4 / 2)) + sin(angle) * len;
	bresenham(map, (int)endx, (int)endy , 0x03B965);
}	