/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 16:50:24 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/11/24 11:03:54 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	fd_not_valid(int fd)
{
	return (fd < 0 || fd > OPEN_MAX);
}

int	read_nothing_or_error(int read_return)
{
	return (read_return <= 0);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter])
		counter++;
	return (counter);
}
