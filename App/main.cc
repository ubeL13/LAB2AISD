#include <iostream>
#include <cstdlib>
#include <Node.h>

int main() {
    // Создаем пустой список
    LinkedList<int> list;
    // Добавляем элементы в конец списка
    list.push_tail(1, 0);
    list.push_tail(2, 1);
    list.push_tail(3, 2);
    list.push_tail(4, 3);
    // Выводим список на экран
    std::cout << list;
    // Добавляем элементы в начало списка
    list.push_head(5, 4);
    list.push_head(6, 5);
    list.push_head(7, 6);
    list.push_head(8, 7);
    // Выводим список на экран
    std::cout << list;
    // Удаляем элементы из начала и конца списка
    list.pop_head();
    list.pop_tail();
    // Выводим список на экран
    std::cout << list;
    // Удаляем элементы с коэффициентом 3
    list.delete_node(3);
    // Выводим список на экран
    std::cout << list;
    // Вычисляем значение многочлена при x = 2
    std::cout << "Polynomial value at x = 2: " << list.evaluate(2) << std::endl;
    // Очищаем список
    list.clear();
    // Выводим список на экран
    std::cout << list;
    return 0;
}