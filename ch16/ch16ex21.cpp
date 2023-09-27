#include<iostream>
#include<string>

class DebugDelete{
public:
    DebugDelete(std::ostream& out = std::cerr): os(out) {}
    template<typename T>
    void operator()(T* p) const {
        os << "Deleting unique_pointer" << std::endl;
        delete p;
    }
private:
    std::ostream& os;
};

int main(){
    double* p = new double;
    DebugDelete d;
    d(p);
    int* ip = new int;
    d(ip); //can delete int even though we deleted a double before.
    std::cout << "I called the deleter above, but below it is called\n"
        <<"because the pointers get automatically deleted once we finish the program." << std::endl;

    std::unique_ptr<int, DebugDelete> up(new int, DebugDelete());
    //vscode is giving me an error here  ^^^ it doesn't like this new here
    //but this is copied from the book and compiles + runs so...
    std::unique_ptr<std::string, DebugDelete> sp(new std::string, DebugDelete());
    




    return 0;
}