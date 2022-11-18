/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:35 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/18 13:43:32 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp_string;

	tmp_string = malloc(sizeof(char) * len + 1);
	if (!tmp_string)
		return (0);
	i = 0;
	ft_strlcpy(tmp_string, &string[start], len + 1);
	return (tmp_string);
}
