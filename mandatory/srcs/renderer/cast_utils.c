/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/25 23:54:08 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	found_txtr(bool check, double *x, double *y)
{
	if (check)
	{
		*x = INT_MAX;
		*y = INT_MAX;
	}
}

void	cast_v_assistant(t_map *map, double ray_angl, t_cast *cst)
{
	exit_free_if(!(cst->tmp = malloc(sizeof(*cst->tmp))),
		"Error:\n\tmalloc failed\n", map);
	exit_free_if(!(cst->tmp->wall = malloc(sizeof(*cst->tmp->wall))),
		"Error:\n\tmalloc failed\n", map);
	exit_free_if(!(cst->tmp->step = malloc(sizeof(*cst->tmp->step))),
		"Error:\n\tmalloc failed\n", map);
	cst->startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	cst->starty = map->rndr->pvec->y + (PLY_SIZE / 2);
	cst->xinter = floor(cst->startx / CELL_SIZE) * CELL_SIZE;
	ray_angl = normalize_ang(ray_angl);
	if (ray_is_right(ray_angl))
		cst->xinter += CELL_SIZE;
	cst->yinter = cst->starty + (cst->xinter - cst->startx) * tan(ray_angl);
	cst->tmp->step->x = CELL_SIZE;
	if (!ray_is_right(ray_angl))
		cst->tmp->step->x *= -1;
	cst->tmp->step->y = CELL_SIZE * tan(ray_angl);
	if (!ray_is_down(ray_angl) && cst->tmp->step->y > 0)
		cst->tmp->step->y *= -1;
	else if (ray_is_down(ray_angl) && cst->tmp->step->y < 0)
		cst->tmp->step->y *= -1;
	cst->nwall_x = cst->xinter;
	cst->nwall_y = cst->yinter;
	if (!ray_is_right(ray_angl))
		cst->nwall_x -= 1;
}

t_wall	*cast_v(t_map *map, double ray_angl)
{
	t_cast	cst;

	cast_v_assistant(map, ray_angl, &cst);
	while (cst.nwall_x >= 0 && cst.nwall_x <= (CELL_SIZE * map->w)
		&& cst.nwall_y >= 0 && cst.nwall_y <= (CELL_SIZE * map->h))
	{
		cst.index_x = cst.nwall_x / CELL_SIZE;
		cst.index_y = cst.nwall_y / CELL_SIZE;
		if (map->map[cst.index_y][cst.index_x] == '1')
		{
			if (!ray_is_right(ray_angl))
				cst.nwall_x += 1;
			map->txtr->found_v = true;
			cst.tmp->wall->x = cst.nwall_x;
			cst.tmp->wall->y = cst.nwall_y;
			break ;
		}
		else
		{
			cst.nwall_x += cst.tmp->step->x;
			cst.nwall_y += cst.tmp->step->y;
		}
	}
	found_txtr(!map->txtr->found_v, &cst.tmp->wall->x, &cst.tmp->wall->y);
	return (cst.tmp);
}

void	cast_h_assistant(t_map *map, double ray_angl, t_cast *cst)
{
	exit_free_if(!(cst->tmp = malloc(sizeof(*cst->tmp))),
		"Error:\n\tmalloc failed\n", map);
	exit_free_if(!(cst->tmp->wall = malloc(sizeof(*cst->tmp->wall))),
		"Error:\n\tmalloc failed\n", map);
	exit_free_if(!(cst->tmp->step = malloc(sizeof(*cst->tmp->step))),
		"Error:\n\tmalloc failed\n", map);
	cst->startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	cst->starty = map->rndr->pvec->y + (PLY_SIZE / 2);
	ray_angl = normalize_ang(ray_angl);
	cst->yinter = floor(cst->starty / CELL_SIZE) * CELL_SIZE;
	if (ray_is_down(ray_angl))
		cst->yinter += CELL_SIZE;
	cst->xinter = cst->startx + ((cst->yinter - cst->starty) / tan(ray_angl));
	cst->tmp->step->y = CELL_SIZE;
	if (!ray_is_down(ray_angl))
		cst->tmp->step->y *= -1;
	cst->tmp->step->x = CELL_SIZE / tan(ray_angl);
	if (ray_is_right(ray_angl) && cst->tmp->step->x < 0)
		cst->tmp->step->x *= -1;
	else if (!ray_is_right(ray_angl) && cst->tmp->step->x > 0)
		cst->tmp->step->x *= -1;
	cst->nwall_x = cst->xinter;
	cst->nwall_y = cst->yinter;
	if (!ray_is_down(ray_angl))
		cst->nwall_y -= 1;
}

t_wall	*cast_h(t_map *map, double ray_angl)
{
	t_cast	cst;

	cast_h_assistant(map, ray_angl, &cst);
	while (cst.nwall_x >= 0 && cst.nwall_x <= (CELL_SIZE * map->w)
		&& cst.nwall_y >= 0 && cst.nwall_y <= (CELL_SIZE * map->h))
	{
		cst.index_x = cst.nwall_x / CELL_SIZE;
		cst.index_y = cst.nwall_y / CELL_SIZE;
		if (map->map[cst.index_y][cst.index_x] == '1')
		{
			if (!ray_is_down(ray_angl))
				cst.nwall_y += 1;
			map->txtr->found_h = true;
			cst.tmp->wall->x = cst.nwall_x;
			cst.tmp->wall->y = cst.nwall_y;
			break ;
		}
		else
		{
			cst.nwall_x += cst.tmp->step->x;
			cst.nwall_y += cst.tmp->step->y;
		}
	}
	found_txtr(!map->txtr->found_h, &cst.tmp->wall->x, &cst.tmp->wall->y);
	return (cst.tmp);
}
