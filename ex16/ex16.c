#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

/* Person create {{{ */

struct Person Person_create(char *name, int age, int height, int weight)
{
    struct Person who;

    who.name = strdup(name);
    who.age  = age;
    who.height  = height;
    who.weight  = weight;

    return who;
}

/* }}} Person create */

/* Person destroy {{{ */

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

/* }}} Person destroy */

/* Person print {{{ */

void Person_print(struct Person who)
{
    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

/* }}} Person print */



int main(int argc, char *argv[])
{
    // make two people structures
    struct Person joe = Person_create(
            "Joe Alex", 32, 64, 140);
    struct Person frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    Person_print(joe);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40;
    Person_print(joe);

    frank.age += 20;
    frank.weight += 20;
    Person_print(frank);

    return 0;
}
