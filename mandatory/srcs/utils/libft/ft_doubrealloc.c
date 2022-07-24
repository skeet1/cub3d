/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubrealloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:14:23 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/10 16:40:35 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

    ft_doubrealloc:
        @description:
            - reallocate a pointer to pointer 
        @params:
            - void **ptr: pointer to pointer to reallocate
            - int size: size to reallocate
        @return:
            - newly allocated pointer to pointer
            - NULL if failed
*/

#include "libft.h"

void    **ft_doubrealloc(void **ptr, size_t size)
{
    void **new;
    size_t i;
    
    i = 0;
    if (!ptr)
        return (NULL);
    if (!size)
        return (ptr);
    if (!(new = malloc(sizeof(void *) * size + 1)))
        return (NULL);
    while(ptr[i])
    {
        new[i] = ft_strdup(ptr[i]);
        if (!new[i])
            ft_doubfree(new, i);
        i++;
    }
    new[size] = NULL;
    ft_doubfree(ptr, 0);
    return (new);
}
