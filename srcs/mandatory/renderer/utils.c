/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:43:53 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 15:14:51 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>


t_map  *add_dist(t_map *map, double value, double ray_angl)
{
    double  *new_arr;
    double  *new_ray_angles;
    size_t i;
    exit_free_if(!(new_arr = malloc(sizeof(*new_arr) * (map->rndr->dist->len + 1))), "Error:\n\tmalloc failed\n", map);
    exit_free_if(!(new_ray_angles = malloc(sizeof(*new_ray_angles) * (map->rndr->dist->len + 1))), "Error:\n\tmalloc failed\n", map);
    i = 0;

    if (map->rndr->dist->len >= WIDTH)
        map->rndr->dist->len = 0;
    while (i < map->rndr->dist->len)
    {
        new_arr[i] = map->rndr->dist->arr[i];
        new_ray_angles[i] = map->rndr->dist->ray_angles[i];
        i++;
    }
    new_arr[i] = value;
    new_ray_angles[i] = ray_angl;

    map->rndr->dist->len += 1;
    // free(map->rndr->dist->arr);
    map->rndr->dist->arr = new_arr;
    map->rndr->dist->ray_angles = new_ray_angles;
    return (map);

}