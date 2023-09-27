#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <cctype>

void adjAdd()
{
    vector<int> vec;
    int x;
    cout << "Input some integers, at least two" << endl;

    while(cin >> x)
    {
        vec.push_back(x); //add elements from the stream to vec
    }

    //for(decltype(vec.size()) i = 0; i!=vec.size()-1; i++)
    //{ 
    //    cout << vec[i] + vec[i+1] << " ";
    //}

    for(auto iter = vec.begin();
    iter !=vec.end()-1; iter++)
        cout << *iter + *(iter+1) << " ";

    cout << endl;

}

void oppAdd()
{
    vector<int> vec;
    int x;
    cout << "Input some integers, at least two" << endl;

    while(cin >> x)
    {
        vec.push_back(x); //add elements from the stream to vec
    }



    //for(decltype(vec.size()) i = 0; i!=(vec.size())/2; i++)
    //{ 
    //    cout << vec[i] + vec[vec.size() - i - 1] << " ";
    //}

    

    auto mid = vec.cbegin() + (vec.cend() - vec.cbegin() + 1) / 2; //midpoint of vector

    for(auto iter = vec.begin();
    iter !=mid; iter++)
    cout << *iter + *(vec.cend() - 1 - (iter - vec.cbegin())) << " ";

    cout << endl;

    cout << endl;

}


int main()
{

//adjAdd();
oppAdd();
    

return 0;
}