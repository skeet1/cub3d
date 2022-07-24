/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:57:00 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/11 13:22:57 by ren-nasr         ###   ########.fr       */
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

void    ft_sfree(void *ptr)
{
    if (ptr)
    {
        free(ptr);
        ptr = NULL;
    }   
}