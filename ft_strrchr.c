/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:31:49 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/15 14:42:08 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)string;
	while (*tmp)
		tmp++;
	if ((char)c == '\0')
		return (tmp);
	while (tmp != string)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp--;
	}
	return (0);
}
