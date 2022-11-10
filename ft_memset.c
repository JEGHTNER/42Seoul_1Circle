/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:07:26 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/10 14:49:43 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, unsigned long len)
{
	unsigned long		i;
	char				*tmp;

	tmp = (char *)ptr;
	i = 0;
	while (i < len)
	{
		tmp[i] = (unsigned char)value;
		i++;
	}
	return ((void *)ptr);
}
