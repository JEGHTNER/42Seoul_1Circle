/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:58 by jehelee           #+#    #+#             */
/*   Updated: 2022/11/18 14:03:18 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_strncmp(const char *string1, const char *string2, size_t n);
int				ft_memcmp(const void *string1, const void *string2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *string);
size_t			ft_strlen(const char *string);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			*ft_memset(void *ptr, int value, size_t len);
void			ft_bzero(void *ptr, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *ptr, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *string, int c);
char			*ft_strrchr(const char *string, int c);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
char			*ft_strdup(const char *string);
char			*ft_substr(char const *string, unsigned int start, size_t len);
char			*ft_strjoin(char const *string1, char const *string2);
char			*ft_strtrim(char const *s1, char const *set);

#endif
