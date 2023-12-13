
#include <iostream>
#include <cstdlib>

// ��������� ������������� �������� ������
template <typename T>
struct Node {
    T coefficient;
    int degree;
    Node<T>* next;

    Node() : next(nullptr) {}
    Node(const T& coeff, int deg) : coefficient(coeff), degree(deg), next(nullptr) {}
};

// ����� �������� ������
template <typename T>
class LinkedList {
private:
    Node<T>* head;  // ��������� �� ������ ������
    int size;       // ������ ������

public:
    LinkedList() : head(nullptr), size(0) {}
    LinkedList(const LinkedList<T>& other) : head(nullptr), size(0) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_tail(current->coefficient, current->degree);
            current = current->next;
        }
    }

    // ����������
    ~LinkedList() {
        clear();
    }

    // �������� ������������
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