/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 09:00:41 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/20 21:14:03 by bprovoos      ########   odam.nl         */
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

void	read_write(int r, int w)
{
	char	*buf;

	buf = get_next_line(r);
	if (buf == NULL)
	{
		write(w, "[NL](NULL)\n", 11);
		return ;
	}
	write(w, "[NL]", 4);
	write(w, buf, ft_strlen(buf));
	write(w, "\n", 1);
	free(buf);
}

int	main(void)
{
	int		linesToRead;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;

	linesToRead = 7;
	fd1 = open("test_get_next_line/read1.txt", O_CREAT | O_RDONLY);
	system("rm -rf test_get_next_line/write1.txt");
	fd2 = open("test_get_next_line/write1.txt", O_CREAT | O_WRONLY, 0644);
	fd3 = open("test_get_next_line/read2.txt", O_CREAT | O_RDONLY);
	system("rm -rf test_get_next_line/write2.txt");
	fd4 = open("test_get_next_line/write2.txt", O_CREAT | O_WRONLY, 0644);
	fd5 = open("test_get_next_line/read3.txt", O_CREAT | O_RDONLY);
	system("rm -rf test_get_next_line/write3.txt");
	fd6 = open("test_get_next_line/write3.txt", O_CREAT | O_WRONLY, 0644);
	if (fd1 == -1)
		printf("fd1 = -1\n");
	if (fd3 == -1)
		printf("fd3 = -1\n");
	while (linesToRead > 0)
	{
		read_write(fd1, fd2);
		read_write(fd3, fd4);
		read_write(fd1, fd2);
		read_write(fd5, fd6);
		linesToRead--;
	}
	// system("leaks a.out");
	return (0);
}
