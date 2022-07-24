/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:08:04 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/04/26 14:09:35 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Allocates (with malloc()) and returns a substring
from the string ’s’. The substring begins at index ’start’ and is of
maximum size ’len’. */

char *ft_substr(const char *str, unsigned int start, size_t end)
{
	char *substr;
	size_t len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (start > len)
		return (ft_strdup(""));
	if (end > len)
		end = len;
	substr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, end - start + 1);
	return (substr);
}