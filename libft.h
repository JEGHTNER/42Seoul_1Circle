/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:58 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/10 19:17:17 by jehelee          ###   ########.fr       */
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
void			ft_bzero(void *ptr, unsigned long len);
void			*ft_memcpy(void *dst, const void *src, unsigned long len);
void			*ft_memmove(void *dst, const void *src, unsigned long len);

#endif
