/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:30:07 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/23 18:52:52 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	put_pix_to_img(t_map *map, int x, int y, int clr)
{
	// int	*pixel;
	// exit_free_if(x > WIDTH, "x out of range",map);

	// if ( x >= WIDTH || y >= HEIGHT)
	// {
	// 	x = WIDTH - 2;
	// 	y = HEIGHT - 2;
	// }
	
	if (x > WIDTH)
		x = WIDTH;
	if (x < 0)
		x = 0;
	if (y > HEIGHT)
		y = HEIGHT;
	if (y < 0)
		y = 0;
	(void)clr;
	// map->mlx->img_data[y * WIDTH + x] = map->txtr->north_data[offy * CELL_SIZE + offx];
	// pixel = map->mlx->img_data + (y * map->mlx->size_line + x * (map->mlx->bpp / 8));
	map->mlx->img_data[y * WIDTH + x] = clr;
	// pixel = map->mlx->img_data + (y * WIDTH + x);
	// *(unsigned int *)pixel = 0xffffff;	
	// *(unsigned int *)pixel = clr;

}

