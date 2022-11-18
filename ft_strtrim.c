/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:03:07 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/18 14:23:14 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *trim_set)
{
	while (*trim_set)
	{
		if (c == *trim_set)
			return (1);
		trim_set++;
	}
	return (0);
}

static int	get_trimmed_len(char const *string1, char const *trim_set)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (string1[i])
	{
		if (check_set(string1[i], trim_set) == 0)
			len++;
		i++;
	}
	return (len);
}
//123
//12

char	*ft_strtrim(char const *string1, char const *trim_set)
{
	int		i;
	int		j;
	char	*tmp_string;

	i = 0;
	j = 0;
	tmp_string = malloc(sizeof(char) * get_trimmed_len(string1, trim_set) + 1);
	while (string1[i])
	{
		if (check_set(string1[i], trim_set) == 0)
			tmp_string[j++] = string1[i];
		i++;
	}
	return (tmp_string);
}
