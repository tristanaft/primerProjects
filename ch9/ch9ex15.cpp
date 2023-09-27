#include<vector>
#include<iostream>

void vecIntCompare( std::vector<int> v1,
                    std::vector<int> v2){
    if(v1==v2){
        std::cout<<"These vectors are the same."<<std::endl;
    }
    else{
        std::cout<<"These vectors are not the same."<<std::endl;
    }


}

int main(){




    return 0;
}