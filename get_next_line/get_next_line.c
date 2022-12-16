/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/16 16:49:35 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// 지워
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
//#include "get_next_line_utils.c"

void	free_node(t_list *save, t_list **head)
{
	t_list	*tmp;

	tmp = save;
	tmp->backup = NULL;
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
	if (save->backup == NULL)
		return (0);
	tmp = save->backup;
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
	tmp = save->backup;
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
			save->backup = malloc(tmp_len - i); //malloc 4
			if (!save->backup)
				return (NULL);
			ft_strlcpy(save->backup, &tmp[i + 1], tmp_len + 1);
			free (tmp); // free 1
			return (line);
		}
		i++;
	}
	if (read_size <= 0)
	{
		if (!(*save->backup) || read_size == -1)
		{
			free(save->backup);
			save->backup = NULL;
			return (NULL);
		}
		line = malloc(tmp_len + 1);
		ft_strlcpy(line, save->backup, tmp_len + 1);
		free(save->backup);
		save->backup = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*save;
	char			*buf;
	char			*line;
	ssize_t			read_size;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	//line = NULL;
	save = find_list(&head, fd);
	if (!save)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //malloc 1
	if (!buf)
	{
		free_node(save, &head);
		return(NULL);
	}
	while (!find_enter(save))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size > 0)
		{
			buf[read_size] = '\0';
			tmp = save->backup;
			save->backup = ft_strjoin(save->backup, buf); // malloc 2 & null guard
			free (tmp);
		}
		else
			break ;
	}
	line = split_line(save, read_size);
	free(buf);
	if (read_size <= 0 && !(save->backup))
		free_node(save, &head);
	return (line);
}

/*
int main()
{
	int fd = open("read_error.txt", O_RDONLY);
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
		close(fd);
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
		//close(fd);	
	}
}
*/