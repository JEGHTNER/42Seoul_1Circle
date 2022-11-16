/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:14:30 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/16 15:41:57 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t len)
{
	while ((*string1 || *string2) && len-- > 0)
	{
		if (*string1 != *string2)
			return ((unsigned char)*string1 - (unsigned char )*string2);
		string1++;
		string2++;
	}
	return (0);
}
