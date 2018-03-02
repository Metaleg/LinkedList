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
    LinkedList(const LinkedList &list);
    LinkedList operator=(const LinkedList &list);
    ~LinkedList();

    void show();//

    int get_size() const;
    bool is_empty() const;
    int& operator[](int ind);s
    const int& operator[](int) const;
    void push_front(int val);
    void pop_front();
    int& get_front();
    const int& get_front() const;
    void insert(int pos, int val);
    void erase(int pos);
};


#endif //LINKEDLIST_LINKEDLIST_H


/*
В списке еще должны быть конструкторы копирования и перемещения, плюс операторы копирования и перемещения

 вообще про особенности структур данных нужно знать.
 советую изучить подробнее про особенности списков, динамических массивов (векторов), деревьев, хэш-таблиц,
 очередей, стеков, двунаправленных очередей (dequeue) и очередей с приоритетом.
 без этого в программировании вообще никуда)

 сразу замечу, что связку new/delete сейчас используют довольно редко и внутри списка нужно использовать unique_ptr для хранения указателей

в частности смотри либо Boost.Test, либо gtest

 */