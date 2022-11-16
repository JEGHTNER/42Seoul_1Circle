/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:43:33 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/16 16:17:24 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_space;

	new_space = malloc(size * count);
	if (!new_space)
		return (0);
	ft_bzero(new_space, size * count);
	return (new_space);
}
