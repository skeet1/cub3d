/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safeFree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:57:00 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/09 11:31:19 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
    ft_safeFree:
        @description:
            - free a pointer if it is not NULL 
        @param:
            - void *ptr: pointer to free
        @return:
            - void
*/

#include "libft.h"

void    ft_safeFree(void *ptr)
{
    if (ptr)
    {
        free(ptr);
        ptr = NULL;
    }   
}