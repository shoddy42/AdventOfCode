/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signal.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 09:01:45 by wkonings      #+#    #+#                 */
/*   Updated: 2022/12/06 09:33:09 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

bool ft_hasduplicates(char *str)
{
	char	table[256];
	int		i;

	i = -1;
	ft_bzero(table, 256);
	while (str[++i])
		table[str[i]]++;
	i = -1;
	while (++i < 256)
		if (table[i] > 1)
			return (true);
	return (false);
}

//adjust this to relevant marker size (for part 1 its 4, for part 2 its 15)
#define	MARKER_SIZE 4
// #define MARKER_SIZE 15

int	main(void)
{
	char	file[5000] = {0};
	char	marker[MARKER_SIZE + 1] = {0};
	int		fd;

	fd = open("input.txt", O_RDONLY);
	read(fd, file, 5000);

	int x;
	int i = -1;
	while (file[++i])
	{
		x = -1;
		while (++x < MARKER_SIZE)
			marker[x] = file[i + x];
		if (ft_hasduplicates(marker) == false)
			break ;
	}
	printf ("?: %i str = [%s]\n", i + MARKER_SIZE, marker);
	return (0);
}