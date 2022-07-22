/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:12:43 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/09 14:06:12 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* function allocates sufficient memory for a copy of the string s1,
 does the copy, and returns a pointer to it */

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i = i + 1;
	}
	s2[i] = '\0';
	return (s2);
}
