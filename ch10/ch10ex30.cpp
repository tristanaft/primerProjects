#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main(){
    
    std::cout << "Enter some ints: ";

    std::istream_iterator<int> i_iter(std::cin), i_eof;

    std::vector<int> vec(i_iter,i_eof);

    std::sort(vec.begin(),vec.end());

    std::ostream_iterator<int> o_iter(std::cout," ");

    std::copy(vec.begin(),vec.end(),o_iter);

    std::cout << std::endl;






    return 0;
}