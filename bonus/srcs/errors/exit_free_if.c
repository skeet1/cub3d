/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:43:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 23:09:11 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errors.h>

void	free_mlx(t_map *map)
{
	mlx_destroy_image(map->mlx->mlx, map->mlx->img);
	ft_sfree(map->mlx->img_data);
	ft_sfree(map->mlx->img);
	ft_sfree(map->mlx->win);
	ft_sfree(map->mlx->mlx);
	ft_sfree(map->mlx);
}

void	exit_free_if( int cond, char *msg, t_map *map)
{
	if (cond)
	{
		if (map)
		{
			if (map->rndr)
				kill(map->rndr->music, SIGKILL);
			ft_doubfree((void **)map->map, \
			ft_2darr_len((const char **)map->map));
			ft_sfree(map->clr);
			ft_sfree(map->txtr);
			free_mlx(map);
			ft_sfree(map->rndr->pvec);
			ft_sfree(map->rndr->wall);
			ft_sfree(map->rndr->wall->step);
			ft_sfree(map->rndr->proj);
			ft_doubfree((void **)(map->rndr->doors->map_cpy),
				ft_2darr_len((const char **)map->rndr->doors->map_cpy));
			mlx_destroy_window(map->mlx->mlx, map->mlx->win);
		}
		if (msg)
			ft_putendl_fd(msg, 2);
		exit(EXIT_FAILURE);
	}
}
