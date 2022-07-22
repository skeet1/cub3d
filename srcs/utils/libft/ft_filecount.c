/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:51:04 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/09 20:12:46 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @breif: count how many lines ina a file
 * @param: 
 * 	- char *file: path to file 
 * @return: on success read return >= 0 count or -1 in error
 **/
#include "libft.h"

size_t	ft_filecount( char	*file)
{
	int	fd;
	size_t	count = 0;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	return (count);
}
