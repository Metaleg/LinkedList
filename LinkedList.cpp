//
// Created by metalleg on 25.02.18.
//

#include "LinkedList.h"


LinkedList::LinkedList(const LinkedList& list) {
    for (int i = 0; i < list.size; ++i)
        push_front(list[list.size - i - 1]);
}

LinkedList::LinkedList(LinkedList&& list) {
    first = std::move(list.first);
    size = list.size;

    list.first = nullptr;
}


LinkedList& LinkedList::operator=(const LinkedList& list) {
    for (int i = 0; i < list.size; ++i)
        push_front(list[list.size - i - 1]);
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList &&list) {
    first = std::move(list.first);
    size = list.size;

    list.first = nullptr;
    return *this;
}


int LinkedList::get_size() const {return size;}

bool LinkedList::is_empty() const {
    return first == nullptr;
}


void LinkedList::push_front(int val) {
    std::unique_ptr<Node> newnode(new Node);
    newnode->data = val;
    newnode->next = std::move(first);
    first = std::move(newnode);
    size++;
}


void LinkedList::pop_front() {
    if (!is_empty()){
        std::unique_ptr<Node> temp = std::move(first->next);
        first = std::move(temp);
        size--;
    }

}


int LinkedList::get_front() {
    if (!(is_empty()))
        return first->data;
}


const int LinkedList::get_front() const {
    if (!(is_empty()))
        return first->data;
}



int LinkedList::operator[](int pos){
    if (pos < size) {
        std::unique_ptr<Node> current = std::move(first);
        for (int i = 0; i < pos; ++i)
            current = std::move(current->next);
        return current->data;
    }
}


const int LinkedList::operator[](int pos) const {
    if (pos < size) {
        std::unique_ptr<Node> current;
        for (int i = 0; i < pos; ++i)
            current = std::move(current->next);
        return current->data;
    }
}


void LinkedList::insert(int pos, int val) {
    if (pos < size) {
        std::unique_ptr<Node> newnode(new Node);
        newnode->data = val;
        std::unique_ptr<Node> current = std::move(first);
        for (int i = 0; i < (pos - 1); ++i)
            current = std::move(current->next);
        newnode->next = std::move(current->next);
        current->next = std::move(newnode);
        size++;
    }
}


void LinkedList::erase(int pos) {
    if (pos < size) {
        std::unique_ptr<Node> current = std::move(first);
        for (int i = 0; i < (pos - 1); ++i)
            current = std::move(current->next);
        std::unique_ptr<Node> left;
        left = std::move(current);
        current = std::move(current->next);
        left->next = std::move(current->next);
        size--;
    }
}


void LinkedList::clear() {
    while (first != nullptr) {
        std::unique_ptr<Node> temp = std::move(first->next);
        first = std::move(temp);
    }
}

void LinkedList::show() {
    std::unique_ptr<Node> current = std::move(first);
    while(current){
        std::cout << current->data << std::endl;
        current = std::move(current->next);
    }
}