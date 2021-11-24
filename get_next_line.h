/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 16:46:57 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/11/24 11:00:51 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);

int		fd_not_valid(int fd);

char	*str_join_until_nl(char *dst, char *src);

int		no_nl_in(char *buffer);

char	*my_malloc(char *dst, char *src);

size_t	ft_strlen(const char *str);

int		read_nothing_or_error(int read_return);

void	save_str_after_nl(char *str);

#endif
