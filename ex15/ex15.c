#include <stdio.h>

void first_way(char *names[], int *ages)
{
    int count = 5;
    int i = count - 1;
    while (i >= 0) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
        i--;
    }
}

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    first_way(names, ages);

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    i = count - 1;
    while (i >= 0) {
        printf("%s is %d years old again.\n",
                i[cur_name], i[cur_age]);
        i--;
    }

    printf("---\n");

    // third way using pointers
    for (i = count - 1; i >= 0; i--) {
        printf("%s is %d years old again.\n",
                i[cur_name], i[cur_age]);
    }

    printf("---\n");

    // fourth way using pointers in a stupid complex way
    for (cur_name = (names + count - 1), cur_age = (ages + count - 1);
            (cur_age - ages) >= 0; cur_age--, cur_name--) {
        printf("%s is %d years so far.\n", cur_name[0], cur_age[0]);
    }

    printf("---\n");

    for (i = 0; i < count; i++) {
        printf("name pointer: %p, age pointer: %p\n", cur_name + i, cur_age + i);
    }

    return 0;
}
