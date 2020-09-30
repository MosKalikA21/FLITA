#include <stdio.h>
#include "stack/stack.h"
#include "menu/menu.h"

int main() {
    Stack* stack = create_stack_with_capacity(2);
    if (!stack) {
        printf("Failed to initialize stack\n\n");
        return 1;
    }

    printf("****** STACK ******\n\n");

    while (true) {
        printf("Choose command:\n"
               "\t1 - Push stack\n"
               "\t2 - Pop stack\n"
               "\t3 - Clear stack\n"
               "\t4 - Print stack info\n"
               "\t5 - Print stack contents\n"
               "\t6 - Exit\n\n");

        int cmd;
        scanf("%d", &cmd);

        if (cmd == 1) {
            menu_push_stack(stack);
        } else if (cmd == 2) {
            menu_pop_stack(stack);
        } else if (cmd == 3) {
            menu_clear_stack(stack);
        } else if (cmd == 4) {
            menu_print_stack_info(stack);
        } else if (cmd == 5) {
            menu_print_stack_contents(stack);
        } else if (cmd == 6) {
            break;
        } else {
            printf("Error: Unknown command\n\n");
        }
    }
    
    destroy_stack(stack);

    return 0;}
