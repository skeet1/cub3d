/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:43:15 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/15 10:46:37 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    @description:
        - expand to the actual value of env variable and return it.
    
    @param:
        - char **envs: the set of env variables
        - char *env_name: the name of the env variable
    @return:
        - char *: the value of the env variable
        - NULL: if the env variable is not found
    @Complexity:
        - O(n)
*/

#include "libft.h"


char    *ft_envexp(char **envs, char *env_name)
{
    if (!envs || !env_name)
        return (NULL);
    if (!ft_envexist(envs, env_name))
        return (NULL);
    return (ft_strdup(ft_getenv(envs, env_name)));
}