/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:40:59 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/15 12:38:27 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t len)
{
	char			*tmp_ptr;
	unsigned char	tmp_c;

	tmp_ptr = (char *)ptr;
	tmp_c = (unsigned char) c;
	while (len--)
	{
		if (*tmp_ptr++ == tmp_c)
			return (--tmp_ptr);
	}
	return (0);
}
