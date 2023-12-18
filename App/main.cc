#include <iostream>
#include <cstdlib>
#include <Node.h>

int main() {
    // ������� ������ ������
    LinkedList<int> list;
    // ��������� �������� � ����� ������
    list.push_tail(1, 0);
    list.push_tail(2, 1);
    list.push_tail(3, 2);
    list.push_tail(4, 3);
    // ������� ������ �� �����
    std::cout << list;
    // ��������� �������� � ������ ������
    list.push_head(5, 4);
    list.push_head(6, 5);
    list.push_head(7, 6);
    list.push_head(8, 7);
    // ������� ������ �� �����
    std::cout << list;
    // ������� �������� �� ������ � ����� ������
    list.pop_head();
    list.pop_tail();
    // ������� ������ �� �����
    std::cout << list;
    // ������� �������� � ������������� 3
    list.delete_node(3);
    // ������� ������ �� �����
    std::cout << list;
    // ��������� �������� ���������� ��� x = 2
    std::cout << "Polynomial value at x = 2: " << list.evaluate(2) << std::endl;
    // ������� ������
    list.clear();
    // ������� ������ �� �����
    std::cout << list;
    return 0;
}