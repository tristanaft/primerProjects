#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iostream>
#include <fstream>

int main(){
    //I could do this with command line input, but it a pain so i wont
    //I could also do this with std::cin, but that is also a pain
    std::ifstream in("ch10ex33input.in");
    std::ofstream osEven("ch10ex33outputEven.in"), osOdd("ch10ex33outputOdd.in");

    std::istream_iterator<int> i_iter(in), eof;
    std::ostream_iterator<int> even_iter(osEven, " "), odd_iter(osOdd, " ");

    std::for_each(i_iter,eof,
    [&](int i) { i % 2 ? odd_iter = i : even_iter = i; });





    return 0;
}