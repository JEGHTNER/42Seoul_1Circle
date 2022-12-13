/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/13 20:59:50 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// 지워
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

void	free_node(t_list *save)
{
	t_list	*tmp;

	tmp = save;
	save->prev->next = save->next;
	free (tmp);
}

int	find_enter(t_list *save)
{
	char	*tmp;

	if (save == NULL)
		return (0);
	if (save->buff == NULL)
		return (0);
	tmp = save->buff;
	while (*tmp)
	{
		if (*tmp == '\n')
			return (1);
		tmp++;
	}
	return (0);
}

char	*split_line(t_list *save, ssize_t read_size)
{
	char	*tmp;
	char	*line;
	size_t	i;

	i = 0;
	line = NULL;
	tmp = save->buff;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{	
			line = malloc(i + 2);
			if (!line)
				return (NULL);
			ft_strlcpy(line, tmp, i + 2);
			save->buff = malloc(ft_strlen(tmp) - i);
			ft_strlcpy(save->buff, &tmp[i + 1], ft_strlen(tmp) + 1);
			free (tmp);
			break ;
		}
		i++;
	}
	if (read_size == 0)
	{
		line = malloc(ft_strlen(tmp));
		ft_strlcpy(line, save->buff, ft_strlen(tmp) + 1);
		free(tmp);
		save->buff = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buf;
	ssize_t			read_size;
	static t_list	*head;
	t_list			*save;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	save = find_list(&head, fd);
	read_size = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		save->buff = ft_strjoin(save->buff, buf);
		if (find_enter(save))
		{	
			line = split_line(save, read_size);
			break ;
		}
	}
	free(buf);
	if (read_size < 0)
		free_node(save);
	return (line);
}

int main()
{
	int fd = open("lines_around_10.txt", O_RDONLY);
	if (fd < 0 )
		printf ("file open fail\n");
	else
	{
		printf("%s\n",get_next_line(fd));
		printf("%s\n",get_next_line(fd));
		printf("%s\n",get_next_line(fd));
		printf("%s\n",get_next_line(fd));
		printf("%s\n",get_next_line(fd));
		printf("%s\n",get_next_line(fd));
		printf("%s\n",get_next_line(fd));
		close(fd);	
	}
}
