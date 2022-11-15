/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:58 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/15 16:15:30 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_strncmp(const char *string1, const char *string2, size_t n);
int				ft_memcmp(const void *string1, const void *string2, size_t n);
size_t			ft_strlen(const char *string);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			*ft_memset(void *ptr, int value, size_t len);
void			ft_bzero(void *ptr, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *ptr, int c, size_t len);
char			*ft_strchr(const char *string, int c);
char			*ft_strrchr(const char *string, int c);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);

#endif
