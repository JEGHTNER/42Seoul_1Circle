/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:44:38 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/16 13:32:39 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *string1, const void *string2, size_t n)
{
	size_t		i;
	char		*s1_tmp;
	char		*s2_tmp;

	s1_tmp = (char *)string1;
	s2_tmp = (char *)string2;
	i = 0;
	while (i < n)
	{
		if (s1_tmp[i] != s2_tmp[i])
			return ((unsigned char)s1_tmp[i] - (unsigned char)s2_tmp[i]);
		i++;
	}
	return (0);
}
