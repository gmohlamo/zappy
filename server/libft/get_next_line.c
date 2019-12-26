/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 06:58:16 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/18 11:46:14 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*descriptor(t_list **head, int fd)
{
	t_list			*ptr;

	ptr = *head;
	if (fd < 0)
		return (NULL);
	if (ptr == NULL)
	{
		*head = ft_lstnew(NULL, 0);
		(*head)->content_size = (size_t)fd;
		ptr = *head;
	}
	else
	{
		while (ptr->content_size != (size_t)fd && ptr->next != NULL)
			ptr = ptr->next;
		if (ptr->content_size != (size_t)fd)
		{
			ptr->next = ft_lstnew(NULL, 0);
			ptr->next->content_size = (size_t)fd;
			return (ptr->next);
		}
	}
	return (ptr);
}

static char			*ft_node2str(char *str, t_list *file, int *value)
{
	size_t			itr;
	char			*temp;

	temp = (char*)(file->content);
	itr = 0;
	while (temp[itr] && temp[itr] != '\n')
		itr++;
	str = ft_strsub(temp, 0, itr);
	if (ft_strchr(temp, '\n'))
	{
		file->content = (void*)ft_strsub(&temp[itr + 1],
				0, ft_strlen(&temp[itr + 1]));
		free(temp);
	}
	else if (temp[itr] == '\0')
	{
		ft_memdel(&file->content);
		if (ft_strlen(str) != 0)
			*value = 1;
		return (str);
	}
	*value = 1;
	return (str);
}

static char			*ft_buff2str(char *str, const char *buff,
		t_list *file, int *value)
{
	char			*temp;
	char			*temp2;
	size_t			itr;

	itr = 0;
	temp = NULL;
	temp2 = str;
	while (buff[itr] && buff[itr] != '\n')
		itr++;
	temp = ft_strsub(buff, 0, itr);
	str = ft_strsafejoin(temp2, temp);
	ft_memdel((void**)&temp2);
	ft_memdel((void**)&temp);
	if (buff[itr] == '\n')
		file->content = (void*)ft_strsub(&buff[itr], 1,
				ft_strlen(&buff[itr]) - 1);
	*value = 1;
	return (str);
}

static char			*join_strs(char *str, const char *buff,
		t_list **file, int *value)
{
	t_list			*ptr;

	ptr = *file;
	if (ptr->content)
		str = ft_node2str(str, *file, value);
	else if (buff[0] != '\0')
		str = ft_buff2str(str, buff, *file, value);
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*f_read;
	t_list			*current_file;
	char			buff[BUFF_SIZE + 1];
	char			*str;
	int				value[2];

	str = NULL;
	ft_bzero((void*)value, sizeof(*value) * 2);
	if (!(current_file = descriptor(&f_read, fd)) || (read(fd, buff, 0) < 0) ||
			line == NULL)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	str = join_strs(str, buff, &current_file, &value[0]);
	if (!current_file->content)
		while ((value[1] = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[value[1]] = '\0';
			str = join_strs(str, buff, &current_file, &value[0]);
			if (ft_strstr(buff, "\n"))
				break ;
		}
	(value[0] && line) ? *line = str : ft_strdel(&str);
	return ((value[0] >= 0) ? value[0] : -1);
}
