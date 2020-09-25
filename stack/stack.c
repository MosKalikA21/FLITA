#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <assert.h>
#include "stack.h"

size_t STACK_DEFAULT_CAPACITY = 8;  // Вместимость стека по-умолчанию
size_t STACK_EXPANDING_K = 2;  // Стратегия увеличения вместимости (коэффициент)

// Увеличить вместимость стека (объявляем в этом файле, чтобы сделать функцию приватной)
void expand_stack(Stack* stack);

Stack* create_stack() {
    return create_stack_with_capacity(STACK_DEFAULT_CAPACITY);
}

Stack* create_stack_with_capacity(size_t capacity) {
    // Выделяем память под структуру стека
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) {
        return NULL;
    }

    // Выделяем память под буфер стека
    stack->buffer = (StackValue*) malloc(capacity * sizeof(StackValue));
    if (!stack->buffer) {
        destroy_stack(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack* stack) {
    if (!stack) {
        return;
    }

    if (stack->buffer) {
        free(stack->buffer);
    }
    free(stack);
}

bool is_empty_stack(Stack* stack) {
    return !stack || stack->size == 0;
}

bool is_full_stack(Stack* stack) {
    return stack && stack->size == stack->capacity;
}

void push_stack(Stack* stack, StackValue value) {
    if (!stack) {
        return;
    }

    // Если стек заполнен полностью, увеличиваем его вместимость
    if (is_full_stack(stack)) {
        expand_stack(stack);
    }

    // Кладем элемент в буфер
    stack->buffer[stack->size++] = value;
}

StackValue pop_stack(Stack* stack) {
    assert(stack && stack->size > 0);
    return stack->buffer[--stack->size];
}

void clear_stack(Stack* stack) {
    if (stack) {
        stack->size = 0;
    }
}

void print_stack(Stack* stack) {
    if (!stack) {
        return;
    }

    printf("[");
    for (size_t i = 0; i < stack->size; ++i) {
        printf("%d%s", stack->buffer[i], i < (stack->size - 1) ? ", " : "");
    }
    printf("] <->\n");
}

void expand_stack(Stack* stack) {
    if (!stack) {
        return;
    }

    size_t new_capacity = stack->capacity * STACK_EXPANDING_K;
    // Выделяем память под новый буфер большего размера
    StackValue* new_buffer = (StackValue*) malloc(new_capacity);
    if (!new_buffer) {
        return;
    }

    // Копируем содержимое старого буфера в новый, после чего освобождаем старый
    memcpy(new_buffer, stack->buffer, stack->size * sizeof(StackValue));
    free(stack->buffer);

    // Сохраняем новый буфер и новое значение вместимости
    stack->buffer = new_buffer;
    stack->capacity = new_capacity;
}