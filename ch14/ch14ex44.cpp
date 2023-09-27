#include<iostream>
#include<functional>
#include<map>

int divide(int i1, int i2){
    if(i2 != 0){
        return i1/i2;}
    else{
        std::cerr << "Error, divide by zero";
        return 0;}
};

std::map<std::string, std::function<int(int,int)>> binops = {
    {"+", std::plus<int>()},
    {"-", std::minus<int>()},
    {"/", divide},
    {"*", std::multiplies<int>()},
    {"%", std::modulus<int>()},
};

void displayBinOps(std::map<std::string, std::function<int(int,int)>> bo){
    std::cout << "Supported operations are: ";
    for(auto p : bo){
        std::cout << p.first << " ";
    }
    std::cout << std::endl;
}

void startMessage(){
    std::cout << "-----Welcome to CALCUTRON-----\n";
    std::cout << "Enter two INTs and a binary operation\n"<<
        "(separated by spaces, ex: 1 + 2)\n" <<
        "and this program will perform the calculation." << std::endl;
}

void calculatorProcess(){
    int i1, i2;
    std::string b;
    std::cin >> i1 >> b >> i2;
    if(binops.count(b)){ //the operator is defined.
        std::function<int(int,int)> op = binops[b];
        std::cout << "Result: " << op(i1,i2) << std::endl;
    }else{
        std::cout << "Operator not recognized." << std::endl;
    }
}

int main(){
    startMessage();
    displayBinOps(binops);

    bool done = false;
    while(!done){
        calculatorProcess();
        std::string chk;
        std::cout << "Perform another calculation?\n" 
            << "If yes enter y, otherwise enter anything else: ";
        std::cin >> chk;
        if(chk == "y"){
            done = false;
        }else{
            done = true;
        }
    }

    
    
   



    return 0;
}