#include <iostream>
using namespace std;

class A
{
	int x;
public:
	A() { cout << "A's constructor called " << endl; }
    int getX() {return this->x;}
};

class B
{
	static A a;
public:
	B() { cout << "B's constructor called " << endl; }
	static A getA() { return a; }
};

A B::a; // definition of a

int main()
{
	B b1, b2, b3;
	A a = b1.getA();
    cout << endl;
    int t = a.getX();
    cout << t << endl;


	return 0;
}
