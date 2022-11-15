/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:07:26 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/15 12:39:37 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)ptr;
	i = 0;
	while (i < len)
	{
		tmp[i] = (unsigned char)value;
		i++;
	}
	return ((void *)ptr);
}
