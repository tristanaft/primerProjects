#include<algorithm>
#include<iostream>
#include<vector>
#include<numeric>


int main(){

    std::vector<int> vec;

    std::cout << "Enter some ints: ";
    int i;
    while(std::cin >> i){
        vec.push_back(i);
    }
    std::cout << std::endl;

    int sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
    
    std::cout << "The sum of the inputs is: " << sum << std::endl;



    return 0;
}