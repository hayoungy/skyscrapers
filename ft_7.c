void	col_ft_7(int inp[4][4], int out[4][4])
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (inp[0][j] + inp[1][j] == 5)
		{
			if (inp[0][j] == 1)
				out[3][j] = '1';
			else if (inp[0][j] == 4)
				out[0][j] = '1';
			else if (inp[0][j] == 2 && out[0][j] == '3')
				out[2][j] = '2';
			else if (inp[0][j] == 3 && out[3][j] == '3')
				out[1][j] = '2';
		}
		if (inp[0][j] == inp[1][j])
		{
			if (out[0][j] == out[1][j])
				out[0][j] = '2';
			else if (out[2][j] == out[3][j])
				out[3][j] = '2';
		}
	}
}

void	row_ft_7(int inp[4][4], int out[4][4])
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (inp[2][j] + inp[3][j] == 5)
		{
			if (inp[2][j] == 1)
				out[j][3] = '1';
			else if (inp[2][j] == 4)
				out[j][0] = '1';
			else if (inp[2][j] == 2 && out[j][0] == '3')
				out[j][2] = '2';
			else if (inp[2][j] == 3 && out[j][3] == '3')
				out[j][1] = '2';
		}
		if (inp[2][j] == inp[3][j])
		{
			if (out[j][0] == out[j][1])
				out[j][0] = '2';
			else if (out[j][2] == out[j][3])
				out[j][3] = '2';
		}
	}
}

void	row_sum(int out[4][4])
{
	int i;
	int j;
	int x;
	int y;
	int sum;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		sum = 250;
		while (++j < 4)
		{
			sum -= out[i][j];
			if (out[i][j] == '0')
			{
				x = i;
				y = j;
			}
		}
		if (sum == 49 || sum == 50)
			out[x][y] = sum;
	}
}

void	col_sum(int out[4][4])
{
	int i;
	int j;
	int x;
	int y;
	int sum;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		sum = 250;
		while (++i < 4)
		{
			sum -= out[i][j];
			if (out[i][j] == '0')
			{
				x = i;
				y = j;
			}
		}
		if (sum == 49 || sum == 50)
			out[x][y] = sum;
	}
}

void	ft_7(int inp[4][4], int out[4][4])
{
	int i;
	int j;
	int cnt;

	col_ft_7(inp, out);
	row_ft_7(inp, out);
	i = -1;
	cnt = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (out[i][j] == ' ')
				out[i][j] = '0';
		}
	}
	while (++cnt < 8)
	{
		row_sum(out);
		col_sum(out);
	}
}
