#include <iostream>

int main()
{

    int a, b, c, d;
    std::cin >> a, b, c, d;
    //std::cout << std::endl;
    if(a>b && b>c && c>d)
        return 1;
    else
        return 0;
}