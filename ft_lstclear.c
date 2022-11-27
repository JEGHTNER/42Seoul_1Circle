/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:04:36 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/27 13:30:40 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*current;

	if (!lst || !del)
		return ;
	if (!(*lst))
		return ;
	current = (*lst);
	while (current)
	{
		tmp = current;
		current = current -> next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
