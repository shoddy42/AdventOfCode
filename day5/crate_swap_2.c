#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

int	**move(int amount, int from, int to, int **crates)
{
	int	backup = amount;
	int move = amount;

	while (amount)
	{
		printf ("top from = [%c], top to = [%c]\n", crates[from][crates[from][0]], crates[to][crates[to][0]]);
		crates[to][crates[to][0] + amount] = crates[from][crates[from][0]]; 
		// crates[to][0]++;
		crates[from][crates[from][0]] = 0;
		crates[from][0]--;
		amount--;
	}
	crates[to][0] += backup;
	return (crates);
}

int	**init_crates(int init[9][100])
{
	int **crates;
	int i = -1;
	int	j = -1;
	crates = ft_calloc(9, sizeof(int *));
	while (++i < 9)
		crates[i] = ft_calloc(100, sizeof(int));
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (init[i][++j] != '\0')
		{
			crates[i][j] = init[i][j];
			// printf ("[%c] ", crates[i][j]);
		}
		// printf ("\n");
	}
	return (crates);
}

int	main(void)
{
	int		init[9][100] = {
		{8, 'D', 'T', 'W', 'F', 'J', 'S', 'H', 'N'},
		{8, 'H', 'R', 'P', 'Q', 'T', 'N', 'B', 'G'},
		{3, 'L', 'Q', 'V'},
		{6, 'N', 'B', 'S', 'W', 'R', 'Q'},
		{7, 'N', 'D', 'F', 'T', 'V', 'M', 'B'},
		{7, 'M', 'D', 'B', 'V', 'H', 'T', 'R'},
		{4, 'D', 'B', 'Q', 'J'},
		{8, 'D', 'N', 'J', 'V', 'R', 'Z', 'H', 'Q'},
		{5, 'B', 'N', 'H', 'M', 'S'}
	};

	int		**crates;
	char	file[15000] = {0};
	char	**split;
	int		fd;
	int 	ret;

	
	fd = open("input.txt", O_RDONLY);
	ret = read(fd, file, 15000);
	split = ft_split(file, '\n');

	int 	i;
	int		j;
	int amount;
	int from;
	int to;
	i = -1;
	crates = init_crates(init);
	while (split[++i])
	{
		// printf ("split[%i] = [%s]\n", i, split[i]);
		j = 0;
		while (!ft_isdigit(split[i][j]))
			j++;
		amount = ft_atoi(split[i] + j);
		while (ft_isdigit(split[i][j]))
			j++;
		while (!ft_isdigit(split[i][j]))
			j++;
		from = ft_atoi(split[i] + j);
		while (ft_isdigit(split[i][j]))
			j++;
		while (!ft_isdigit(split[i][j]))
			j++;
		to = ft_atoi(split[i] + j);
		// printf("a: %i f: %i t: %i\n", amount, from, to);
		crates = move(amount, from - 1, to - 1, crates);
	}
	printf ("top [%c%c%c%c%c%c%c%c%c]\n", crates[0][crates[0][0]], crates[1][crates[1][0]], crates[2][crates[2][0]],
	crates[3][crates[3][0]], crates[4][crates[4][0]], crates[5][crates[5][0]],crates[6][crates[6][0]],
	crates[7][crates[7][0]], crates[8][crates[8][0]]);
	// printf ("test %i\n", ret);
	return (0);
}