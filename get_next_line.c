/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 08:53:32 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/20 21:16:59 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_nl_pos(char *buf, ssize_t len)
{
	if (!buf)
		return (-1);
	while (len >= 0 && buf[len] != '\n')
		len--;
	return (len);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*current_line;
	char		next_line[BUFFER_SIZE];
	ssize_t		read_length;
	size_t		line_length;
	ssize_t		nl_position;

	printf("fd: %d location: %p\n", fd, next_line);
	next_line[0] = 'Q';
	current_line = NULL;
	read_length = read(fd, &buffer, BUFFER_SIZE);
	if (read_length <= 0)
		return (NULL);
	line_length = read_length;
	nl_position = get_nl_pos(buffer, read_length);
	while (read_length > 0)
	{
		current_line = ft_realloc(current_line, line_length);
		ft_strlcat(current_line, buffer, line_length + 1);
		if (nl_position != -1)
		{
			current_line[line_length - read_length + nl_position] = '\0';
			ft_strlcpy(next_line, &current_line[line_length - read_length + nl_position + 1], read_length - nl_position);
			return (current_line);
		}
		read_length = read(fd, &buffer, BUFFER_SIZE);
		line_length += read_length;
		nl_position = get_nl_pos(buffer, read_length);
	}
	return (current_line);
}
