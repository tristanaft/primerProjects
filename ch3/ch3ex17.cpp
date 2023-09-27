#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <cctype>


int main()
{

    vector<string> vec;
    string str;
    cout << "Input some words, it will stop when it hits the word stop" << endl;

    while(cin >> str && str != "stop")
    {
        vec.push_back(str); //add elements from the stream to vec
    }

    

    //cout<<"The size of the vector is: " << vec.size() << endl;
    cout << "I will now change these words to uppercase." << endl;

    for(auto &i : vec)
    {
        i[0] = toupper(i[0]);
        cout << i << " "; //print the elements of the vector
    }
    cout << endl;

return 0;
}