#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

/* Struct definitions for stack {{{ */

struct Element {
    int set;
    int value;
};

struct Stack {
    struct Element elements[MAX_ELEMENTS];
};

/* }}} Struct definitions for stack */

/* Push {{{ */

void Stack_push(struct Stack *stack, int value)
{
    int i = 0;

    while (stack->elements[i].set)
        i++;

    stack->elements[i].set = 1;
    stack->elements[i].value = value;
}

/* }}} Push */
/* Pop {{{ */

struct Element Stack_pop(struct Stack *stack)
{
    int i = 0;

    for (i = MAX_ELEMENTS - 1; i >= 0; i--) {
        if (stack->elements[i].set) {
            break;
        }
    }

    stack->elements[i].set = 0;

    return stack->elements[i];
}

/* }}} Pop */

/* Print the stack {{{ */

void Print_stack(struct Stack *stack)
{
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (stack->elements[i].set) {
            printf("%d ", stack->elements[i].value);
        } else {
            break;
        }
    }
    printf("\n");
}

/* }}} Print the stack */

int main(int argc, char *argv[])
{
    struct Stack *stack = malloc(sizeof(struct Stack));

    int i = 0;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        struct Element el = { .set = 0, .value = -1 };
        stack->elements[i] = el;
    }

    Stack_push(stack, 20);
    Stack_push(stack, 21);
    Stack_push(stack, 22);
    Stack_push(stack, 23);
    Stack_push(stack, 24);

    Print_stack(stack);

    printf("poped: %d\n", Stack_pop(stack).value);
    printf("poped: %d\n", Stack_pop(stack).value);

    Print_stack(stack);

    free(stack);

    return 0;
}
