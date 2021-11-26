/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/26 12:11:41 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/11/26 12:18:37 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	const int	fd = open("main.c", O_RDONLY);
	char		*line;

	line = "";
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	system("leaks a.out");
	return (0);
}
