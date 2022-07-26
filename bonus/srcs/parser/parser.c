/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:42:07 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 22:57:38 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <renderer.h>

int	main( int argc, char **argv)
{
	char	*map_file;
	t_map	*map;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./wolf3d <map_file>", 2);
		exit(EXIT_FAILURE);
	}
	map_file = argv[1];
	map = validate_map(map_file, argv);
	play_sound(map);
	renderer(map);
	return (0);
}
