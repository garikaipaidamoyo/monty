#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1024

typedef struct {
    int items[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value, int line_num) {
    if (stack->top == STACK_SIZE) {
        fprintf(stderr, "L%d: Stack overflow\n", line_num);
        exit(EXIT_FAILURE);
    }
    stack->items[stack->top++] = value;
}
