#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        for (int j = 0; j < strlen(*(argv + i)); ++j)
            printf("%c", *(*(argv + i) + j));
        printf("\n");
    }
    return 0;
}
