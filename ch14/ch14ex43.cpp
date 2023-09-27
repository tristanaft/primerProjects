#include<functional>
#include<vector>
#include<iostream>



int main(){
    using namespace std::placeholders;

    std::vector<int> vi = {2, 3, 5, 7};
    int i;
    std::cin >> i;
    auto iter = std::find_if_not(vi.begin(), vi.end(),
      std::bind(std::modulus<int>(), i, _1));
    if(iter != vi.end()){
        std::cout << *iter <<" divides " << i <<std::endl;
    } else{
        std::cout << "No divisor of " <<  i << " in vector." << std::endl;
    }






    return 0;
}