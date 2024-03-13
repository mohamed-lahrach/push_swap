int check_within_range(const char *str)
{
    long num = 0;
    int sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    if (*str == '\0')
        return 0;
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        if (sign == 1 && num > 2147483647)
            return 0;
        if (sign == -1 && -num < -2147483648)
            return 0;
        str++;
    }
    return 1;
}