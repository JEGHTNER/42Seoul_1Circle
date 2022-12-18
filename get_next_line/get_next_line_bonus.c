/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/18 21:21:07 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// 지워
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
#include "get_next_line_utils_bonus.c"

void	remove_fd(t_list *current_fd, t_list **head)
{
	if (!current_fd || !*head)
		return ;
	if (current_fd->prev)
		current_fd->prev->next = current_fd->next;
	if (current_fd->next)
		current_fd->next->prev = current_fd->prev;
	else
		*head = current_fd->next;
		//save->next->prev = NULL;
	free (current_fd->backup);
	current_fd->backup = NULL;
	free (current_fd);
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

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*current_fd;
	ssize_t			read_size;
	char			*line;
	char			*tmp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	current_fd = find_fd(&head, fd);
	if (!current_fd)
		return (NULL);
	while (1)
	{
		read_size = read(fd, current_fd->backup, BUFFER_SIZE);
		if (read_size == 0)
		{
			remove_fd(current_fd, &head);
			return (line);
		}
		if (read_size == -1)
		{
			remove_fd(current_fd, &head);
			free(line);
			return (NULL);
		}
		current_fd->backup[read_size] = '\0';
		if (!line)
			line = strdup(current_fd->backup);
		else
		{
			tmp = ft_strjoin(line, current_fd->backup);
			free(line);
			line = tmp;
		}
		if (strchr(current_fd->backup, '\n') != NULL)
		{
			tmp = strchr(line, '\n');
			*tmp = '\0';
			strcpy(current_fd->backup, tmp + 1);
			return (line);
		}
	}
}


int main()
{
	int fd = open("lines_around_10.txt", O_RDONLY);
	if (fd < 0 )
		printf ("file open fail\n");
	int fd2 = open("42_with_nl", O_RDONLY);
	if (fd2 < 0 )
		printf ("file open fail\n");
	int fd3 = open("43_with_nl", O_RDONLY);
	if (fd3 < 0 )
		printf ("file open fail\n");
	int fd4 = open("giant_line_nl.txt", O_RDONLY);
	if (fd4 < 0 )
		printf ("file open fail\n");
	else
	{
		// printf("fd2:%s\n",get_next_line(fd2));
		// printf("fd2:%s\n",get_next_line(fd2));
		// printf("fd2:%s\n",get_next_line(fd2));
		// printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		// printf("fd2:%s\n",get_next_line(fd2));
		// printf("fd2:%s\n",get_next_line(fd2));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd:%s\n",get_next_line(fd));
	}
}
