/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:04:39 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/22 21:04:46 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int main(void)
// {
//     t_list *lst;
//     t_list *node1 = ft_lstnew("A");
//     t_list *node2 = ft_lstnew("B");
//     t_list *node3 = ft_lstnew("C");
//     lst = NULL;
//     ft_lstadd_front(&lst, node3);
//     ft_lstadd_front(&lst, node2);
//     ft_lstadd_front(&lst, node1);
//     printf("リストのサイズ: %d\n", ft_lstsize(lst));
//     printf("空リストのサイズ: %d\n", ft_lstsize(NULL));
//     return (0);
// }
