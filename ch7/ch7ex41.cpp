#include <string>
#include <iostream>

struct Sales_data {
    //non-delegating constructor
    Sales_data(const std::string &s, unsigned n, double p): 
               bookNo(s), units_sold(n), revenue(p*n) 
        {callCheck("Sales_data(const std::string &s, unsigned n, double p)");}
        
    //other constructors as delegating constructors
    Sales_data() : Sales_data("",0,0) 
        {callCheck("Sales_data()");}
    Sales_data(const std::string &s): Sales_data(s,0,0)
        {callCheck("Sales_data(const std::string &s)");}
    Sales_data(std::istream &is): Sales_data() 
    {   callCheck("Sales_data(std::istream &is)");
        read(is,*this);}

    //Sales_data(std::istream& is): Sales_data::read(is,*this) {}
    //Sales_data(std::istream& is) {Sales_data::read(is,*this);}

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

    void callCheck(std::string s)
    {std::cout << s <<" is called." << std::endl;};

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
    Sales_data d1;
    Sales_data d2("0-201-78345-X");
    Sales_data d3("0-201-78345-X", 5, 2.5);
    Sales_data d4(std::cin);

    print(std::cout, d1) << std::endl;
    print(std::cout, d2) << std::endl;
    print(std::cout, d3) << std::endl;
    print(std::cout, d4) << std::endl;


    return 0;
}