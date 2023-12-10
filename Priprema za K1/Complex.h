#pragma once
#include <iostream>
class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double real=0, double imag=0) : real(real), imag(imag){}

        Complex operator+(const Complex& other) const{
            Complex returnValue;
            returnValue.real = real + other.real;
            returnValue.imag = imag + other.imag;

            return returnValue;
        }

        double getReal() const{
            return this->real;
        }

        double getImag() const{
            return this->imag;
        }

        void print() const{
            std::cout<<"("<<getReal()<<","<<getImag()<<")"<<std::endl;
        }
};