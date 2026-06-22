/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/05/03 00:01:33 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
//     t_list *lst = NULL;
//     ft_lstadd_front(&lst, ft_lstnew("A"));
//     ft_lstadd_front(&lst, ft_lstnew("B"));
//     ft_lstadd_front(&lst, ft_lstnew("C"));
//     while (lst)
//     {
//         printf("[%s]\n", (char *)lst->content);
//         lst = lst->next;
//     }
//     return (0);
// }
