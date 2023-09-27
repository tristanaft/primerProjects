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

void f(const numbered& s){
    //now the function no longer uses copy initialization,
    //so this works
    std::cout << s.mysn << std::endl;
}


int main(){

    numbered a, b=a, c=b; //a.msyn = 1, b.msyn = 2, c.msyn = 3
    f(a);
    f(b);
    f(c);




    return 0;
}