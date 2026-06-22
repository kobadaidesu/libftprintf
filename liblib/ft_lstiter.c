/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/05/03 00:01:33 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int main(void)
// {
//     t_list *node1 = ft_lstnew(ft_strdup("hello"));
//     t_list *node2 = ft_lstnew(ft_strdup("world"));
//     node1->next = node2;

//     ft_lstiter(node1, f_print);
//     // 出力：
//     // hello
//     // world

//     ft_lstiter(node1, f_toupper);
//     ft_lstiter(node1, f_print);
//     // 出力：
//     // HELLO
//     // WORLD
// }