/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:42:31 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/16 16:00:34 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

t_list	*new_node(int fd)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->backup = NULL;
	tmp->file_descriptor = fd;
	return (tmp);
}

t_list	*find_list(t_list **head, int fd)
{
	t_list	*tmp;

	if (!(*head))
		*head = new_node(fd);
	tmp = *head;
	while (tmp)
	{
		if (tmp->file_descriptor == fd)
			return (tmp);
		if (tmp->next == NULL)
		{
			tmp->next = new_node(fd);
			tmp->next->prev = tmp;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;

	if (!string)
		return (0);
	while (*string)
	{
		i++;
		string++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;

	if (!src || !dst)
		return (0);
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

	string2_len = ft_strlen(string2);
	string1_len = ft_strlen(string1);
	tmp_string = malloc(sizeof(char) * (string1_len + string2_len) + 1);
	if (!tmp_string)
		return (0);
	ft_strlcpy(tmp_string, string1, string1_len + 1);
	ft_strlcpy(tmp_string + string1_len, string2, string2_len + 1);
	return (tmp_string);
}
