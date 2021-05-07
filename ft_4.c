void	ft_4(int inp[4][4], int out[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		while (++j < 4)
		{
			if (inp[i][j] + inp[i + 1][j] == 3)
			{
				if (inp[i][j] == 1 && i == 0)
					out[3][j] = '3';
				else if (inp[i][j] == 2 && i == 0)
					out[0][j] = '3';
				else if (inp[i][j] == 1 && i == 2)
					out[j][3] = '3';
				else
					out[j][0] = '3';
			}
		}
		j = -1;
		i += 2;
	}
}
void	ft_41(int inp[4][4], int out[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		while (++j < 4)
		{
			if (inp[i][j] + inp[i + 1][j] == 5)
			{
				if (inp[i][j] == 1 && i == 0)
					out[1][j] = '3';
				else if (inp[i][j] == 4 && i == 0)
					out[2][j] = '3';
				else if (inp[i][j] == 1 && i == 2)
					out[j][1] = '3';
				else if (inp[i][j] == 4 && i == 2)
					out[j][2] = '3';
			}
		}
		j = -1;
		i += 2;
	}
}
