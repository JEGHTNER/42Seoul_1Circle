/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:51:34 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/23 20:54:37 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *string, int file_descriptor)
{
	ft_putstr_fd(string, file_descriptor);
	ft_putchar_fd('\n', file_descriptor);
}
