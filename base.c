#include <stdio.h>
#include <stdlib.h>

// Определение узла стека
typedef struct  s_node {
    int             value;  // Значение узла
    struct s_node   *next;  // Указатель на следующий узел в стеке
}               t_node;

// Определение структуры стека
typedef struct  s_list {
    t_node *top;  // Вершина стека
}               t_list;

// Функция для добавления элемента в стек
void    push(t_list *stack, int value) {
    t_node *new = malloc(sizeof(t_node));  // Выделение памяти для нового узла
    if (!new) return;  // Проверка на успешное выделение памяти
    new->value = value;  // Присваивание значения узлу
    new->next = stack->top;  // Установка нового узла на вершину стека
    stack->top = new; 
	return 0; // Обновление вершины стека
}

// Функция для удаления элемента из стека
int     pop(t_list *stack) {
    if (stack->top == NULL) return -1;  // Проверка на пустой стек
    t_node *top = stack->top;  // Сохранение текущей вершины стека
    int value = top->value;  // Сохранение значения вершины
    stack->top = top->next;  // Обновление вершины стека
    free(top);  // Освобождение памяти удаленного узла
    return value;  // Возвращение значения удаленного узла
}

// Функция для обмена двух верхних элементов стека
void    swap(t_list *stack) {
    if (stack->top == NULL || stack->top->next == NULL) return;  // Проверка на достаточное количество элементов
    t_node *first = stack->top;  // Первый элемент
    t_node *second = first->next;  // Второй элемент
    first->next = second->next;  // Переназначение ссылки на следующий элемент
    second->next = first;  // Обмен элементами
    stack->top = second;  // Обновление вершины стека
}

// Функция для сортировки трех элементов в стеке
void    sort_three(t_list *stack) {
    // Получение значений трех верхних элементов стека
    int a = stack->top->value;
    int b = stack->top->next->value;
    int c = stack->top->next->next->value;

    // Сортировка с помощью операций swap и rotate
    // Различные комбинации сравнений и перемещений для достижения отсортированного состояния
    if (a > b && b > c) {
        swap(stack);
        push(stack, pop(stack)); // rotate
    } else if (a > b && a < c) {
        swap(stack);
    } else if (a > c && b < c) {
        push(stack, pop(stack)); // rotate
    } else if (a < b && a > c) {
        push(stack, pop(stack)); // rotate
        swap(stack);
    } else if (a < c && b > c) {
        push(stack, pop(stack)); // rotate
        push(stack, pop(stack)); // rotate
    }
    // Если не попадает под предыдущие условия, стек уже отсортирован
}

int main() {
    t_list stack;  // Создание стека
    stack.top = NULL;  // Инициализация пустого стека

    // Добавление чисел в стек
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);

    // Сортировка стека
    sort_three(&stack);

    // Вывод отсортированного стека
    while (stack.top != NULL) {
        printf("%d\n", pop(&stack));
    }

    return 0;
}
