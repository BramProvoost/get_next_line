/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 10:50:20 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/20 17:14:34 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memset(void *str, int c, size_t n)
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

static void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_memset(ptr, '\0', size * count);
	return (ptr);
}

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

/*
static size_t	strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter])
		counter++;
	return (counter);
}
*/
