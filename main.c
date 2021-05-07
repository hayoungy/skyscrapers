#include <stdio.h>
#include <unistd.h>

void	ft_4(int inp[4][4], int out[4][4]);
void	ft_41(int inp[4][4], int out[4][4]);
void	ft_5(int inp[4][4], int out[4][4]);
void	ft_6(int out[4][4]);
void	ft_7(int inp[4][4], int out[4][4]);

int	print(int out[4][4])
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			write(1, &out[y][x], 1);
			if (x != 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	return (1);
}

void	ft_1(int inp[4][4], int out[4][4])
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (inp[y][x] == 1)
			{
				if (y == 0)
					out[y][x] = '4';
				if (y == 1)
					out[y+2][x] = '4';
				if (y == 2)
					out[x][0] = '4';
				if (y == 3)
					out[x][3] = '4';
			}
		}
	}
}

void	ft_2(int inp[4][4], int out[4][4])
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (inp[y][x] + inp[y+1][x] == 5)
			{
				if (y == 0 && inp[y][x] == 2)
					out[y+1][x] = '4';
				if (y == 0 && inp[y][x] == 3)
					out[y+2][x] = '4';
				if (y == 2 && inp[y][x] == 2)
					out[x][y-1] = '4';
				if (y == 2 && inp[y][x] == 3)
					out[x][y] = '4';
			}
		}
	}
}

void	ft_3(int out[4][4])
{
	int y;
	int x;

	int k;
	int j;
	int i;

	k = 1;
	j = 1;
	i = 1;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (out[y][x] == '4')
			{
				i = i * (x + 1);
				j = j * (y + 1);
				k ++;
			}
		}
	}
	i = (24 / i) - 1;
	j = (24 / j) - 1;
	if (k == 4)
		out[j][i] = '4';
}

int invcnt(char *argv[])
{
	int i;

	i = -1;
	while (argv[1][++i] != '\0')
		;
	if (i != 31)
		return (1);
	return (0);
}

void	minsum(int inp[4][4])
{
	int i;
	int out[4][4];
	
	i = -1;
	if (inp[0][0] == 1)
	{
		static char *tmp1 = "4132241332411324";
		while (++i < 16)
			out[0][i] = tmp1[i] - 48;
	}
	else
	{
		static char *tmp2 = "1324314224134231";
		while (++i < 16)
			out[0][i] = tmp2[i] - 42;
	}
}

int inv1(int inp[4][4])
{
	int i;
	int j;
	int k;
	int sum;
	
	i = -1;
	k = 0;
	sum = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			sum += inp[i][j];
			if (inp[i][j] == 1)
				k++;
			if (inp[i][j] > 4 || inp[i][j] < 1)
				return (1);
		}
	}
	if (sum == 32)
		minsum(inp);
	if (sum < 32 || sum > 36)
		return (1);
	if (k != 4)
		return (1);
	return (0);
}

int inv2(int inp[4][4])
{
	int i;
	int j;
	int sum;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		j = -1;
		while ( ++j < 4)
		{
			sum = inp[i][j]+inp[i+1][j];
			if (sum < 3 || sum > 5)
				return (1);
		}
		i += 2;
	}
	return (0);
}

void madinp()
{
	int i;
	int j;
	int inp[4][4];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			inp[i][j] = 0;
	}
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 2 || invcnt(argv))
		write(1, "Error", 5);
	else
	{	
		int i;
		int j;
		int inp[4][4];
		int out[4][4];

		madinp();
		i = 0;
		j = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] != ' ')
				{
					inp[0][j] = argv[1][i] - 48;
					j++;
				}			
			i++;
		}
		if (inv1(inp) || inv2(inp))
		{
			write(1, "Error", 5);
		}
	}
	ft_1(inp, out);
	ft_2(inp, out);
	ft_3(out);
	ft_4(inp, out);
	ft_41(inp, out);
	ft_5(inp, out);
	ft_6(out);
	ft_7(inp, out);
	print(out);
	return (0);
}
