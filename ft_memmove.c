/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:48:36 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/10 19:38:51 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	char		*dst_tmp;
	const char	*src_tmp;

	dst_tmp = (char *)dst;
	src_tmp = (const char *)src;
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
