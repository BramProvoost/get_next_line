/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 09:00:41 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/11/24 11:23:05 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// https://harm-smits.github.io/42docs/projects/get_next_line.html

// size_t	ft_strlen(const char *str)
// {
// 	size_t	counter;

// 	counter = 0;
// 	if (!str)
// 		return (0);
// 	while (str[counter])
// 		counter++;
// 	return (counter);
// }

void	read_write(int rfd, int wfd)
{
	char	*buf;

	buf = get_next_line(rfd);
	if (buf == NULL)
	{
		write(wfd, "(NULL)", 6);
		return ;
	}
	write(wfd, "[NL]", 4);
	write(wfd, buf, ft_strlen(buf));
	free(buf);
}

int	main(void)
{
	int		counter;
	int		linesToRead;
	int		rfd;
	int		wfd;

	counter = 0;
	linesToRead = 10;
	rfd = open("read1.txt", O_RDONLY);
	wfd = open("write1.txt", O_WRONLY);
	while (counter < linesToRead)
	{
		counter++;
		read_write(rfd, wfd);
	}
	close(rfd);
	close(wfd);
	// system("leaks mandatory");
	// system("leaks bunos");
	return (0);
}
