#include<iostream>
#include<vector>
#include<algorithm>

class isEqual{
public:
    isEqual() = default;
    isEqual(int i): chk(i) {}
    bool operator()(int i){
        return i==chk;
    }
private:
    int chk;
};

int main(){
    std::cout << "Here is a sequence of INTs: \n";
    std::vector<int> vi { 1,1,2,3,4,1,1,2,3,4,5,6,7,8 };
    //vscode is complaining about this definition of vi even though it is perfectly valid...
    //it seems to just hate vectors of ints, I have tried rewriting it...
    
    for(int x : vi){
        std::cout << x << " ";
    }
    std::cout << std::endl;


    std::cout << "Enter a value you want to replace, and the value to replace it with: \n";
    int ov, nv;
    std::cin >> ov >> nv;
    isEqual ie(ov);

    std::replace_if(vi.begin(), vi.end(), ie, nv);
    for(int x : vi){
        std::cout << x << " ";
    }
    std::cout << std::endl;



    return 0;
}