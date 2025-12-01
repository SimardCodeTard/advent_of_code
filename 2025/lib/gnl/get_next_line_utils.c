/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:56:31 by smenard           #+#    #+#             */
/*   Updated: 2025/11/28 16:06:46 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Allocates memory and concatenates the contents of every link in the list
 * The input list is cleared afterwards
 */
char	*ft_lstjoin_clear(t_list *lst)
{
	t_list	*curr_link;
	char	*s_joined;
	size_t	i;
	size_t	j;

	i = 0;
	if (!lst)
		return (NULL);
	s_joined = malloc((*lst->total_content_length + 1) * sizeof(char));
	if (!s_joined)
		return (safe_free_return(lst, NULL, NULL, NULL));
	curr_link = lst;
	while (curr_link && curr_link->content_length > 0)
	{
		j = 0;
		while (j < curr_link->content_length)
			s_joined[i++] = curr_link->content[j++];
		curr_link = curr_link->next;
	}
	if (i == 0)
		return (safe_free_return(lst, NULL, s_joined, NULL));
	s_joined[i] = '\0';
	return (safe_free_return(lst, NULL, NULL, s_joined));
}

/**
 * Allocates memory and returns a new list
 */
t_list	*ft_lstnew(size_t *total_content_length)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content_length = 0;
	lst->total_content_length = total_content_length;
	return (lst);
}

/**
 * Appends the given char to the end of the list
 */
t_list	*ft_lstappend(t_list *lst, char c)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	if (lst->content_length >= LIST_MAX_CONTENT_LENGTH)
	{
		lst->next = ft_lstnew(lst->total_content_length);
		lst = lst->next;
		if (!lst)
			return (NULL);
	}
	lst->content[lst->content_length] = c;
	lst->content_length++;
	(*lst->total_content_length)++;
	return (lst);
}

ssize_t	read_file(int fd, t_buffer *buffer)
{
	ssize_t	read_result;

	read_result = read(fd, buffer->data, BUFFER_SIZE);
	if (read_result == -1)
		return (read_result);
	if (read_result < BUFFER_SIZE)
		buffer->data[read_result] = '\0';
	buffer->index = 0;
	return (read_result);
}

/**
 * Frees all pointers, fills the buffer with NULL bytes and returns value
 */
void	*safe_free_return(t_list *lst, t_buffer *buffer, char *line,
			void *value)
{
	t_list	*lst_next;

	lst_next = lst;
	while (lst_next)
	{
		lst_next = lst->next;
		free(lst);
		lst = lst_next;
	}
	if (buffer)
		free(buffer);
	free(line);
	return (value);
}
