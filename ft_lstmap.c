/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:23:37 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/26 15:14:56 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_node;
	t_list	*new_head;
	void	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	new_head = NULL;
	while (tmp)
	{
		ptr = f(tmp -> content);
		new_node = ft_lstnew(ptr);
		if (!(new_node))
		{
			ft_lstclear(&new_head, del);
			del(ptr);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_node);
		tmp = tmp->next;
	}
	new_node = NULL;
	return (new_head);
}
