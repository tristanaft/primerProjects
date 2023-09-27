#include <string>
#include <iostream>

struct Sales_data {
    //constructors added
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p): 
               bookNo(s), units_sold(n), revenue(p*n) { }

    //Sales_data(std::istream& is): Sales_data::read(is,*this) {}
    //Sales_data(std::istream& is) {Sales_data::read(is,*this);}
    Sales_data(std::istream &is) {read(is);}

    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data&);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::istream& read(std::istream& is){
        double price = 0;
        is >> (this->bookNo) >> (this->units_sold) >> price;
        (this->revenue) = (this->units_sold) * price;
        return is;
    }

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

using std::cin;
using std::cout;
using std::endl;


int main() {

    Sales_data total(cin);
    if(cin) {
        Sales_data trans(cin);
        while(cin){
            if(total.isbn() == trans.isbn()){
                total.combine(trans); //update the running total
            }
            else{
                print(cout,total) << endl;
                total = trans;
            }
            trans.read(cin); // read new input
            //this line looks really weird to me...
            //is it just coded in a strange way?
            //should it be coded like, trans.read(cin) reads to trans?
        }
        print(cout,total) << endl;
    } else {
        std::cout << "No data!" << endl;
    }

  return 0;
}