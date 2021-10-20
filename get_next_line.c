/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 08:53:32 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/20 15:22:09 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	while (i + 1 < size && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (j > 0)
		dst[i] = '\0';
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize < 1)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

void	ft_bzero(char *s, int n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{	
	void	*temp;

	if (ptr == NULL)
		return (ft_calloc(1, size));
	temp = ft_calloc(1, size);
	ft_strlcpy(temp, ptr, size);
	free(ptr);
	return (temp);
}

size_t	strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter])
		counter++;
	return (counter);
}

size_t	get_nl_pos(char *buf, ssize_t len)
{
	if (!buf)
		return (-1);
	while (len >= 0 && buf[len] != '\n')
		len--;
	return (len);
}

/*
** temp = malloc
** cpy current_line to temp
** free(current_line)
** current_line = malloc
** cpy temp to current_line
** add buffer to current_line
** free temp
*/

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*current_line;
	char		next_line[BUFFER_SIZE];
	size_t		read_length;
	size_t		line_length;
	ssize_t		nl_position;

	current_line = NULL;
	read_length = read(fd, &buffer, BUFFER_SIZE);
	if (read_length <= 0)
		return (NULL);
	line_length = read_length;
	nl_position = get_nl_pos(buffer, read_length);
	// printf("[nl:%zd]\n", nl_position);
	while (read_length > 0)
	{
		current_line = ft_realloc(current_line, line_length);
		ft_strlcat(current_line, buffer, line_length + 1);
		if (nl_position != -1)
		{
			current_line[line_length - read_length + nl_position] = '\0';
			ft_strlcpy(next_line, &current_line[line_length - read_length + nl_position + 1], read_length - nl_position);
			printf("nl = '%s'\n", next_line);
			return (current_line);
		}
		read_length = read(fd, &buffer, BUFFER_SIZE);
		line_length += read_length;
		nl_position = get_nl_pos(buffer, read_length);
	}
	return (current_line);
}

// char *p1;
// int m1, m2;
// m1 = 10;
// m2 = 20;
// p1 = (char*)malloc(m1);
// strcpy(p1, "Codesdope");
// p1 = (char*)realloc(p1, m2);
// strcat(p1, "Practice");
// printf("%s\n", p1);
