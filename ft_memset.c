/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:07:26 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/23 20:27:25 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		tmp[i] = (unsigned char)value;
		i++;
	}
	return ((void *)ptr);
}
