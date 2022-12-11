/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2022/12/11 20:23:28 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// 지워
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line_utils.c"
#define BUFFER_SIZE 5

typedef struct s_list
{
	int				file_descriptor;
	char			*buff;
	struct s_list	*next;
}t_list;

t_list	*new_node(int fd)
{
	t_list	*tmp;

	tmp = malloc(sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->file_descriptor = fd;
	return (tmp);
}

t_list	*find_list(t_list **head, int fd)
{
	t_list	*tmp;

	if (!(*head))
		*head = new_node(fd);
	tmp = *head;
	while (tmp)
	{
		if (tmp->file_descriptor == fd)
			return (tmp);
		if (tmp->next == NULL)
			tmp->next = new_node(fd);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*split_line(t_list *save, ssize_t read_size)
{
	char	*tmp;
	char	*line;
	int		flag;
	size_t	i;

	i = 0;
	flag = 0;
	line = NULL;
	tmp = save->buff;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{	
			flag = 1;
			line = malloc(i + 1);
			if (!line)
				return (NULL);
			ft_strlcpy(line, tmp, i + 1);
			save->buff = malloc(ft_strlen(tmp) - i);
			ft_strlcpy(save->buff, &tmp[i + 1], ft_strlen(tmp) + 1);
			free (tmp);
			break ;
		}
		i++;
	}
	if (flag == 0 && read_size == 0)
	{
		line = malloc(i + 1);
		if (!line)
			return (NULL);
		ft_strlcpy(line, tmp, i + 1);
		save->buff = calloc (1, 1);
		free (tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE];
	ssize_t			read_size;
	static t_list	*head;
	t_list			*save;
	char			*tmp;
	char			*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	save = find_list(&head, fd);
	if ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		save->buff = ft_strjoin(save->buff, buf);
		tmp = save->buff;
		line = split_line(save, read_size);
	}
	if (read_size == 0 && save->buff != NULL)
		line = split_line(save, read_size);
	return (line);
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
