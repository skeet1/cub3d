/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darr_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:52:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 20:52:40 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_dobubtrim.c trim double pointers char ** from char * set
 * it returns the double pointer array
 *  or NULL if the pointer is NULL
 */

#include "libft.h"

char	**ft_2darr_trim(char **doub, char *set)
{
	size_t	i;
	char	*hold;

	i = 0;
	if (!doub || !set)
		return (NULL);
	while (doub[i])
	{
		if (ft_strnstr(doub[i], set, ft_strlen(doub[i])))
		{
			hold = doub[i];
			doub[i] = ft_strtrim(doub[i], set);
			ft_sfree(hold);
		}
		i++;
	}
	return (doub);
}
