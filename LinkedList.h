//
// Created by metalleg on 25.02.18.
//
#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <iomanip>
#include <memory>


class Large_index{
public:
    int index;
    explicit Large_index(int ind):index(ind){}; // explicit посоветовал компилятор
};

class Empty{};


template<class type_data>
struct Node {
    type_data data;
    std::unique_ptr<Node<type_data>> next;
};

template<class type_data>
class LinkedList {
    std::unique_ptr<Node<type_data>> first;
    int size;
public:
    LinkedList():first(nullptr), size(0){}
    LinkedList(const LinkedList<type_data>& list);
    LinkedList(LinkedList<type_data>&& list) noexcept ;
    LinkedList<type_data>& operator=(const LinkedList<type_data>& list);
    LinkedList<type_data>& operator=(LinkedList<type_data>&& list) noexcept ;
    virtual ~LinkedList() = default;

    void show();

    int get_size() const;
    bool is_empty() const;
    type_data operator[](int ind);
    const type_data operator[](int ind) const;
    void push_front(type_data val);
    void pop_front();
    type_data get_front();
    const type_data get_front() const;
    void insert(int pos,type_data val);
    void erase(int pos);
    void clear();
};




/////////////////////////////////////////////////////////////////////////////////////////////////


template<class type_data>
LinkedList<type_data>::LinkedList(const LinkedList<type_data>& list) {
    for (int i = 0; i < list.size; ++i)
        push_front(list[list.size - i - 1]);
    size = list.size;
}

template<class type_data>
LinkedList<type_data>::LinkedList(LinkedList<type_data>&& list) noexcept {
    first = std::move(list.first);
    size = list.size;

    list.first = nullptr;
}

template<class type_data>
LinkedList<type_data>& LinkedList<type_data>::operator=(const LinkedList<type_data>& list) {
    for (int i = 0; i < list.size; ++i)
        push_front(list[list.size - i - 1]);
    return *this;
}

template<class type_data>
LinkedList<type_data>& LinkedList<type_data>::operator=(LinkedList<type_data>&& list) noexcept {
    first = std::move(list.first);
    size = list.size;

    list.first = nullptr;
    return *this;
}

template<class type_data>
int LinkedList<type_data>::get_size() const {return size;}

template<class type_data>
bool LinkedList<type_data>::is_empty() const {
    return first == nullptr;
}

template<class type_data>
void LinkedList<type_data>::push_front(type_data val) {
    std::unique_ptr<Node<type_data>> newnode(new Node<type_data>);
    newnode->data = val;
    newnode->next = std::move(first);
    first = std::move(newnode);
    size++;
}

template<class type_data>
void LinkedList<type_data>::pop_front() {
    if (is_empty())
        throw Empty();
    else{
        first = std::move(first->next);
        size--;
    }
}

template<class type_data>
type_data LinkedList<type_data>::get_front() {
    if (is_empty())
        throw Empty();
    else
        return first->data;
}

template<class type_data>
const type_data LinkedList<type_data>::get_front() const {
    if (is_empty())
        throw Empty();
    else
        return first->data;
}


template<class type_data>
type_data LinkedList<type_data>::operator[](int pos){
    if (pos < size) {
        auto current = first.get();
        for (int i = 0; i < pos; ++i)
            current = current->next.get();
        return current->data;
    }
    else throw Large_index(size);
}

template<class type_data>
const type_data LinkedList<type_data>::operator[](int pos) const {
    if (pos < size) {
        auto current = first.get();
        for (int i = 0; i < pos; ++i)
            current = current->next.get();
        return current->data;
    }
    else throw Large_index(size);
}

template<class type_data>
void LinkedList<type_data>::insert(int pos, type_data val) {
    if (pos < size) {
        std::unique_ptr<Node<type_data>> newnode(new Node<type_data>);
        newnode->data = val;
        auto current = first.get();
        for (int i = 0; i < (pos - 1); ++i)
            current = current->next.get();
        newnode->next = std::move(current->next);
        current->next = std::move(newnode);
        size++;
    }
    else throw Large_index(size);
}

template<class type_data>
void LinkedList<type_data>::erase(int pos) {
    if (pos < size) {
        auto current = first.get();
        for (int i = 0; i < (pos - 1); ++i)
            current = current->next.get();
        auto left = current;
        current = current->next.get();
        left->next = std::move(current->next);
        size--;
    }
    else throw Large_index(size);
}

template<class type_data>
void LinkedList<type_data>::clear() {
    first = nullptr;
    size = 0;
}

template<class type_data>
void LinkedList<type_data>::show() {
    auto current = first.get();
    while(current){
        std::cout << current->data << std::endl;
        current = current->next.get();
    }
}
#endif //LINKEDLIST_LINKEDLIST_H
