/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 08:53:39 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/20 17:09:10 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*ft_realloc(void *ptr, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
