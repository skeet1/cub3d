/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intternary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:36:02 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/13 11:37:38 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    @description:
        - if condition is true, return first argument, else return second argument
    @params:
        - int condition: condition to check
        - int first: first argument to return
        - int second: second argument to return
    @return:
        - first or second argument
*/

#include "libft.h"

int ft_intternary(int condition, int first, int second)
{
    if (condition)
        return (first);
    return (second);
}
