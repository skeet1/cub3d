/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:43:53 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 01:58:30 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>


t_map  *add_dist(t_map *map, double value)
{
    double  *new_arr;
    size_t i;
    if (map->rndr->dist->i >= 1920)
        map->rndr->dist->i = 0;
    exit_free_if(!(new_arr = malloc(sizeof(*new_arr) * (map->rndr->dist->i + 1))), "Error:\n\tmalloc failed\n", map);
    i = 0;
    while (i < map->rndr->dist->i)
    {
        new_arr[i] = map->rndr->dist->arr[i];
        i++;
    }
    map->rndr->dist->i++;
    new_arr[i] = value;
    // free(map->rndr->dist->arr);
    map->rndr->dist->arr = new_arr;
    return (map);
}