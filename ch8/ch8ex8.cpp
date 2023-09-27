#include <string>
#include <iostream>
#include <fstream>


/*
Here is how you compile and run this:

cd /Users/tristanaft/Desktop/cppProjects/primerProjects/ch8/
This gets to the correct directory

ch8 % g++ -o ch8ex8exe ch8ex8.cpp
this tells g++ to create ch8ex7exe using the cpp file ch8ex7.cpp

./ch8ex8exe ch8ex8input.in ch8ex8output.in
This runs ch8ex7exe using the 2 command line arguments.

g++ -o -std=c++11 ch8ex8exe ch8ex8.cpp && ./ch8ex8exe ch8ex8input.in ch8ex8output.in
*/



class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
    //declare friends
    friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
    friend std::istream& read(std::istream& is, Sales_data& item);
    friend std::ostream& print(std::ostream& os, const Sales_data& item);

    public:
        //constructors must be public
        Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
        Sales_data(const std::string &s): bookNo(s) { }
        Sales_data(const std::string &s, unsigned n, double p): 
                bookNo(s), units_sold(n), revenue(p*n) { }
        Sales_data(std::istream &is) {read(is,*this);}
        //member functions?
        std::string isbn() const {return bookNo;}
        Sales_data &combine(const Sales_data&);
    private:
        //parameters of the class should be private?
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

};

Sales_data& Sales_data::combine(const Sales_data& rhs){   
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
    os  << item.isbn()  << " " << item.units_sold 
        << " " << item.revenue;
    return os;
}

std::istream& read(std::istream& is, Sales_data& item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: 8.8 <filename>" << std::endl;
    return -3;
  }
  std::ifstream in(argv[1]);
  if (!in) {
    std::cerr << "Fail to open input file: " << argv[1] << std::endl;
    return -2;
  }

  std::ofstream out(argv[2],std::ofstream::app);
  if (!out) {
    std::cerr << "Fail to open output file: " << argv[2] << std::endl;
    return -4;
  }



    Sales_data total(in);
    if(in) {
        Sales_data trans(in);
        while(in){
            if(total.isbn() == trans.isbn()){
                total.combine(trans); //update the running total
            }
            else{
                print(out,total) << endl;
                total = trans;
            }
            read(in,trans);
        }
        print(out,total) << endl;
    } else {
        std::cout << "No data!" << endl;
    }

  return 0;
}

