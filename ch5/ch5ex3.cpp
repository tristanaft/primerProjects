#include <iostream>

int main() {
  int sum = 0, val = 1;

  /*while (val <= 10){
    sum += val;
    ++val;
    }*/
  while (val <= 10) 
    sum += val, ++val;

  std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

  // It isn't that big of a difference, but I think it makes it less clear

  return 0;
}