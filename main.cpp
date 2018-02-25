//main.cpp

#include "LinkedList.h"



int main() {
    LinkedList l;

    l.add(11);
    l.add(21);
    l.add(31);
    l.add(41);
    l.add(51);
    l.add(0);

    l.show();
    std::cout<<"List size: "<<l.getSize()<<std::endl;
    if (l.isEmpty())
        std::cout<<"List is empty\n";
    else
        std::cout<<"List is not empty\n";

    std::cout<<"l[1] = "<<l[1]<<std::endl;

    std::cout<<std::endl;

    return 0;
}