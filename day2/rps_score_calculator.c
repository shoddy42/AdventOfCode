/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rps_score_calculator.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wkonings <wkonings@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 07:43:27 by wkonings      #+#    #+#                 */
/*   Updated: 2022/12/02 08:07:10 by wkonings      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

uint64_t add_score_round_one(char *s)
{
	uint64_t score = 0;

	if (s[2] == 'X')
		score += 1;
	else if (s[2] == 'Y')
		score += 2;
	else if (s[2] == 'Z')
		score += 3;


	if (s[0] == 'A' && s[2] == 'X')
		score += 3;
	else if (s[0] == 'B' && s[2] == 'Y')
		score += 3;
	else if (s[0] == 'C' && s[2] == 'Z')
		score += 3;
	
	if (s[0] == 'A' && s[2] == 'Y')
		score += 6;
	if (s[0] == 'B' && s[2] == 'Z')
		score += 6;
	if (s[0] == 'C' && s[2] == 'X')
		score += 6;


	return (score);
}

uint64_t add_score(char *s)
{
	uint64_t score = 0;

	if (s[2] == 'X')
		score += 0;
	else if (s[2] == 'Y')
		score += 3;
	else if (s[2] == 'Z')
		score += 6;

	if (s[0] == 'A' && s[2] == 'X')
		score += 3;
	if (s[0] == 'A' && s[2] == 'Y')
		score += 1;
	if (s[0] == 'A' && s[2] == 'Z')
		score += 2;

	if (s[0] == 'B' && s[2] == 'X')
		score += 1;
	if (s[0] == 'B' && s[2] == 'Y')
		score += 2;
	if (s[0] == 'B' && s[2] == 'Z')
		score += 3;

	if (s[0] == 'C' && s[2] == 'X')
		score += 2;
	if (s[0] == 'C' && s[2] == 'Y')
		score += 3;
	if (s[0] == 'C' && s[2] == 'Z')
		score += 1;

	return (score);
}

int main(void)
{
	char	file[10000] = {0};
	char	**split;
	int		input;
	int		i;
	int		j;
	uint64_t	score = 0;

	input = open("input", O_RDONLY);
	read(input, file, 10000);
	split = ft_split(file, '\n');
	i = -1;
	while (split[++i])
	{
		printf ("%s\n", split[i]);
		score += add_score(split[i]);
	}
	printf ("score: [%llu]\n", score);
	return (0);
}