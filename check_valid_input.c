#include "libft.h"

int	check_duplicate_digits(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
int	check_special_chars_or_letters(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (j == 0 && (arr[i][j] == '-' || arr[i][j] == '+'))
			{
				j++;
				continue ;
			}
			if (!ft_isdigit((unsigned char)arr[i][j]) || arr[i][j] == '\t')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	check_valid_input(char **arr)
{
	int i = 0;
	int valid = 1;

	if (check_special_chars_or_letters(arr))
	{
		printf("special chars or letters\n");
		valid = 0;
	}
	else if (check_duplicate_digits(arr))
	{
		printf("duplicate digits\n");
		valid = 0;
	}
	else
	{
		while (arr[i])
		{
			if (!check_within_range(arr[i]))
			{
                printf("not within range\n");
				valid = 0;
				break ;
			}
			i++;
		}
	}
	if (valid)
		return (0);
	else
		return (1);
}