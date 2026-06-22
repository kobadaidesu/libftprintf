/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/05/03 00:01:33 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}

// int	main(void)
// {
// 	t_list	*lst;
//
// 	lst = ft_lstnew(ft_strdup("A"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("B")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("C")));
// 	ft_lstclear(&lst, free);
// 	printf("lst after clear: %s\n", lst ? "not null" : "NULL");
// }
