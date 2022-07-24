/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:22:43 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/06/05 12:28:00 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  add a new element to a doubly linked list
 * @note   
 * @param  **arr: 
 * @param  *content: 
 * @retval modified array
 */

char	**ft_doubadd(char **arr, char *content)
{
	size_t	len;

	len = ft_doublen((const char **)arr);
	arr = (char **)ft_doubrealloc((void **)arr, len + 1);
	arr[len] = ft_strdup(content);
	return (arr);
}
