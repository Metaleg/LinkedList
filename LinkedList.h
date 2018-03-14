//
// Created by metalleg on 25.02.18.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <iomanip>
#include <memory>

struct Node {
    int data;
    std::unique_ptr<Node> next;
};

class LinkedList {
    std::unique_ptr<Node> first;
    int size;
public:
    LinkedList():first(nullptr), size(0){}
    LinkedList(const LinkedList& list);
    LinkedList(LinkedList&& list);
    LinkedList& operator=(const LinkedList& list);
    LinkedList& operator=(LinkedList&& list);
    virtual ~LinkedList() = default;

    void show();

    int get_size() const;
    bool is_empty() const;
    int operator[](int ind);
    const int operator[](int) const;
    void push_front(int val);
    void pop_front();
    int get_front();
    const int get_front() const;
    void insert(int pos,int val);
    void erase(int pos);
    void clear();
};


#endif //LINKEDLIST_LINKEDLIST_H
