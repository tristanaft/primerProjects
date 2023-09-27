#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

//This is from ch 10

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);


public:
    Sales_data& operator+=(const Sales_data&);
    Sales_data() : Sales_data("", 0, 0.0) {}
    explicit Sales_data(const std::string &no) : Sales_data(no, 0, 0.0) {}
    Sales_data(const std::string &no, unsigned us, double price)
        : bookNo(no), units_sold(us), revenue(price * us) {}
    explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

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




Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;  // Use default copy constructor
  sum.combine(rhs);
  return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}

inline
double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}



int main() {
  Sales_data currItem;
  std::vector<Sales_data> sdVec;
  double price;
  std::string fileName = "sdinput.in";
  std::ifstream in(fileName);

  if (read(in,currItem)) {
    sdVec.push_back(currItem);
    while (read(in,currItem)) {
        sdVec.push_back(currItem);
        }
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }
  //lets print the elements in sdVec:
  for(auto sd: sdVec){
    //print(std::cout,sd);
    std::cout << sd << std::endl;
    }
  //ok now we have the vector, lets sort it now.
  std::cout << std::endl; //give extra space

  std::stable_sort(sdVec.begin(),sdVec.end(),compareIsbn);

  for(auto sd: sdVec){
    print(std::cout,sd);
    std::cout << std::endl;
    }


  return 0;
}