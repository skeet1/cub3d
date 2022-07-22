/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validfname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:08:23 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/11 13:15:10 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ft_validfname:
        @description:
            - check if the string is a valid filename
        @param:
            - char *name : string to check
        @return:
            - bool : true if valid, false otherwise
        @note:
            - if name is NULL, return false        

*/

#include "libft.h"


bool    ft_validfname(char *name)
{
    int i;
    
    int j;
    char *invalid_chars[] = {
        "\\", "/",  "?", "\"", "<", ">", "|", "#", "&" "$",\
        "`", "'", NULL,
    }; 
    i = 0;
    
    
    if (!name)
        return (false);
    while (name[i])
    {
        j = 0;
        while (invalid_chars[j])
        {
            if (ft_strncmp(name + i, invalid_chars[j], 1) == 0)
                return (false);
            j = j + 1;
        }
        i = i + 1;
    }
    return (true);
}
