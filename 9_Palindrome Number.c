/*compare from left and right end to middle*/
bool isPalindrome(int x) {
    if (x < 0)
        return false;
    int left = 1, right = 1;
    while (left <= x / 10)
        left *= 10;
    while (left > right) {
        if (x / left % 10 != x / right % 10)
            return false;
        left /= 10;
        right *= 10;
    }
    return true;
}
