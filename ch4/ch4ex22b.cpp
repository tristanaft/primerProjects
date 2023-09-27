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

    /* 
    cout << ((grade>90) ? "A+" :
                (grade > 80) ? "A" :
                    (grade > 70) ? "B" :
                        (grade > 60) ? "C" :
                            (grade > 50) ? "D" : "Fail");
    */

    if(grade>90)
        cout <<"A" << endl;
    else if (grade > 80)
        cout << "B" <<endl;
    else if (grade > 70)
        cout << "C" <<endl;
    else if (grade > 60)
        cout << "D" <<endl;
    else
        cout << "Fail" <<endl;
    
    cout << endl;





    
    
    
    




    
    
    return 1;
}