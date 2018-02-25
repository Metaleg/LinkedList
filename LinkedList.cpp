//
// Created by metalleg on 25.02.18.
//

#include "LinkedList.h"

LinkedList::~LinkedList() {
    while (first != NULL) {   //Пока по адресу не пусто
        Node *temp = first->next; //Временная переменная для хранения адреса следующего элемента
        std::cout<<"deleted "<<first->data<<std::endl;
        delete first; //Освобождаем адрес обозначающий начало
        first = temp; //Меняем адрес на следующий
    }
}


int LinkedList::getSize() const {return size;}

bool LinkedList::isEmpty() const {
    return (first == NULL) ? true : false;
}

void LinkedList::add(int d) {
    Node* newnode = new Node;
    newnode->data = d;
    newnode->next=first;
    first = newnode;
    size++;
}

void LinkedList::show() {
    Node* current = first;
    while(current){
        std::cout<<current->data<<std::endl;
        current = current->next;
    }
}

int& LinkedList::operator[](int ind){
    Node* current = first;
    for (int i = 0; i < (ind); ++i)
        current = current->next;
    return current->data;
}

const int& LinkedList::operator[](int ind) const {
    Node* current = first;
    for (int i = 0; i < (size - ind - 1); ++i)
        current = current->next;
    return current->data;
}