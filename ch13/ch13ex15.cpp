#include<iostream>

class numbered{
public:
    numbered(): mysn(++sn) {}
    numbered(const numbered&): mysn(++sn) {}
    int mysn;
private:
    static int sn;
};

int numbered::sn = 0;

void f(numbered s){
    //s is copy initialized in the function, which throws off mysn
    //from the value you give to it initially...
    std::cout << s.mysn << std::endl;
}


int main(){

    numbered a, b=a, c=b; //a.msyn = 1, b.msyn = 2, c.msyn = 3
    f(a);
    f(b);
    f(c);




    return 0;
}