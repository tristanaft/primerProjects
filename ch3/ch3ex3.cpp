#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;


int main()
{

    cout << "Input two words separated by a space." << endl;
    string word1, word2;
    cin >> word1 >> word2;
    //cout << word1 << word2;
    if(word1 == word2)
    {
        cout << "These are the same word" << endl;
    }
    else if(word1>word2)
    {
        cout << "The first word is larger in dict order" << endl;
    }
    else
    {
        cout << "The second word is larger in dict order" << endl;
    }

    if(word1.size()==word2.size())
    {
        cout << "They are the same length" << endl;
    }
    else if(word1.size()>word2.size())
    {
        cout << "The first word is longer" << endl;
    }
    else
    {
        cout << "The second word is longer" << endl;
    }

}
