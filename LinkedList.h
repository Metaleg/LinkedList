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
    LinkedList():first(NULL), size(0){}
    ~LinkedList();

    void add(int d);
    void show();

    int getSize() const;
    bool isEmpty() const;
    int& operator[](int); // Неконстантный оператор получения ссылки на i-й элемент
    const int& operator[](int) const; // Константный оператор получения ссылки.
    void push_front(int val); // Добавление элемента в начало списка
    void pop_front(); // Удаление элемента из начала списка
    int& get_front(); // Получение первого элемента
    const int& get_front() const; // Аналогично, как и в случае с операторами []
    void insert(int pos, int val); // Добавить новый элемент в заданную позицию
    void erase(int pos); // Удалить определенный элемент
};


#endif //LINKEDLIST_LINKEDLIST_H
