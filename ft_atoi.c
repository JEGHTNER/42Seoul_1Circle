/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:59:24 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/16 13:28:56 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space_sign(const char *string, int *sign)
{
	int	i;

	i = 0;
	while ((string[i] >= 9 && string[i] <= 13) || string[i] == 32)
			i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *string)
{
	int					sign;
	int					i;
	long long			result;
	long long			max;

	max = __LONG_MAX__;
	sign = 1;
	result = 0;
	i = check_space_sign(string, &sign);
	while (ft_isdigit(string[i]))
	{
		result = result * 10 + string[i] - '0' ;
		if (sign == 1 && result >= max)
			return (-1);
		else if (sign == -1 && result >= max + 1)
			return (0);
		i++;
	}
	return (result * sign);
}
