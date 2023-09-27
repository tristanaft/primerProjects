//from http://stackoverflow.com/q/21598635/5340808

#include <iostream>
using namespace std;


template <typename T> class Stack {
  typedef typename T::ThisDoesntExist StaticAssert; // T::ThisDoesntExist doesn't exist at all!
};


void f1(Stack<char>); // No instantiation, compiles

class Exercise {
  Stack<double> &rsd; // No instantiation, compiles (references don't need instantiation, are similar to pointers in this)
  
  //Stack<int>    si; // Instantiation! Doesn't compile!!
  //defining a variable requires instantiation?
};


int main(){
  
  Stack<char> *sc; // No Instantiation, this compiles successfully since a pointer doesn't need instantiation
  
  //f1(*sc); // Instantiation of Stack<char>! Doesn't compile!!
  //so, it has to be instantiated because we are DEREFERENCING sc

  //int iObj = sizeof(Stack< std::string >); // Instantiation of Stack<std::string>, doesn't compile!!
    //this has to be instantiated because we are checking the size of the stack.
}

//the compiler does raise some warnings, which is cool:
//warning: class 'Exercise' does not declare any constructor to initialize its non-modifiable members
//note: reference member 'rsd' will never be initialized

//Instantiation occurs when data has to be ALLOCATED, which is not the case
//when defining pointers or references or defining functions.