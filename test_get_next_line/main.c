/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 09:00:41 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/20 14:41:41 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// https://harm-smits.github.io/42docs/projects/get_next_line.html

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

int	main(void)
{
	int		linesToRead;
	int		fd1;
	int		fd2;
	char	*buf1;

	linesToRead = 1;
	fd1 = open("test_get_next_line/read1.txt", O_RDONLY);
	system("rm -rf test_get_next_line/write1.txt");
	fd2 = open("test_get_next_line/write1.txt", O_CREAT | O_WRONLY, 0644);
	if (fd1 == -1)
		printf("fd = -1\n");
	while (linesToRead > 0)
	{
		buf1 = get_next_line(fd1);
		if (buf1 == NULL)
		{
			write(fd2, "[NL](NULL)", 10);
			break ;
		}
		write(fd2, "[NL]", 4);
		write(fd2, buf1, ft_strlen(buf1));
		if (linesToRead != 1)
		{
			write(fd2, "\n", 1);
		}
		free(buf1);
		linesToRead--;
	}
	// system("leaks a.out");
	return (0);
}
