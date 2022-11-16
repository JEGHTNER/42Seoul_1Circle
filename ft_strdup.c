/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:54 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/16 12:45:14 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*new_string;
	int		i;

	new_string = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (!new_string)
		return (0);
	i = 0;
	while (string[i])
	{
		new_string[i] = string[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
