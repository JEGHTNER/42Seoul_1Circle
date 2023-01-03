/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:28 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/03 20:04:09 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "ft_printf_utils_diu.c"
// #include "ft_printf_utils_csp.c"
// #include "ft_printf_utils_hex.c"

int	print_argument(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == '%')
		count = print_percent();
	else if (format == 'd' || format == 'i')
		count = print_di(ap);
	else if (format == 'u')
		count = print_u(ap);
	else if (format == 'x' || format == 'X' || format == 'p')
		count = print_hexp(format, ap);
	else if (format == 'c')
		count = print_c(ap);
	else if (format == 's')
		count = print_s(ap);
	return (count);
}

int	init_parse(char *format, int *i_ptr, va_list ap)
{
	int	count;
	int	check_error;

	count = 0;
	check_error = 0;
	(*i_ptr)++;
	if (ft_strchr("cspdiuxX%", format[*i_ptr]))
	{
		check_error = print_argument(format[*i_ptr], ap);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	return (count);
}

int	parse_format(char *format, va_list ap)
{
	int	ret_size;
	int	i;
	int	*i_ptr;
	int	check_error;

	ret_size = 0;
	i = -1;
	i_ptr = &i;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			check_error = init_parse(format, i_ptr, ap);
			if (check_error == -1)
				return (-1);
			ret_size += check_error;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			ret_size++;
		}
	}
	return (ret_size);
}

int	ft_printf(const char *format, ...)
{
	int		ret_size;
	va_list	ap;

	va_start(ap, format);
	ret_size = parse_format((char *)format, ap);
	va_end(ap);
	return (ret_size);
}

// #include <stdio.h>
// int main()
// {
// 	int a;
// 	int b;
// 	a = printf("%d\n",10);
// 	b = ft_printf("%d\n",10);
// 	printf("printf = %d\nft_printf= %d", a, b);
// }