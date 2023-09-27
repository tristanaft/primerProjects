#include "TextQuery.h"
#include "QueryResult.h"

int main(){
    std::ifstream in("inputfile.in");
    std::cout << "Getting Text" << std::endl;
    TextQuery tq(in);

    tq.printText();
    std::cout << std::endl;

    std::cout << "Attempting to query..." << std::endl;
    QueryResult qr = tq.query("to");
    qr.print();

    return 0;
}