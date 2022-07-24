/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:29:54 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/05 14:01:38 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_doublen(const char **)
    * 
    * @description: this function computes the length of the double pointer. 
    * @param const char **double: pointer to a pointer to a string
    * @return: the length of the string
*/

#include "libft.h"

size_t  ft_doublen(char const **doub)
{
    size_t i;

    i = 0;
    while (doub[i])
        i++;
    return (i);
}
