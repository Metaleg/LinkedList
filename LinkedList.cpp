//
// Created by metalleg on 25.02.18.
//

#include "LinkedList.h"

LinkedList::~LinkedList() {
    while (first != nullptr) {
        Node *temp = first->next;
        delete first;
        first = temp;
    }
}

void LinkedList::show() {
    Node* current = first;
    while(current){
        std::cout<<current->data<<std::endl;
        current = current->next;
    }
}

int LinkedList::get_size() const {return size;}

bool LinkedList::is_empty() const {
    return (first == nullptr) ? true : false;
}

void LinkedList::push_front(int val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next=first;
    first = newnode;
    size++;
}

void LinkedList::pop_front() {
    Node *temp = first->next;
    delete first;
    first = temp;
    size--;
}

int& LinkedList::get_front() {
    return first->data;
}

const int& LinkedList::get_front() const {
    return first->data;
}


int& LinkedList::operator[](int pos){
    Node* current = first;
    for (int i = 0; i < pos; ++i)
        current = current->next;
    return current->data;
}

const int& LinkedList::operator[](int pos) const {
    Node* current = first;
    for (int i = 0; i < pos; ++i)
        current = current->next;
    return current->data;
}

void LinkedList::insert(int pos, int val) {
    Node* newnode= new Node;
    newnode->data = val;
    Node* current = first;
    for (int i = 0; i < (pos - 1); ++i)
        current = current->next;
    newnode->next = current->next;
    current->next = newnode;
    size++;
}

void LinkedList::erase(int pos) {
    Node* current = first;
    for (int i = 0; i < (pos - 1); ++i)
        current = current->next;
    Node* left = current;
    current = current->next;
    left->next = current->next;
    delete current;
    size--;
}