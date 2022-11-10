/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:55:52 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/10 18:37:59 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned long len)
{
	char			*dst_tmp;
	const char		*src_tmp;
	unsigned long	i;

	dst_tmp = (char *) dst;
	src_tmp = (const char *) src;
	i = 0;
	while (i < len)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}
