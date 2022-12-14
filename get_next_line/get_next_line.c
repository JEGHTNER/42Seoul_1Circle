/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/14 19:51:34 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// 지워
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

void	free_node(t_list *save, t_list **head)
{
	t_list	*tmp;

	tmp = save;
	tmp->buff = NULL;
	if (save->prev)
		save->prev->next = save->next;
	else
		*head = NULL;
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
	size_t	tmp_len;

	i = 0;
	line = NULL;
	tmp = save->buff;
	if (!tmp)
		return (NULL);
	tmp_len = ft_strlen(tmp);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{	
			line = malloc(i + 2); // malloc 3 
			if (!line)
				return (NULL);
			ft_strlcpy(line, tmp, i + 2);
			save->buff = malloc(tmp_len - i); //malloc 4
			ft_strlcpy(save->buff, &tmp[i + 1], tmp_len + 1);
			free (tmp); // free 1
			return (line);
		}
		i++;
	}
	if (read_size == 0)
	{
		if (!(*save->buff))
			return (NULL);
		line = malloc(tmp_len + 1);
		ft_strlcpy(line, save->buff, tmp_len + 1);
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
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //malloc 1
	if (!buf)
		return(NULL);
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size > 0)
		{
			buf[read_size] = '\0';
			save->buff = ft_strjoin(save->buff, buf); // malloc 2
		}
		if (find_enter(save) || read_size <= 0)
		{
			line = split_line(save, read_size);
			break ;
		}
	}
	free(buf);
	buf = NULL;
	if (read_size <= 0 && !(save->buff))
		free_node(save, &head);
	return (line);
}


int main()
{
	int fd = open("multiple_nl.txt", O_RDONLY);
	if (fd < 0 )
		printf ("file open fail\n");
	int fd2 = open("one_line_no_nl.txt", O_RDONLY);
	if (fd < 0 )
		printf ("file open fail\n");
	else
	{
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		//printf("fd2:%s\n",get_next_line(fd2));
		close(fd);	
	}
}
