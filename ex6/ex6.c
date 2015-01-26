#include <stdio.h>

int main(int argc, char *argv[])
{

    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed\
Vasea";
    char last_name[] = "Shaw";

    printf("You are %d %d miles away.\n", distance, initial);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n",
            first_name, initial, last_name);

    printf("%o\n", 8);
    printf("%A\n", 8.1231514123123123f);

    printf("%d\n", 0xAA);
    printf("%d\n", 07);

    printf("%s", "");

    return 0;
}
