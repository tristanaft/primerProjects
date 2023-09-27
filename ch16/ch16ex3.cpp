#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

//At this point, I have replaced most of the functions with operators.
//from ch 14

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


template<typename T> 
int compare(T& l, T& r){
    if(l < r) return 1;
    else if(r < l) return -1;
    else return 0; //if equal.
}


int main(){
    Sales_data sd1("bookNo1", 10, 25.0), sd2("bookNo2", 7, 15.0);
    std::cout << "compare(sd1, sd2) = "<< compare(sd1,sd2) << std::endl;
    //get the error: error: invalid operands to binary expression ('Sales_data' and 'Sales_data')
    //note: in instantiation of function template specialization 'compare<Sales_data>' requested here



    return 0;
}