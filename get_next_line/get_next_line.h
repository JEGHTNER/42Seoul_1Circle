/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:42:28 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/14 16:06:17 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h> // 지워

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	int				file_descriptor;
	char			*buff;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

t_list	*new_node(int fd);
t_list	*find_list(t_list **head, int fd);
int		find_enter(t_list *save);
char	*split_line(t_list *save, ssize_t read_size);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *string);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *string1, char const *string2);

#endif