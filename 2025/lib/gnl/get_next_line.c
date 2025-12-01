/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:18:59 by smenard           #+#    #+#             */
/*   Updated: 2025/11/28 15:12:55 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Get the next line of the file pointed by fd
 */
char	*get_next_line(int fd)
{
	t_buffer	*buffer;
	char		*line;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	buffer = get_buffer(fd);
	if (!buffer)
		return (NULL);
	line = build_next_line(fd, buffer);
	if (!line)
		return (safe_free_return(NULL, buffer, NULL, NULL));
	return (safe_free_return(NULL, buffer, NULL, line));
}

/**
 * Allocates memory and reads the next line in the file pointed by fd
 */
char	*build_next_line(int fd, t_buffer *buffer)
{
	t_list				*lst;
	t_line_build_status	status;
	char				*line;
	size_t				total_content_length;

	status = INCOMPLETE;
	total_content_length = 0;
	lst = ft_lstnew(&total_content_length);
	if (!lst)
		return (NULL);
	while (status != COMPLETE && status != NO_LINES)
	{
		status = extract_line(fd, lst, buffer);
		if (status == ERROR)
			return (safe_free_return(lst, NULL, NULL, NULL));
	}
	if (buffer->data[buffer->index] == '\n')
	{
		buffer->data[buffer->index] = '\0';
		if (!ft_lstappend(lst, '\n'))
			return (safe_free_return(lst, NULL, NULL, NULL));
	}
	line = ft_lstjoin_clear(lst);
	return (line);
}

t_line_build_status	extract_line(int fd, t_list *lst, t_buffer *buffer)
{
	t_list				*curr_link;
	t_line_build_status	status;
	ssize_t				read_res;

	status = INCOMPLETE;
	read_res = 0;
	curr_link = lst;
	while (buffer->index < BUFFER_SIZE && buffer->data[buffer->index]
		&& buffer->data[buffer->index] != '\n')
	{
		curr_link = ft_lstappend(curr_link, buffer->data[buffer->index]);
		buffer->data[buffer->index] = '\0';
		if (!curr_link)
			return (ERROR);
		buffer->index++;
	}
	if (buffer->data[buffer->index] == '\n')
		status = COMPLETE;
	if (status != COMPLETE)
		read_res = read_file(fd, buffer);
	if (read_res == -1 || (read_res == 0 && lst->total_content_length == 0))
		return (ERROR);
	if (read_res == 0)
		status = NO_LINES;
	return (status);
}

/**
 * Get the static buffer containing the rest of the last call to get_next_line
 */
t_buffer	*get_buffer(int fd)
{
	static char	buffers[BUFFER_SIZE];
	t_buffer	*buffer;

	buffer = malloc(sizeof(t_buffer));
	if (!buffer)
		return (NULL);
	buffer->data = buffers;
	buffer->index = 0;
	while (buffer->index < BUFFER_SIZE && !buffer->data[buffer->index])
		buffer->index++;
	if (buffer->index == BUFFER_SIZE && read_file(fd, buffer) <= 0)
		return (safe_free_return(NULL, buffer, NULL, NULL));
	return (buffer);
}
