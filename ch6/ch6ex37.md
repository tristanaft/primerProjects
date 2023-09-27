Assuming that the function takes in a string...

std::string (*func(std::string s))[10]

auto func(std::string s) -> std::string(*)[10]

decltype(str) func(std::string s){} 
this assumes that somewhere in func() there is a string& called str that references something outside the function?

using arrStr = std::string[10]
arrStr* func(std::string s)