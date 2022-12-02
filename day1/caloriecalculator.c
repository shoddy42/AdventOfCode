/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   caloriecalculator.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 06:14:23 by wkonings      #+#    #+#                 */
/*   Updated: 2022/12/02 08:06:50 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

long largest;
long second;
long third;

void	top_three(int new)
{
	long swap;

	if (new > largest)
	{
		swap = third;
		second = largest;
		third = second;
		largest = new;
	}
	else if (new > second)
	{
		swap = third;
		third = second;
		second = new;
	}
	else if (new > third)
	{
		third = new;
	}
}

int main(void)
{
	long	current;
	char	file[20000] = {0};
	char	**split;
	int 	i;
	int		j;
	int		fd;
	int ret;

	largest = 0;
	current = 0;
	fd = open("input", O_RDONLY);
	ret = read(fd, file, 20000);
	split = ft_split(file, '$');
	i = -1;
	while (split[++i])
	{
		j = -1;
		current += atoi(split[i]);
		if (!split[i][1])
		{
			if (current > third)
			{
				printf ("?: [%li]\n", current);
				top_three(current);
			}
			current = 0;
		}
	}
	printf ("largest = [%li]\n", largest);
	printf ("second = [%li]\n", second);
	printf ("third = [%li]\n", third);
	printf ("total = [%li]\n", largest + second + third);
	return (0);
}