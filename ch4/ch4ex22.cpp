#include <iostream>
//#include <vector>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    
    
    cout << "Enter grade: ";
    int grade;
    cin >> grade;
    cout << endl;

    cout << ((grade>90) ? "A+" :
                (grade > 80) ? "A" :
                    (grade > 70) ? "B" :
                        (grade > 60) ? "C" :
                            (grade > 50) ? "D" : "Fail");
    
    cout << endl;





    
    
    
    




    
    
    return 1;
}