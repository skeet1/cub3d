/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:33:30 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/04/21 22:46:24 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Convert int into a string */

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
