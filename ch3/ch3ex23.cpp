#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//#include <string>
//using std::string;
#include <vector>
using std::vector;


int main()
{

    vector<int> vec(10);

    cout << "enter 10 ints separated by spaces" << endl;

    for(int i=0; i!=10; i++)
        cin>>vec[i];

    for(auto it = vec.begin();
    it!=vec.end(); it++)
        *it *=2;

    for(auto it = vec.begin();
    it!=vec.end(); it++)
        cout<<*it << " ";

    cout << endl;

return 0;
}