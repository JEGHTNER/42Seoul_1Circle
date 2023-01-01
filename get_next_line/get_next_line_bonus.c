/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/01 15:08:38 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// 지워
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
//#include "get_next_line_utils_bonus.c"

void	remove_fd(t_list *current_fd, t_list **head)
{
	if (!current_fd || !*head)
		return ;
	if (current_fd->prev)
		current_fd->prev->next = current_fd->next;
	if (current_fd->next)
		current_fd->next->prev = current_fd->prev;
	if (current_fd == *head)
		*head = current_fd->next;
	current_fd->file_descriptor = -1;
	free (current_fd->backup);
	current_fd->backup = NULL;
	free (current_fd->read_buff);
	current_fd->read_buff = NULL;
	free (current_fd);
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
		read_size = read(fd, current_fd->read_buff, BUFFER_SIZE);
		if (read_size == 0)
		{
			if (current_fd->backup && *(current_fd->backup))
			{	
				tmp = strchr(current_fd->backup, '\n');
				if (tmp)
				{	
					*tmp = '\0';
					line = ft_strjoin(current_fd->backup, "\n");
					if (!line)
					{
						remove_fd(current_fd, &head);
						return (NULL);
					}
					ft_strlcpy(current_fd->backup, tmp + 1, ft_strlen(tmp + 1) + 1);
					return (line);
				}
				else
				{
					line = ft_strdup(current_fd->backup);
					if(!line)
					{
						remove_fd(current_fd, &head);
						return (NULL);
					}
					remove_fd(current_fd, &head);
					return (line);
				}
			}
			else
			{
				remove_fd(current_fd, &head);
				return (NULL);
			}
		}
		if (read_size == -1)
		{
			remove_fd(current_fd, &head);
			free(line);
			return (NULL);
		}
		current_fd->read_buff[read_size] = '\0';
		if (!(current_fd->backup))
		{
			current_fd->backup = ft_strdup(current_fd->read_buff);
			if (!(current_fd->backup))
			{
				remove_fd(current_fd, &head);
				return (NULL);
			}
		}
		else
		{
			tmp = ft_strjoin(current_fd->backup, current_fd->read_buff);
			if (!tmp)
			{
				remove_fd(current_fd, &head);
				return (NULL);
			}
			free(current_fd->backup);
			current_fd->backup = tmp;
		}
		if (strchr(current_fd->backup, '\n') != NULL)
		{
			tmp = strchr(current_fd->backup, '\n');
			*tmp = '\0';
			line = ft_strjoin(current_fd->backup, "\n");
			if (!line)
			{
				remove_fd(current_fd, &head);
				return (NULL);
			}
			ft_strlcpy(current_fd->backup, tmp + 1, ft_strlen(tmp + 1) + 1);
			return (line);
		}
	}
}

/*
int main()
{
	// int fd = open("read_error.txt", O_RDONLY);
	// if (fd < 0 )
	// 	printf ("file open fail\n");
	// int fd2 = open("lines_around_10.txt", O_RDONLY);
	// if (fd2 < 0 )
	// 	printf ("file open fail\n");
	// int fd3 = open("43_with_nl", O_RDONLY);
	// if (fd3 < 0 )
	// 	printf ("file open fail\n");
	// int fd4 = open("giant_line_nl.txt", O_RDONLY);
	// if (fd4 < 0 )
	// 	printf ("file open fail\n");
	// else
	// {
	// 	printf("fd:%s\n",get_next_line(fd));
	// 	printf("fd2:%s\n",get_next_line(fd2));
	// 	printf("fd:%s\n",get_next_line(fd));
	// 	printf("fd2:%s\n",get_next_line(fd2));
	// 	while(get_next_line(fd) != NULL)
	// 		printf("while : %s\n",get_next_line(fd));
	// 	close(fd);
	// 	printf("fd2:%s\n",get_next_line(fd2));
	// 	fd = open("read_error.txt", O_RDONLY);
	// 	if (fd < 0 )
	// 		printf ("file open fail\n");
	// 	printf("fd:%s\n",get_next_line(fd));
	// 	printf("fd2:%s\n",get_next_line(fd2));
	// 	printf("fd:%s\n",get_next_line(fd));
	// 	printf("fd:%s\n",get_next_line(fd));
	// 	printf("fd2:%s\n",get_next_line(fd2));
	// 	printf("fd2:%s\n",get_next_line(fd2));
	// 	printf("fd:%s\n",get_next_line(fd));
	// 	printf("fd:%s\n",get_next_line(fd));
	// }
	int fd = open("41_with_nl", O_RDONLY);
	if (fd < 0 )
		printf ("file open fail\n");
	int fd2 = open("42_with_nl", O_RDONLY);
	if (fd2 < 0 )
		printf ("file open fail\n");
	int fd3 = open("43_with_nl", O_RDONLY);
	if (fd3 < 0 )
		printf ("file open fail\n");
	int fd4 = open("nl", O_RDONLY);
	if (fd4 < 0 )
		printf ("file open fail\n");
	else
	{
		printf("fd:%s\n",get_next_line(fd));
		printf("fd1000:%s\n",get_next_line(1000));
		printf("fd1:%s\n",get_next_line(fd2));
		printf("fd2:%s\n",get_next_line(fd3));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd1:%s\n",get_next_line(fd2));
		printf("fd2:%s\n",get_next_line(fd3));
		printf("fd:%s\n",get_next_line(fd));
		printf("fd1:%s\n",get_next_line(fd2));
		printf("fd2:%s\n",get_next_line(fd3));
		printf("fd3:%s\n",get_next_line(fd4));
		printf("fd3:%s\n",get_next_line(fd4));
	}

	// int fd = open("1char.txt", O_RDONLY);
	// if (fd < 0 )
	// 	printf ("file open fail\n");
	// else{
	// 	printf("fd:%s\n",get_next_line(fd));
	// 	printf("fd:%s\n",get_next_line(fd));
	// }
}
*/