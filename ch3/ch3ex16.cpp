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

    vector<int> vec;
    int x;

    while(cin >> x)
    {
        vec.push_back(x); //add elements from the stream to vec
    }

    for(auto i : vec)
        cout << i << " "; //print the elements of the vector
    cout << endl;

    cout<<"The size of the vector is: " << vec.size() << endl;

return 0;
}