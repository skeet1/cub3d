/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:52:32 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/25 11:11:16 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:
		- count the number of occurences of a char * in a char **
	@param:
		- char **doub: the doubing to be searched
		- char *to_find: the doubing to be found
	@return:
		- int: the number of occurences
		- NULL: if the doubing to be found is NULL
	@note:
		- the function is case sensitive
		- the function is recursive
		- if to_find is NULL, the function returns len(doub)
*/

#include "libft.h"

int	ft_doubcount(const char **doub, char *to_find)
{
	size_t	i;
	int		count;

	if (!doub || !to_find)
		return (0);
	if (!*doub)
		return (0);
	if (!*to_find)
		return (ft_strlen((const char *)doub));
	i = 0;
	count = 0;
	while (doub[i])
	{
		if (ft_strncmp(doub[i], to_find, ft_strlen((const char *)to_find)) == 0)
			count++;
		i++;
	}
	return (count);
}
