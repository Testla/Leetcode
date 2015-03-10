int reverse(int x) {
    int sign = 1, result = 0;
    if (x < 0) {
        sign = -1;
        x *= -1;
    }
    while (x) {
        if (result > (INT_MAX - x % 10) / 10)  /*overflow detected*/
            return 0;
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result * sign;
}

