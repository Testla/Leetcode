#include <stdio.h>

typedef enum {false, true} bool;

//41ms if I use function here, 24ms if I use macro
//bool can_match(const char s, const char p) {
//    return s == p || p == '.';
//}
#define can_match(s, p) (s == p || p == '.')

bool isMatch(char *s, char *p) {
    if (*s == '\0' || *p == '\0') {
        if (*s == *p)
            return true;
        else if (*s == '\0' && *(p + 1) == '*')
            return isMatch(s, p + 2);
        else
            return false;
    }
    if (*(p + 1) == '*') {
        while (1) {
            if (isMatch(s, p + 2))
                return true;
            if (*s == '\0' || !can_match(*s, *p))
                return false;
            ++s;
        }
    } else {
        if (!can_match(*s, *p))
            return false;
        else
            return isMatch(s + 1, p + 1);
    }
}

int main(void) {
    char s[100], p[100];
    int i;
    while (~scanf("%s%s", s, p))
        puts(isMatch(s, p) ? "Yes" : "No");
    return 0;
}

