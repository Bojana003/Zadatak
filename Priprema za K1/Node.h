#pragma once
#include "Complex.h"

class Node{
    private:
        Complex value;
        Node* next;
    public:
        Node(Complex value) : value(value), next(nullptr){}

        Node(Complex value, Node* next) : value(value), next(next){}

        Complex getValue() const{
            return value;
        } 

        Node* getNext(){
            return this->next;
        }

        void setValue(const Complex& value){
            this->value = value;
        }

        void setNext(Node* next){
            this->next = next;
        }

        void print() const{
            value.print();
        }
};