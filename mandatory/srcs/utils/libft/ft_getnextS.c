/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:11:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/10 14:54:55 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
    ft_getnextS:
        @description:
            - get the next space char in str
        @param:
            - char *str: string to search
        @return:
            - char *: next space char
            - if no space char, return NULL
        @note:
            - if str is NULL, return NULL
*/

#include "libft.h"

char    *ft_getnextS(char *S)
{
    int i;

    i = 0;
    if (!S)
        return (NULL);
    while (S[i] && S[i] != ' ')
        i = i + 1;
    return (S + i);
}