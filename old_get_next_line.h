/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   old_get_next_line.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 09:26:29 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/19 08:53:19 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OLD_GET_NEXT_LINE_H
# define OLD_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*ft_memset(void *str, int c, size_t n);

char	*ft_strlendump(const char *str, size_t length);

#endif
