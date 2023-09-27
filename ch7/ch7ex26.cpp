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
    Sales_data(std::istream &is) {read(is,*this);}

    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data&);
    float avg_price();

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::istream& read(std::istream& is, Sales_data& item){
        double price = 0;
        is >> item.bookNo >> item.units_sold >> price;
        item.revenue = item.units_sold * price;
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

std::ostream& print(std::ostream& os, const Sales_data& item){
    os  << item.isbn()  << " " << item.units_sold 
        << " " << item.revenue;
    return os;
}

inline
float Sales_data::avg_price(){
    if(units_sold){
        return revenue/units_sold;
    }
    else
        return 0;
}


using std::cin;
using std::cout;
using std::endl;


int main() {
    Sales_data d1("number", 12, 6); // Sales data holds transactions,
    //Sales data is initialized by a single transaction,
    //so average price should be the only price which is 6
    float pr = d1.avg_price();
    std::cout << pr << std::endl;


    return 0;
}