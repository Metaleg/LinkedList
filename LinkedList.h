//
// Created by metalleg on 25.02.18.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <iomanip>

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    Node* first;
    int size;
public:
    LinkedList():first(nullptr), size(0){}
    ~LinkedList();

    void show();

    int get_size() const; // Получить размер списка
    bool is_empty() const; // Возвращает true, если список пуст и должен делать это эффективно
    int& operator[](int ind); // Неконстантный оператор получения ссылки на i-й элемент (если такой синтаксис в новинку, то гугли перегрузку операторов.
    const int& operator[](int) const; // Константный оператор получения ссылки. Должна знать, почему он нам нужен и почему не можем ограничиться только первым (см. const у методов)
    void push_front(int val); // Добавление элемента в начало списка
    void pop_front(); // Удаление элемента из начала списка
    int& get_front(); // Получение первого элемента
    const int& get_front() const; // Аналогично, как и в случае с операторами []
    void insert(int pos, int val); // Добавить новый элемент в заданную позицию
    void erase(int pos); // Удалить определенный элемент
};


#endif //LINKEDLIST_LINKEDLIST_H
