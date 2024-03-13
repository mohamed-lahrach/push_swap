long ft_atol(const char *str)
{
    long result;
    long sign;

    result = 0;
    sign = 1;
    if (*str == '-')
    {
        sign *= -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (sign * result);
}
