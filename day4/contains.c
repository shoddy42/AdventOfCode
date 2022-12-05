/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contains.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 12:25:46 by root          #+#    #+#                 */
/*   Updated: 2022/12/04 13:05:03 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

int contains(char *s1, char *s2)
{
    int i = 0;
    int min;
    int max;

    int min2;
    int max2;

    min = ft_atoi(s1);
    while (s1[++i] && s1[i] != '-')
        ;
    max = ft_atoi(s1 + i + 1);
    while (s1[++i] && s1[i] != ',')
        ;
    min2 = ft_atoi(s1 + i + 1);
    while (s1[++i] && s1[i] != '-')
        ;
    max2 = ft_atoi(s1 + i + 1);
    if (min <= min2 && max >= max2)
        return (1);
    if (min2 <= min && max2 >= max)
        return (1);
    return (0);
}

int contains_part2(char *s1, char *s2)
{
    int i = -1;
    int min;
    int max;

    int min2;
    int max2;
    min = ft_atoi(s1);
    while (s1[++i] && s1[i] != '-')
        ;
    max = ft_atoi(s1 + i + 1);
    while (s1[++i] && s1[i] != ',')
        ;
    min2 = ft_atoi(s1 + i + 1);
    while (s1[++i] && s1[i] != '-')
        ;
    max2 = ft_atoi(s1 + i + 1);
    if (min2 >= min && min2 <= max)
        return (1);
    if (max2 >= min && max2 <= max)
        return (1);
    if (min >= min2 && min <= max2)
        return (1);
    if (max >= min2 && max <= max2)
        return (1);
    return (0);
}

int main(void)
{
	char	file[15000] = {0};
	char	**split;
	int		input;
	int		i;
	int    	overlapping = 0;

	input = open("input", O_RDONLY);
	read(input, file, 15000);
	split = ft_split(file, '\n');
    overlapping = 0;
	i = -1;
	while (split[++i])
        overlapping += contains(split[i], split[i] + ft_strchr_num(split[i], ',') + 1);
    printf ("overlapping: [%i]\n", overlapping);
    return (0);
}