/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:48:44 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/25 11:59:06 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:
		- free the ast 
	@param: 
		- t_AST *root: the root of the ast
	@return:
		- void
	@IMPORTANT:
		- the content of the nodes is not freed, as it is void * it can a simple char * 
			or some complex struct, you can't tell,so you can't free it.
	@note:
		- the freeing is done recursively
*/

#include "libft.h"

void	ft_free_ast(t_AST *root)
{
	if (root)
	{
		ft_sfree(root->sym);
		ft_free_ast(root->left);
		ft_free_ast(root->right);
		free(root);
	}
}
