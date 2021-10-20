/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 10:50:20 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/12 21:30:37 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

// size_t	strlen(const char *str)
// {
// 	size_t	counter;

// 	counter = 0;
// 	if (!str)
// 		return (0);
// 	while (str[counter])
// 		counter++;
// 	return (counter);
// }

// char	*strdup(const char *str)
// {
// 	char			*temp;
// 	unsigned long	len;
// 	unsigned long	i;

// 	len = strlen(str);
// 	temp = (char *)malloc(len + 1);
// 	if (!temp)
// 		return (NULL);
// 	i = len;
// 	len = 0;
// 	while (len < i)
// 	{
// 		temp[len] = str[len];
// 		len++;
// 	}
// 	temp[len] = '\0';
// 	return (temp);
// }

// size_t	strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!dst || !src)
// 		return (0);
// 	if (dstsize < 1)
// 	{
// 		while (src[i])
// 			i++;
// 		return (i);
// 	}
// 	while (src[i] && i < dstsize - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	if (i < dstsize)
// 		dst[i] = '\0';
// 	while (src[i])
// 		i++;
// 	return (i);
// }

// char	*substr(char const *s, size_t start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (!str || !s)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }

// char	*strjoin(char *dst, char *src)
// {
// 	int		dstlen;
// 	int		srclen;
// 	char	*result;
// 	int		needle1;
// 	int		needle2;

// 	dstlen = strlen(dst);
// 	srclen = strlen(src);
// 	result = malloc(sizeof(char) * (dstlen + srclen + 1));
// 	if (!result)
// 		return (NULL);
// 	needle1 = 0;
// 	while (needle1 < dstlen)
// 	{
// 		result[needle1] = dst[needle1];
// 		needle1++;
// 	}
// 	needle2 = 0;
// 	while (needle2 < srclen)
// 	{
// 		result[needle1 + needle2] = src[needle2];
// 		needle2++;
// 	}
// 	result[needle1 + needle2] = '\0';
// 	return (result);
// }

// void	*ft_realloc(void *ptr, size_t len)
// {
// 	void	*real;

// 	real = malloc(len);
// 	ft_memset(real, 0, len);
// 	if (real)
// 		ft_memcpy(real, ptr, len);
// 	ptr = NULL;
// 	free(ptr);
// 	return (real);
// }
