/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_diu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:39:36 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/03 16:50:10 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display(long long number, int *count)
{
	long long	wr_num;

	if (number >= 10)
		display(number / 10, count);
	wr_num = number % 10 + '0';
	write(1, &wr_num, 1);
	(*count)++;
}

int	ft_putnbr_diu(int number)
{
	long long	nbr;
	int			count;

	count = 0;
	nbr = (long long)number;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		count++;
	}
	display(nbr, &count);
	return (count);
}

int	print_di(va_list ap)
{
	int	count;
	int	ap_int;

	ap_int = va_arg(ap, int);
	count = ft_putnbr_diu(ap_int);
	return (count);
}

int	print_u(va_list ap)
{
	int				count;
	unsigned int	ap_uint;

	ap_uint = va_arg(ap, unsigned int);
	count = ft_putnbr_diu(ap_uint);
	return (count);
}
