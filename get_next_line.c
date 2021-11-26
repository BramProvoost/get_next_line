/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 10:48:01 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/11/26 12:19:24 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Steps in the function get_next_line:
- If the fd is not valid, the function returns NULL.
- Add the string form static buffer to line until a nl.
While no nl had been read
	- Read BUFFER_SIZE length number of characters and stor it in buffer.
	- If the read function return 0 or -1, the function returns NULL.
	- Add the string form static buffer to line until a nl.
- Copy from buffer after the nl in to buffer.
- The function returns line.
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_return;

	if (fd_not_valid(fd))
		return (NULL);
	line = NULL;
	line = str_join_until_nl(line, buffer);
	while (no_nl_in(buffer))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_nothing_or_error(read_return))
			break ;
		buffer[read_return] = '\0';
		line = str_join_until_nl(line, buffer);
		if (!line)
			return (NULL);
	}
	save_str_after_nl(buffer);
	return (line);
}

char	*str_join_until_nl(char *dst, char *src)
{
	char	*str;
	int		i;
	int		j;

	str = my_malloc(dst, src);
	if (!str)
		return (NULL);
	i = 0;
	while (dst && dst[i])
	{
		str[i] = dst[i];
		i++;
	}
	j = 0;
	while (src && src[j])
	{
		str[i + j] = src[j];
		j++;
		if (src[j - 1] == '\n')
			break ;
	}
	str[i + j] = '\0';
	free (dst);
	return (str);
}

char	*my_malloc(char *dst, char *src)
{
	char		*str;
	const int	dst_len = ft_strlen(dst);
	const int	src_len = ft_strlen(src);

	str = malloc(dst_len + src_len + 1);
	if (!str || dst_len + src_len == 0)
	{
		free(dst);
		free(str);
		return (NULL);
	}
	return (str);
}

int	no_nl_in(char *buffer)
{
	int	needle;

	needle = 0;
	while (buffer[needle] != '\0')
	{
		if (buffer[needle] == '\n')
			return (0);
		needle++;
	}
	return (1);
}

void	save_str_after_nl(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	while (str[j])
	{
		str[j] = '\0';
		j++;
	}
	str[j] = '\0';
}
