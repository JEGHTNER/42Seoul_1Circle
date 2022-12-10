/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/10 20:59:47 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// 지워
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
	int				file_descriptor;
	char			*buff;
	struct s_list	next;
}t_list;

t_list	*find_list(t_list *head, int fd)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->file_descriptor == fd)
			return (tmp);
		tmp = tmp->next;
	}
}

char	*get_next_line(int fd)
{
	char			buf[100];
	ssize_t			read_size;
	static t_list	*head;
	t_list			*save;

	tmp_ptr = save[fd];
	while ((read_size = read(fd, buf, 1) > 0))
	{
		if(*buf == '\n')
		{
			*tmp_ptr = '\0';
			break;
		}
		*tmp_ptr = *buf;
		tmp_ptr++;
	}
	if (read_size <= 0)
	{
		return (NULL);
	}
	return (save[fd]);
}


int main()
{
	int fd = open("test.txt", O_RDONLY);
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
