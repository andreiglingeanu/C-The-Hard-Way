#include <stdio.h>

int main(void)
{
    int a, b;
    char s[3] = "asd";

    scanf("%d,%d;%s", &a, &b, s);

    printf("a = %d, b = %d\n", a, b);
    printf("s = %s\n", s);

    return 0;
}

