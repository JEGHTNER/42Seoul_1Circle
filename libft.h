/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:58 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/10 14:06:21 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
unsigned long	ft_strlen(const char *string);
void			*ft_memset(void *ptr, int value, unsigned long len);

#endif

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

unsigned long	ft_strlen(const char *string)
{
	unsigned long	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

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
