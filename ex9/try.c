#include <stdio.h>

int main(int argc, char *argv[])
{
    int ints[] = {1, 2, 3};

    if (1[ints] == ints[1]) {
        printf("YES!\n");
    }

    printf("%d\n", 2[ints]);

    return 0;
}
