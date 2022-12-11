/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:42:31 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/11 18:47:41 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 5

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	if(!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if(!src)
		return (ft_strlen(dst));
	if (size != 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *string1, char const *string2)
{
	size_t	string1_len;
	size_t	string2_len;
	char	*tmp_string;

	string1_len = ft_strlen(string1);
	string2_len = ft_strlen(string2);
	tmp_string = malloc(sizeof(char) * (string1_len + string2_len) + 1);
	if (!tmp_string)
		return (0);
	ft_strlcpy(tmp_string, string1, string1_len + 1);
	ft_strlcpy(tmp_string + string1_len, string2, string2_len + 1);
	return (tmp_string);
}
