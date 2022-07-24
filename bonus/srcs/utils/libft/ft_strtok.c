/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:16:43 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/04/21 21:51:51 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 ft_strtok - strtok implementation
	strtok is a function that splits a string into tokens based on a delimiter.
	It returns a pointer to the next token in the string.
	prototype: char *ft_strtok(char *str, const char *delim);
*/
#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saved_str;
	char		*token;
	int			i;
	int			j;
	int			k;

	if (str != NULL)
		saved_str = str;
	if (saved_str == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (saved_str[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (saved_str[i] == delim[j])
			{
				saved_str[i] = '\0';
				token = &saved_str[k];
				saved_str = &saved_str[i + 1];
				return (token);
			}
			j++;
		}
		i++;
	}
	token = &saved_str[k];
	saved_str = NULL;
	return (token);
}
