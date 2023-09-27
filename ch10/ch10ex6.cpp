#include<iostream>
#include<algorithm>
#include<vector>


int main(){

    std::vector<int> vec = {1,2,3,4,5,6};
    for(int x:vec)
        std::cout << x << " ";
    
    std::cout << std::endl;
    std::fill_n(vec.begin(),3,0);

    for(int x:vec)
        std::cout << x << " ";
    std::cout << std::endl;



    return 0;
}