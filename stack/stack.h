#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdbool.h>
#include <zconf.h>

typedef int StackValue;  // Алиас на тип элементов стека

typedef struct {
    StackValue* buffer;  // указатель на буфер для размещения элементов стека
    size_t size;  // текущий размер стека
    size_t capacity;  // текущая вместимость стека (то есть размер буфера)
} Stack;

// создание стека с вместимостью по-умолчанию
Stack* create_stack();
// создание стека с указанной вместимостью
Stack* create_stack_with_capacity(size_t capacity);
// уничтожение стека (освободить ресуры, занимаемые стеком)
void destroy_stack(Stack* stack);

// проверка стека на пустоту (размер=0)
bool is_empty_stack(Stack* stack);
// проверка стека на полную заполненность (размер=вместимости)
bool is_full_stack(Stack* stack);

// положить значение в стек
void push_stack(Stack* stack, StackValue value);
// достать значение из стека
StackValue pop_stack(Stack* stack);
// очистить стек
void clear_stack(Stack* stack);

// показать содержимое стека в стандартный поток вывода
void print_stack(Stack* stack);

#endif //STACK_STACK_H
