#include<iostream>


void intSwap(int *a, int *b){

    int temp = *b;
    *b=*a;
    *a=temp;
}

int main(){

    int a=1, b=2;
    int *pa = &a, *pb=&b;

    std::cout << "a= " << a << "\t" << "b= " << b <<std::endl;

    std::cout << "SWAP!" <<std::endl;
    intSwap(pa,pb);

    std::cout << "a= " << a << "\t" << "b= " << b <<std::endl;


    return 0;
}