/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_add_nodei.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 08:58:22 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/27 09:32:56 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief add node at a specific index of the ast 
 * @note the index is a char * containing 0 and 1 , which should be used 
 * * as a guide to traverse the ast 1 for right and 0 for left
 * @IMPORTANT: the function should be 
 * * called unless the ast contains at least one node
 * @param *root: the root of the ast
 * @param *sym: the symbol of the node
 * @param *content: the content of the node
 * @param where: the index of the node 
 * 
 * @return the root of the ast
*/

#include "libft.h"

t_AST	*ft_ast_add_nodei(t_AST *root, char *sym, void *content, char *where)
{
	t_AST	*tmp;
	size_t	i;
	size_t	len;

	if (!root)
		return (ft_ast_new_node(sym, content));
	tmp = root;
	i = 0;
	len = ft_strlen(where);
	while (tmp && i < len - 1)
	{
		if (where[i] == '1')
			tmp = tmp->right;
		else
			tmp = tmp->left;
		i++;
	}
	if (where[i] == '1')
		tmp->right = ft_ast_new_node(sym, content);
	else
		tmp->left = ft_ast_new_node(sym, content);
	return (root);
}
