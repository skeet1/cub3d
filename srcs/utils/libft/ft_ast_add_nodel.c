/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_add_nodel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:36:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/05/26 12:38:10 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @brief add node to left of the last left leaf of the ast  
 * @note  the function is recursive
 * @param  *root: the root of the ast
 * @param  *sym: the symbol of the node
 * @param  *content: the content of the node
 * @retval the root of the ast
 */

#include "libft.h"

t_AST   *ft_ast_add_nodel(t_AST *root, char *sym, void *content)
{
    t_AST   *tmp;

    if (!root)
        return (ft_ast_new_node(sym, content));
    tmp = root;
    while (tmp->left)
        tmp = tmp->left;
    tmp->left = ft_ast_new_node(sym, content);
    return (root);
}
