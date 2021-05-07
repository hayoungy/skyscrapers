void	ft_5(int inp[4][4], int out[4][4])
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (inp[i][j] == 3 && i == 0)
				out[0][j] = ' ';
			else if (inp[i][j] == 3 && i == 1)
				out[3][j] = ' ';
			else if (inp[i][j] == 3 && i == 2)
				out[j][0] = ' ';
			else if (inp[i][j] == 3 && i == 3)
				out[j][3] = ' ';
		}
		j = -1;
	}
}
