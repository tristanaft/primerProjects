#include <string>
#include <iostream>

struct Sales_data {
    //constructors added
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p): 
               bookNo(s), units_sold(n), revenue(p*n) { }

    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data&);

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
std::istream& read(std::istream& is, Sales_data& item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item)
{
    os  << item.isbn()  << " " << item.units_sold 
        << " " << item.revenue;
    return os;
}


int main() {

  //test first initialization:
  Sales_data d1("978-3-16-148410-0");
  Sales_data d2("978-3-16-148410-0", 10, 20.0);

  print(std::cout,d1) << std::endl;
  print(std::cout,d2) << std::endl;


  return 0;
}