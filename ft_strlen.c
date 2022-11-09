/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:23:44 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/09 18:45:23 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned long	ft_strlen(const char *string)
{
	unsigned long	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
