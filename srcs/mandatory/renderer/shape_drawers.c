/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_drawers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/23 10:43:58 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	bresenham(t_map *map, int x1, int y1, int clr)
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int e2;

	x0 = map->rndr->pvec->x + 2;
	y0 = map->rndr->pvec->y + 2;
	dx = abs(x1 - x0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	dy = abs(y1 - y0);
	if (y0 < y1)
		sy = 1;
	else
		sy = -1; 
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	while (1)
	{
		put_pix_to_img(map, x0, y0, clr);
		if (x0==x1 && y0==y1)
			break;
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

void	draw_rect(t_map *map, double x, double y, int width, int height)
{
	double	prev_x;
	double	x0;
	double	y0;

	prev_x = x;
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
	bresenham(map, (int)endx, (int)endy, 0x03B965);
}	
