//main.cpp

#include "LinkedList.h"



int main() {
    LinkedList<int> l;

    l.push_front(11);
    l.push_front(21);
    l.push_front(31);
    l.push_front(41);
    l.push_front(51);
    l.push_front(3);


    if (l.is_empty())
        std::cout<<"List is empty\n";
    else
        std::cout<<"List is not empty\n";
    std::cout<<"List size: "<<l.get_size()<<std::endl;
    std::cout<<"First element: "<<l.get_front()<<std::endl;
    l.show();

    std::cout << "l[3] = " << l[3] << std::endl;
    l.show();
    l.pop_front();
    l.pop_front();
    std::cout << std::endl;
    l.show();




 /*   LinkedList l2;

    //l2.show();

    if (l2.is_empty())
        std::cout<<"List is empty\n";
    else
        std::cout<<"List is not empty\n";

    std::cout<<"First element: "<<l2.get_front()<<std::endl;
    std::cout << l2[2] << std::endl;
    l2.pop_front();
    l2.insert(5, 25);
    l2.push_front(5);
    l2.show();
    l2.clear();
    l2.show();*/


    std::cout<<std::endl;


    return 0;
}