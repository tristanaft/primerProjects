#include<iostream>
#include<vector>
#include<list>

int main(){

    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    std::vector<int> vi(std::begin(ia),std::end(ia));
    std::list<int> li(std::begin(ia),std::end(ia));

    auto vit = vi.begin();
    auto lit = li.begin();
    auto len = vi.size();

    for(auto i=0; i<len; i++){
        if(*vit%2 == 0){ //if vector element even erase
            vi.erase(vit);
        }
        if(*lit%2 == 1){ //if list element odd erase
            li.erase(lit);
        }
        vit++;
        lit++;
    }
    
    //print elements:
    for(auto z:ia)
        std::cout<< z << " ";
    std::cout << std::endl;

    for(auto x:vi)
        std::cout<< x << " ";
    std::cout << std::endl;

    for(auto y:li)
        std::cout<< y << " ";
    std::cout << std::endl;



    return 0;
}