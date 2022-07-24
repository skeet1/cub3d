/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_2darr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:49:34 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 19:55:23 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief store a file's content in a 2d array and return it
 * @param file path to file
 * @return char** 2d array of file's content or NULL if error
 */

char    **ft_file_to_2darr(char *file)
{
    char    **arr;
    char    *line;
    int     fd;
    int     i;

    i = 0;
    if (!file)
        return (NULL);
    if (!(arr = malloc(sizeof(char *) * (ft_filelcount(file) + 1))))
        return (NULL);
    if ((fd = open(file, O_RDONLY)) == -1)
        return (NULL);
    
    line = get_next_line(fd);
    while (line)
    {
        arr[i] = line;
        line = get_next_line(fd);
        i++;
    }    
    arr[i] = NULL;
    close(fd);
    return (arr);
}

