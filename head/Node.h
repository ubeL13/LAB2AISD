
#include <iostream>
#include <cstdlib>

// Структура представления элемента списка
template <typename T>
struct Node {
    T coefficient;
    int degree;
    Node<T>* next;

    Node() : next(nullptr) {}
    Node(const T& coeff, int deg) : coefficient(coeff), degree(deg), next(nullptr) {}
};

// Класс связного списка
template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Указатель на начало списка
    int size;       // Размер списка

public:
    LinkedList() : head(nullptr), size(0) {}
    LinkedList(const LinkedList<T>& other) : head(nullptr), size(0) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->coefficient, current->degree);
            current = current->next;
        }
    }

    // Деструктор
    ~LinkedList() {
        clear();
    }

    // Операция присваивания
    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) return *this;

        clear();
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->coefficient, current->degree);
            current = current->next;
        }
        return *this;
    }

};