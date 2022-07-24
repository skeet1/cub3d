/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_add_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:29:07 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/25 11:58:23 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:
		- add a node to the ast
	@param: 
		- t_AST *root: the root of the ast
		- t_AST *node: the node to add
	@return:
		- t_AST *: the root of the ast
	@IMPORTANT:
		- the node is added to the right of the last right leaf of the ast
*/

#include "libft.h"

t_AST	*ft_ast_add_node(t_AST *root, char *sym, void *content)
{
	t_AST	*tmp;

	if (!root)
		return (ft_ast_new_node(sym, content));
	tmp = root;
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = ft_ast_new_node(sym, content);
	return (root);
}
