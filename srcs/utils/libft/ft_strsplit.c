/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:51:23 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 20:04:06 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 *  Split a string into an array of strings using a delimiter.
 * @param doub 
 * A pointer to the string to split.
 * @param delim 
 * A pointer to the delimiter.
 * @return char** 
 * A pointer to the array of strings.
 * @complexity: 80's Horror 
 */

#include "libft.h"

char	**ft_strsplit(char const *s, char *delim)
{
	char	**ret;
	int		j;
	size_t	i;
	size_t	k;
	size_t	l;
	size_t	trigger;

	ret = malloc(sizeof(char *));
	k = 0;
	i = 0;
	l = 0;
	trigger = 0;
	while (s[i])
	{
		j = 0;
		if (i == ft_strlen(s) - 1)
		{
			ret = (char **)ft_2darr_realloc((void **)ret, k + 1);
			ret[k] = ft_substr(s, l, i + 1);
			k++;
		}
		if (s[i] != delim[j])
			trigger = 1;
		if (s[i] == delim[j] && trigger)
		{
			while (s[i] == delim[j])
			{
				i++;
				j++;
			}
			if (delim[j] == '\0')
			{
				ret = (char **)ft_2darr_realloc((void **)ret, k + 1);
				ret[k] = ft_substr(s, l, i - ft_strlen(delim));
				k++;
				l = i;
				trigger = 0;
			}
		}
		else
			i++;
	}
	return (ret);
}
