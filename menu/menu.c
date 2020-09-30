#include <assert.h>
#include <stdio.h>
#include <menu.h>

void menu_push_stack(Stack* stack) {
    assert(stack);

    printf("Number to push: ");

    StackValue value;
    scanf("%d", &value);

    push_stack(stack, value);

    printf("Stack was successfully pushed\n\n");
}

void menu_pop_stack(Stack* stack) {
    assert(stack);

    if (is_empty_stack(stack)) {
        printf("Stack is empty\n\n");
        return;
    }

    StackValue value = pop_stack(stack);
    printf("Popped value from stack: %d\n\n", value);
}

void menu_clear_stack(Stack* stack) {
    assert(stack);

    if (is_empty_stack(stack)) {
        printf("Stack is already empty\n\n");
        return;
    }

    clear_stack(stack);
    printf("Successfully cleared stack\n\n");
}

void menu_print_stack_info(Stack* stack) {
    assert(stack);

    printf("Data structure: STACK (LIFO)\n"
           "Elements type: int\n"
           "Current size: %lu\n"
           "Current capacity: %lu\n\n", stack->size, stack->capacity);
}

void menu_print_stack_contents(Stack* stack) {
    assert(stack);

    if (is_empty_stack(stack)) {
        printf("Stack is empty\n\n");
        return;
    }

    printf("Stack contents:\n\t");
    print_stack(stack);
    printf("\n\n");
}
