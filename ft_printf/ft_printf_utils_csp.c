/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_csp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:35 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/03 18:28:32 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_strlen(const char *string)
{
	size_t	count;

	count = 0;
	if (!string)
		return (0);
	while (*string)
	{
		string++;
		count++;
	}
	return (count);
}

int	print_percent(void)
{
	int	count;

	count = 0;
	if (write(1, "%", 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	print_c(va_list ap)
{
	int				count;
	unsigned char	ap_char;

	count = 0;
	ap_char = (unsigned char)va_arg(ap, int);
	if (write(1, &ap_char, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	print_s(va_list ap)
{
	int		count;
	char	*ap_str;

	count = 0;
	ap_str = va_arg(ap, char *);
	if (!ap_str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		count = 6;
		return (count);
	}
	count = ft_strlen(ap_str);
	if (write(1, ap_str, count) == -1)
		return (-1);
	return (count);
}
