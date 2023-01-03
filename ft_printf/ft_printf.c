/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:28 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/03 17:56:14 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "ft_printf_utils_diu.c"
// #include "ft_printf_utils_csp.c"
// #include "ft_printf_utils_hex.c"

char	*ft_strchr(const char *string, int c)
{
	char	*tmp;

	tmp = (char *)string;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	if ((char)c == '\0')
		return (tmp);
	return (0);
}

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

	count = 0;
	(*i_ptr)++;
	if (ft_strchr("cspdiuxX%", format[*i_ptr]))
	{
		count += print_argument(format[*i_ptr], ap);
	}
	return (count);
}

int	parse_format(char *format, va_list ap)
{
	int	ret_size;
	int	i;
	int	*i_ptr;

	ret_size = 0;
	i = 0;
	i_ptr = &i;
	while (format[i])
	{
		if (format[i] == '%')
			ret_size += init_parse(format, i_ptr, ap);
		else
		{
			write(1, &format[i], 1);
			ret_size++;
		}
		i++;
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
// 	a = printf("%u\n", -10);
// 	b = ft_printf("%u\n", -10);
// 	printf("printf = %d\nft_printf= %d", a, b);
// }