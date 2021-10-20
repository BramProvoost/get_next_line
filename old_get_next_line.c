/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 09:26:10 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/12 21:47:55 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> /* temp printf */

/* 
- handle last next_line
- length = read the buffer
- if length is 0 or -1:
  - return null
- if there is a \n in buffer:
  - split buffer
  - store the chars after the \n in next_line
  - add the chart before the \n in current_line
  - return current_line
- add buffer to current_line 
- if length == buffer_size:
  - return current_line
*/

// static ssize_t	is_eof_or_error(ssize_t value);

static ssize_t	get_nl_pos(char *buf, ssize_t len);

// static char		*handel_nl(char *buf1, char *buf2, ssize_t pos);

// static char		*handle_buf(char *buf1, char *buf2, ssize_t len);

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

char	*strdup(const char *str)
{
	char			*temp;
	unsigned long	len;
	unsigned long	i;

	len = strlen(str);
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (NULL);
	i = len;
	len = 0;
	while (len < i)
	{
		temp[len] = str[len];
		len++;
	}
	temp[len] = '\0';
	return (temp);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	if (n != 0 && dest == src)
		return (dest);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t len)
{
	void	*real;

	real = malloc(len);
	ft_memset(real, 0, len);
	if (real)
		ft_memcpy(real, ptr, len);
	ptr = NULL;
	free(ptr);
	return (real);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*next_line = NULL;
	char		*current_line;
	size_t		length;
	size_t		nl_pos;

	if (next_line)
		current_line = strdup(next_line);
	length = read(fd, &buffer, BUFFER_SIZE);
	current_line = NULL;
	nl_pos = get_nl_pos(buffer, length);
	current_line = ft_realloc(current_line, strlen(current_line) + length);
	current_line = ft_memcpy(current_line, buffer, length);
	return (current_line);
}

// char	*get_next_line(int fd)
// {
// 	char		buf1[BUFFER_SIZE];
// 	static char	*buf2 = "";
// 	char		*result;
// 	int			length;
// 	int			nl_pos;

// 	result = "";
// 	length = read(fd, &buf1, BUFFER_SIZE);
// 	if (is_eof_or_error(length))
// 		return (NULL);
// 	result = handle_buf(result, buf1, length);
// 	nl_pos = get_nl_pos(result, length);
// 	printf("result:\t\t'%s'\n", result);
// 	while (nl_pos == -1 && length == BUFFER_SIZE)
// 	{
// 		printf("loop\n");
// 		length = read(fd, &buf1, BUFFER_SIZE);
// 		if (is_eof_or_error(length))
// 			return (NULL);
// 		result = handle_buf(result, buf1, length);
// 		nl_pos = get_nl_pos(result, length);
// 		printf("result:\t\t'%s'\n", result);
// 	}
// 	printf("return\n");
// 	return (handel_nl(result, buf2, nl_pos));
// }

/* 
** Check return value form read for end of file or error.
*/

// static ssize_t	is_eof_or_error(ssize_t value)
// {
// 	return (value <= 0);
// }

static ssize_t	get_nl_pos(char *buf, ssize_t len)
{
	if (!buf)
		return (-1);
	while (buf[len] != '\n' && len >= 0)
	{
		len--;
	}
	return (len);
}

// static char	*handel_nl(char *buf1, char *buf2, ssize_t pos)
// {
// 	char	*before_nl;
// 	char	*after_nl;

// 	before_nl = substr(buf1, 0, pos);
// 	after_nl = substr(buf1, pos - 1, BUFFER_SIZE);
// 	buf2 = strjoin(buf2, after_nl, BUFFER_SIZE);
// 	printf("pos_nl:\t%zd\n", pos);
// 	printf("before_nl:\t'%s'\n", before_nl);
// 	printf("after_nl:\t'%s'\n", after_nl);
// 	return (before_nl);
// }

// static char	*handle_buf(char *buf1, char *buf2, ssize_t len)
// {
// 	char	*result;

// 	result = strjoin(buf1, buf2, len);
// 	printf("strjoin buf:\t'%s'\n", result);
// 	buf2 = "";
// 	return (result);
// }

// char	*get_next_line(int fd)
// {
// 	char		buf1[BUFFER_SIZE];
// 	char		*temp;
// 	static char	*buf2 = NULL;
// 	int			charsRead;
// 	int			needle;

// 	charsRead = read(fd, &buf1, BUFFER_SIZE);
// 	needle = 0;
// 	while (charsRead == BUFFER_SIZE)
// 	{
// 		while (needle < charsRead)
// 		{
// 			if (buf1[needle] == '\n')
// 			{
// 				temp = substr(buf1, needle, charsRead - needle);
// 				buf2 = temp;
// 				free(temp);
// 				printf("buf2: '%s'\n", buf2);
// 				temp = substr(buf1, 0, needle);
// 				temp = strjoin(temp, buf1, needle);
// 				return (temp);
// 			}
// 			needle++;
// 		}
// 		temp = strjoin(temp, buf1, BUFFER_SIZE);
// 		charsRead = read(fd, &buf1, BUFFER_SIZE);
// 	}
// 	if (charsRead <= 0 && !temp)
// 		return (NULL);
// 	else
// 		temp = strjoin(temp, buf1, charsRead);
// 	return (temp);
// }

// char	*get_next_line(int fd)
// {
// 	char		buf[BUFFER_SIZE];
// 	char		*str;
// 	int			charsRead;
// 	int			needle;

// 	str = NULL;
// 	charsRead = read(fd, &buf, BUFFER_SIZE);
// 	while (charsRead == BUFFER_SIZE)
// 	{
// 		needle = 0;
// 		while (needle < BUFFER_SIZE)
// 		{
// 			if (buf[needle] == '\n')
// 			{
// 				str = strjoin(str, buf, needle);
// 				return (str);
// 			}
// 			needle++;
// 		}
// 		if (charsRead <= 0)
// 			return (NULL);
// 		str = strjoin(str, buf, BUFFER_SIZE);
// 		charsRead = read(fd, &buf, BUFFER_SIZE);
// 	}
// 	if (charsRead <= 0 && str == NULL)
// 		return (NULL);
// 	str = strjoin(str, buf, charsRead);
// 	return (str);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	buf[4];

// 	buf[0] = 'a';
// 	buf[1] = 'b';
// 	buf[2] = 'c';
// 	str = "123";
// 	str = strjoin(str, buf, 3);
// 	printf("%s\n", str);
// 	free(str);
// 	// printf("-----------------------------------------\n");
// 	// system("leaks a.out");
// 	return (0);
// }

// int	main(void)
// {
// 	char	str1[] = "123";
// 	char	*str2;
// 	char	*str3;

// 	str2 = "abc";
// 	str3 = strjoin(str1, str2, 3);
// 	printf("str3 = %s\n", str3);
// 	return (0);
// }
