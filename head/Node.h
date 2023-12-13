
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

    // Добавление элемента в конец списка
    void push_tail(const T& coeff, int deg) {
        Node<T>* newNode = new Node<T>(coeff, deg);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    // Добавление другого списка в конец списка
    void push_tail(const LinkedList<T>& other) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->coefficient, current->degree);
            current = current->next;
        }
    }

    // Добавление элемента в начало списка
    void push_head(const T& coeff, int deg) {
        Node<T>* newNode = new Node<T>(coeff, deg);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    // Добавление списка в начало списка
    void push_head(const LinkedList<T>& other) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_head(current->coefficient, current->degree);
            current = current->next;
        }
    }

    // Удаление элемента из начала списка
    void pop_head() {
        if (head == nullptr) {
            return;
        }
        else if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node<T>* temp = head;
            head = head->next;
            current->next = head;
            delete temp;
        }
        size--;
    }

    // Удаление элемента из конца списка
    void pop_tail() {
        if (head == nullptr) {
            return;
        }
        else if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* current = head;
            while (current->next->next != head) {
                current = current->next;
            }
            Node<T>* temp = current->next;
            current->next = head;
            delete temp;
        }
        size--;
    }

    // Удаление всех элементов Node с информационным полем, равным переданному
    void delete_node(const T& coeff) {
        if (head == nullptr) {
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;
        do {
            if (current->coefficient == coeff) {
                Node<T>* temp = current;
                if (current == head) {
                    head = current->next;
                    if (head == current) {
                        head = nullptr;
                    }
                }
                if (prev != nullptr) {
                    prev->next = current->next;
                }
                current = current->next;
                delete temp;
                size--;
            }
            else {
                prev = current;
                current = current->next;
            }
        } while (current != head);
    }

    // Операция доступа по индексу для чтения
    const Node<T>& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return *current;
    }

    // Операция доступа по индексу для записи
    Node<T>& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return *current;
    }
    // Получение размера списка
    int getSize() const {
        return size;
    }

    // Очистка списка
    void clear() {
        if (head == nullptr) {
            return;
        }

        Node<T>* current = head;
        while (current->next != head) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        delete current;
        head = nullptr;
        size = 0;
    }

    // Вычисление значения многочлена при заданном значении x
    T evaluate(T x) const {
        T result = 0;
        Node<T>* current = head;
        if (current != nullptr) {
            do {
                result += current->coefficient * pow(x, current->degree);
                current = current->next;
            } while (current != head);
        }
        return result;
    }
};
