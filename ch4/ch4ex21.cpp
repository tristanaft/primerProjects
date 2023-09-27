#include <iostream>
#include<vector>

int main()
{
    
    
    std::vector<int> iv;
    int i;

    while(std::cin >> i)
        iv.push_back(i);
    
    for(auto &val : iv)
        val = (val%2 ? 2*val : val); 
        //if even, val%2=0 false return val
        //if odd, val%2 nonzero ->true return 2*val
    for(auto &x : iv)
        std::cout << x << " ";
    std::cout << std::endl;
    

    
    
    
    
    
    
    
    
    
    
    
    return 1;
    }