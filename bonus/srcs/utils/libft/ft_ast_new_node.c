/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_new_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:24:34 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/25 11:57:30 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   @description:
		- create a new node for the ast
	@param:
		- char *sym: the symbol of the node
		- void *content: the content of the node
	@return:
		- t_ast_node *: the new node
		- NULL: if the allocation failed
	@note:
		- the node left and right leaves are set to NULL
*/

#include "libft.h"

t_AST	*ft_ast_new_node(char *sym, void *content)
{
	t_AST	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->sym = ft_strdup(sym);
	node->content = content;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
