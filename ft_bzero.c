/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:33:11 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/27 13:24:40 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		tmp[i] = 0;
		i++;
	}
}
