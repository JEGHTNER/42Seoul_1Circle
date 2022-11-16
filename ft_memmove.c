/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:48:36 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/16 16:36:34 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	const char	*src_tmp;

	dst_tmp = (char *)dst;
	src_tmp = (const char *)src;
	if (dst == 0 || src == 0)
		return (dst);
	if (dst_tmp <= src_tmp)
	{
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		dst_tmp += (len - 1);
		src_tmp += (len - 1);
		while (len--)
			*dst_tmp-- = *src_tmp--;
	}
	return (dst);
}
