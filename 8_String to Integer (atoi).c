int myAtoi(char *str) {
    int sign = 1;
    long long result = 0;
    while (isspace(*str))
        ++str;
    if (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1;
        ++str;
    }
    if (!isdigit(*str))  /*invalid*/
        return 0;
    while (isdigit(*str)) { 
        result = result * 10 + *str - '0';
        if (sign == 1 && result > INT_MAX)
            return INT_MAX;
        else if (sign == -1 && -result < INT_MIN)
            return INT_MIN;
        ++str;
    }
    return (int)(sign * result);
}
