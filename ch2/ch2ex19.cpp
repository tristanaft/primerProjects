#include <iostream>

int main()
{

    int i=0;
    
    //double* dp = &i;  type mismatch btw double and int
    //int *ip = i;      pointer ip must point to the address of i
    int *p = &i;        //pointer p points to i



    return 0;
}