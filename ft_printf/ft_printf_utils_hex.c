/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:37 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/03 17:04:09 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	display_hex(unsigned long long number, char *hex, int *count)
{
	if (number >= 16)
		display_hex(number / 16, hex, count);
	write(1, &hex[number % 16], 1);
	(*count)++;
}

int	ft_puthex_p(unsigned long long ap_hex)
{
	int		count;
	char	*low_hex;

	low_hex = "0123456789abcdef";
	write(1, "0x", 2);
	count += 2;
	display_hex(ap_hex, low_hex, &count);
	return (count);
}

int	ft_puthex_x(char format, unsigned long long ap_hex)
{
	int		count;
	char	*cap_hex;
	char	*low_hex;

	cap_hex = "0123456789ABCDEF";
	low_hex = "0123456789abcdef";
	if (format == 'x')
		display_hex(ap_hex, low_hex, &count);
	else
		display_hex(ap_hex, cap_hex, &count);
	return (count);
}

int	print_hexp(char format, va_list ap)
{
	int					count;
	unsigned long long	ap_hex;

	if (format == 'p')
	{
		ap_hex = (unsigned long long)va_arg(ap, void *);
		count = ft_puthex_p(ap_hex);
	}
	else
	{
		ap_hex = va_arg(ap, unsigned int);
		count = ft_puthex_x(format, ap_hex);
	}
	return (count);
}
