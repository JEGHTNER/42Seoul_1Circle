/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:14:30 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/15 16:30:42 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t len)
{
	size_t	i;

	while (*string1 || *string2 && len-- > 0)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	return (0);
}
