/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubconcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:39:05 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/13 19:55:14 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:
		- concatenates char ** into a new string using a delimiter
	@param:
		- char **str: string to concatenate
		- char *delim: delimiter
	
	@return:
		- char *: the concatenated string
		- if str is NULL, return NULL
		- if str is empty, return an empty string
	@note:
		- if delim is NULL, there should be no delimiter
*/

#include "libft.h"

char	*ft_doubconcat(char **str, char *delim)
{
	size_t	i;
	char	*ret;
	size_t	len;

	i = 0;
	if (!str)
		return (NULL);
	if (!str[0])
		return (ft_strdup(""));
	ret = ft_strdup("");
	len = ft_doublen((const char **)str);
	while (str[i])
	{
		ret = ft_strjoin(ret, str[i]);
		if (delim && i < len - 1)
			ret = ft_strjoin(ret, delim);
		if (!ret)
			ft_doubfree((void **)str, i);
		i++;
	}
	ft_doubfree((void **)str, 0);
	return (ret);
}
