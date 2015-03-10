/*arrange s into (2 * nrows - 2) characters per group
 *caculate and fetch each character*/
char *convert(char *s, int nrows) {
    int length = strlen(s), end = 0, step = 2 * nrows - 2, p, first, second;
    char *result = (char *)malloc((length + 1) * sizeof(char));
    /*special case when nRows == 1*/
    if (nrows == 1) {
        strncpy(result, s, length + 1);
    } else {
        /*the first row*/
        for (p = 0; p < length; p += step)
            result[end++] = s[p];
        /*the row(s) between the first one and the last one*/
        for (first = 1, second = step - 1; first < nrows - 1; ++first, --second) {
            for (p = 0; ; p += step) {
                if (p + first >= length)
                    break;
                result[end++] = s[p + first];
                if (p + second >= length)
                    break;
                result[end++] = s[p + second];
            }
        }
        /*the last row*/
        if (nrows > 1)
            for (p = nrows - 1; p < length; p += step)
                result[end++] = s[p];
        result[end] = '\0';
    }
    return result;
}

int main(void) {
    char s[100];
    int nrows;
    while (~scanf("%s%d", s, &nrows))
        puts(convert(s, nrows));
    return 0;
}
