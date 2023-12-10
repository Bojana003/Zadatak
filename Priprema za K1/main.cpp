#include <iostream>
#include "LinkedList.h"
int main(){
    LinkedList list;
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(5, 6);
    list.addNode(c1);
    list.addNode(c2);
    list.addNode(c3);

    list.print();

    std::cout<<std::endl;

    Complex result = list.aggregate([](const Complex&x1, const Complex& x2){
        return x1+x2;
    });

    result.print();
    return 0;
}