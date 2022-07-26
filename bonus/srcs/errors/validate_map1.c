/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:10:16 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errors.h>

/** checks:
 * if the map is not surronded by walls (one's) return an error. done
 * if the map content is seperated by lines return an error,  done
 * if the map content is not the last return an error , done
 * if any of the sixth values is not starting or/and have a 
 * invalid identifier return an error, done
 * check validity of path to texture, done
 * if there's not sixth values return an error, done
**/

void	check_is_indetifier(t_map *map, char *line)
{
	if (is_identifier(line))
	{
		if (ft_strchr(line, '/'))
			map = get_texture(line, map);
		else
			map = get_color(line, map);
	}
}

void	is_map_assist(t_map	*map, int fd, char *line)
{
	line = check_line(line);
	exit_free_if(!(line = ft_strtrim(line, " ")),
		"Error:\n\tmalloc failed", map, 1);
	ft_doubfree((void **)map->map, 0);
	map->map = malloc(sizeof(char *) * 2);
	map->map[0] = line;
	map->map[1] = NULL;
	map = get_map(fd, map);
	exit_free_if(!map, "Error:\n\tInvalid map", map, 1);
}

void	get_color_assist(t_map *map, char c, int color)
{
	if (c == 'F')
		map->clr->floor = color;
	else if (c == 'C')
		map->clr->ceiling = color;
	map->clr_txtr_count.x += 1;
}

void	exit_if_assist(t_map *map, char *map_file, int *fd, char **env)
{
	exitif((*fd = open(map_file, O_RDONLY)) == -1, "Error:\n\tinvalid map file");
	exitif((ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", 4) != 0),
		"Error:\n\tinvalid map file. expected extension is .cub");
	exitif(ft_filelcount(map_file) < 7, "Error:\n\tMissing values in map file");
	exitif(!map_is_last(map_file),
		"Error:\n\tMap content should be at the end of the file");
	map->env = ft_doubdup(env);
	map->map = ft_file_to_2darr(map_file);
	map->map = get_new_map(map->map);
	exit_free_if(!check_map(map->map), "Error:\n\tinvalid map", map, 1);
}

t_map	*validate_map(char *map_file, char **env)
{
	char		*line;
	int			fd;
	t_map		*map;

	map = init();
	exit_if_assist(map, map_file, &fd, env);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_isempty(line))
		{
			free_and_gnl(&line, fd);
			continue ;
		}
		check_is_indetifier(map, line);
		if (is_map(line))
		{
			is_map_assist(map, fd, line);
			break ;
		}
		free_and_gnl(&line, fd);
	}
	exit_free_if(map->clr_txtr_count.x != 2 || \
	map->clr_txtr_count.y != 4, "Error:\n\t invalid arguments in map", map, 1);
	return (ft_sfree(line), close(fd), map);
}
