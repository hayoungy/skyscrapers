#include <stdio.h>

void	except(int out[4][4], int i, int j)
{
	int x;
	int y;

	x = -1;
	if (out[i][j] == '3')
	{
		while (++x < 4)
		{
			y = -1;
			while (++y < 4)
			{
				if ((i == x || j == y) && out[x][y] == '0')
					out[x][y] = ' ';
			}
		}
	}
}

void	row_check_6(int out[4][4])
{
	int cnt;
	int a;
	int b;
	int c;
	int d;

	a = -1;
	while (++a < 4)
	{
		b = -1;
		cnt = 0;
		while (++b < 4)
		{
			if (out[a][b] == '0')
			{
				cnt++;
				c = a;
				d = b;
			}
		}
		if (cnt == 1)
			out[c][d] = '3';
	}
}

void	col_check_6(int out[4][4])
{
	int sum;
	int a;
	int b;
	int c;
	int d;

	b = -1;
	while (++b < 4)
	{
		a = -1;
		sum = 0;
		while (++a < 4)
		{
			sum += out[a][b];
			if (out[a][b] == '0')
			{
				c = a;
				d = b;
			}
		}
		if (sum == 100)
			out[c][d] = '3';
	}
}

void	ft_6(int out[4][4])
{
	int i;
	int j;
	int cnt_3;

	cnt_3 = -1;
	while (++cnt_3 < 4)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				except(out, i, j);
		}
		row_check_6(out);
		col_check_6(out);
	}
}
