int	check_empty_str(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != ' ' && argv[i][j] != '\t')
				break ;
			j++;
		}
		if (argv[i][j] == '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}