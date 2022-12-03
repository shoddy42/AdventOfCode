/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sum_of_sacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 10:03:52 by root          #+#    #+#                 */
/*   Updated: 2022/12/03 10:34:58 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

int priority (char c)
{
    if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
    if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 27);
    return (0);
}

int    find_match(char *s)
{
	int	i = -1;
	int half = ft_strlen(s) / 2;

	while (++i < half)
		if (ft_charinstr(s[i], s + half) == true)
			return (priority(s[i]));
    return (0);
}

int	find_badge(char *s1, char *s2, char *s3)
{
	int i = -1;
	
	while (s1[++i])
		if (ft_charinstr(s1[i], s2) && ft_charinstr(s1[i], s3))
			return (priority(s1[i]));
	return (0); 
}

int main(void)
{
	char	file[10000] = {0};
	char	**split;
	int		input;
	int		i;
	int    	sum = 0;

	input = open("input", O_RDONLY);
	read(input, file, 10000);
	split = ft_split(file, '\n');
    sum = 0;
	//part 1
	i = -1;
	while (split[++i])
        sum += find_match(split[i]);
	//part 2
	// i = 0;
	// while (split[i] && split[i + 1] && split[i + 2])
	// {
	// 	sum += find_badge(split[i], split[i + 1], split[i + 2]);
	// 	i += 3;
	// }
    printf ("sum: [%i]\n", sum);
	return (0);
}