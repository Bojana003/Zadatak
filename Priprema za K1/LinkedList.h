#pragma once
#include "Node.h"
#include <iostream>
class LinkedList{
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr){}

        ~LinkedList(){
            _delete();
        }

        LinkedList(const LinkedList& other){
            copy(other);
        }

        LinkedList(LinkedList&& other){
            move(other);
        }

        LinkedList& operator=(const LinkedList& other){
            if(this != &other){
                _delete();
                copy(other);
            }
            return *this;
        }

        LinkedList& operator=(LinkedList&& other){
            if(this != &other){
                _delete();
                move(other);
            }
            return *this;
        }

        void copy(const LinkedList& other){
            if(other.head != nullptr){
                this->head = nullptr;
            }
            this->head = new Node(other.head->getValue());
            Node *temp = other.head->getNext();

            while(temp){
                this->addNode(other.head->getValue());
                temp = temp->getNext();
            }
        }

        void move(LinkedList& other){
            this->head = other.head;
            other.head = nullptr;
        }

        void _delete(){
            Node* current = this->head;
            Node* previous = nullptr;

            while(current){
                previous = current;
                current = current->getNext();
                delete previous;
            }
        }

        void addNode(const Complex& value){
            if(this->head == nullptr){
                this->head = new Node(value);
            }
            else{
                Node* temp = this->head;

                while(temp->getNext()){
                    temp = temp->getNext();
                }
                temp->setNext(new Node(value));
            }
        }

        const Complex at() const{
            return this->head->getValue();
        }

        void print() const{
            Node* temp = head;

            while(temp){
                temp->print();
                temp = temp->getNext();
            }
        }

        Complex aggregate(Complex (*f)(const Complex& x1, const Complex& x2)){
            Complex result = head->getValue();
            Node *temp = head->getNext();
            while(temp){
                result = f(result, temp->getValue());
                temp = temp->getNext();
            }
            return result;
        }
};