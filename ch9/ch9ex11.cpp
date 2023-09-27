#include<vector>

using std::vector;

int main(){

    vector<int> v1(10,-1); //vector of 10 -1s
    vector<int> v2(v1); //v2 is a copy of v1
    vector<int> v3 = {1,2,3,4,5}; //v3 direct initialize?
    vector<int> v4; //
    vector<int> v5{1,2,3,4,5}; //direct initialize?
    vector<int> v6(v5.begin(), v5.end());

    return 0;
}