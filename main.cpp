//main.cpp

#include "LinkedList.h"



int main() {

    try{

        LinkedList<int> l;

        l.push_front(11);
        l.push_front(21);
        l.push_front(31);
        l.push_front(41);
        l.push_front(51);
        l.push_front(3);

        if (!l.is_empty())
            std::cout << "List is not empty" << std::endl;
        std::cout<<"List size: "<<l.get_size()<<std::endl;
        std::cout<<"First element: "<<l.get_front()<<std::endl;
        l.show();
        std::cout << std::endl;

        std::cout << "l[3] = " << l[3] << std::endl;
        //std::cout << "l[10] = " << l[10] << std::endl;

        l.insert(4, 98);
        l.show();
        std::cout << std::endl;

        //l.insert(9, 555);


        l.pop_front();
        l.show();
        std::cout << std::endl;

        l.erase(2);
        l.show();
        std::cout << std::endl;


        l.clear();
        std::cout << std::endl;
        l.show();
        std::cout << std::endl;


        ///////////////////////////////////////////////////

        LinkedList<char> ch;

        ch.push_front('t');
        ch.push_front('s');
        ch.push_front('i');
        ch.push_front('L');


        if (!ch.is_empty())
            std::cout << "List is not empty" << std::endl;
        std::cout<<"List size: "<<ch.get_size()<<std::endl;
        std::cout<<"First element: "<<ch.get_front()<<std::endl;
        ch.show();
        std::cout << std::endl;

        std::cout << "l[2] = " << ch[2] << std::endl;
        //std::cout << "ch[10] = " << ch[10] << std::endl;

        ch.insert(0, 'L');
        ch.show();
        std::cout << std::endl;

        //ch.insert(9, 'I');


        ch.pop_front();
        ch.show();
        std::cout << std::endl;

        ch.erase(2);
        ch.show();
        std::cout << std::endl;


        ch.clear();
        std::cout << std::endl;
        ch.show();
        std::cout << std::endl;

    }
    catch (Large_index index){
        std::cout << "Incorrect index! Index must have a lower value then " << index.index << std::endl;
    }
    catch (Empty){
        std::cout << "List is empty!" << std::endl;
    }


    std::cout<<std::endl;
    return 0;
}