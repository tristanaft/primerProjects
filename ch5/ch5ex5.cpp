#include <iostream>
#include <vector>
#include <string>


int main() {

    std::vector<std::string> letters = {"A", "B", "C", "D", "F"};

    std::cout << "Input Letter Grade: ";
    int grade;
    std::cin >> grade;

    std::string letterGrade;
    //Assign letter grade to int grade value
    if (grade > 60){
        letterGrade = letters[(100-grade-1)/10];
        //Now, add in +/-
        if(grade == 100 || grade%10 > 7){
            letterGrade += "+";
        }
        else if (grade%10 < 3){
            letterGrade += "-";
        }
        }
    else{
        letterGrade = letters[3];
        }
    

    std::cout << "Letter grade is: " << letterGrade << std::endl;







  return 1;
}