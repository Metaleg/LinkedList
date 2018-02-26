//main.cpp

#include "LinkedList.h"



int main() {
    LinkedList l;

    l.push_front(11);
    l.push_front(21);
    l.push_front(31);
    l.push_front(41);
    l.push_front(51);
    l.push_front(0);


    if (l.is_empty())
        std::cout<<"List is empty\n";
    else
        std::cout<<"List is not empty\n";
    std::cout<<"List size: "<<l.get_size()<<std::endl;
    l.show();
    //std::cout<<"First element: "<<l.get_front()<<std::endl;

    std::cout<<std::endl;


    return 0;
}