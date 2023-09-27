#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

//At this point, I have replaced most of the functions with operators.


class Sales_data {
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
public:
    Sales_data& operator=(const std::string&);
    Sales_data& operator+=(const Sales_data&);
    Sales_data() : Sales_data("", 0, 0.0) {}
    explicit Sales_data(const std::string &no) : Sales_data(no, 0, 0.0) {}
    Sales_data(const std::string &no, unsigned us, double price)
        : bookNo(no), units_sold(us), revenue(price * us) {}
    explicit Sales_data(std::istream &is) : Sales_data() { is >> *this; }

    std::string isbn() const { return bookNo; }

private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

//new operator declarations
Sales_data operator+(const Sales_data&, const Sales_data&);
std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);

//new operator definitions;
std::ostream& operator<<(std::ostream& os, const Sales_data& sd){
    os  << sd.isbn()  << " " << sd.units_sold << " "
        << sd.revenue << " " << sd.avg_price();
    return os;
}

std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if(is){ //check that inputs succeeded
        item.revenue = item.units_sold * price;
    }
    else{
        item = Sales_data(); //input failed, give object default state.
    }
    return is;
}

Sales_data& Sales_data::operator=(const std::string& s){
    bookNo = s;
    return *this;
}

//by defining += this way, we avoid having to create a temporary object
//so theres a bit less work.
Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;  // Use default copy constructor
    sum += rhs;
  return sum;
}


inline
double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

//I could redefine this as operator<() but I think that could be ambiguous...
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}



int main() {

    Sales_data sd;
    std::cout << sd << std::endl;
    sd = "test bookno";
    std::cout << sd << std::endl;


  return 0;
}