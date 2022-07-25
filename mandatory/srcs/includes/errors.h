/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:44:15 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 00:03:59 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <parser.h>
# include <mlx.h>

void	exit_free_if(int cond, char *msg, t_map *map);
t_map	*validate_map(char *map_file);

#endif
