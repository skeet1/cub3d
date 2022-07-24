/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:34:54 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/06/05 09:17:37 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief  check is a char is a space
 * @note   
 * @param  c: 
 * @retval 1 if it is, 0 if not
 */

#include "libft.h"

bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}