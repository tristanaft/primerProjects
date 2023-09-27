#include<algorithm>
#include<iostream>
#include<vector>


int main(){

    std::vector<int> vec;

    std::cout << "Enter some ints: ";
    int i;
    while(std::cin >> i){
        vec.push_back(i);
    }
    std::cout << std::endl;

    //to prompt user again, need to clear stream
    //and ignore empty space...
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int target;
    std::cout << "Now, enter a target int to count: ";
    std::cin >> target;

    auto bg = vec.begin();
    auto en = vec.end();
    int cn = std::count(vec.begin(),vec.end(),target);

    std::cout<< "The value: " << target << " appears " << cn <<
        " times." << std::endl;






    return 0;
}