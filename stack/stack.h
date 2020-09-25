#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdbool.h>
#include <zconf.h>

typedef int StackValue;  // Алиас на тип элементов стека

typedef struct {
    StackValue* buffer;  // Указатель на буфер для размещения элементов стека
    size_t size;  // Текущий размер стека
    size_t capacity;  // Текущая вместимость стека (размер буфера)
} Stack;

// Создать стек с вместимостью по-умолчанию
Stack* create_stack();
// Создать стек с указанной вместимостью
Stack* create_stack_with_capacity(size_t capacity);
// Уничтожить стек (освободить ресуры, занимаемые стеком)
void destroy_stack(Stack* stack);

// Проверка стека на пустоту (размер = 0)
bool is_empty_stack(Stack* stack);
// Проверка стека на полную заполненность (размер = вместимости)
bool is_full_stack(Stack* stack);

// Положить значение в стек
void push_stack(Stack* stack, StackValue value);
// Достать значение из стека
StackValue pop_stack(Stack* stack);
// Очистить стек
void clear_stack(Stack* stack);

// Распечать содержимое стека в стандартный поток вывода
void print_stack(Stack* stack);

#endif //STACK_STACK_H
