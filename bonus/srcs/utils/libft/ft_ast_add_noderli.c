/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_add_noderli.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:20:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/26 13:54:58 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  add a node to the right of the left node at index i
 * @note   
 * @param  *root: 
 * @param  *sym: 
 * @param  *content: 
 * @param  i: index of the node in the ast
 * @retval root of the ast 
 */

t_AST	*ft_ast_add_nodelri(t_AST *root, char *sym, void *content, size_t i)
{
	t_AST	*tmp;

	if (!root)
		return (ft_ast_new_node(sym, content));
	tmp = root;
	while (tmp && i)
	{
		tmp = tmp->left;
		i--;
	}
	tmp->right = ft_ast_new_node(sym, content);
	return (root);
}
