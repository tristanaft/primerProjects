#include<string>
#include<iostream>


//original class: Quote
class Quote{
public:
    //constructors, explicitly written instead of default.
    Quote(): bookNo(std::string()), price(0.0) {
        std::cout << "Quote()" << std::endl;
    }
    Quote(const Quote& rhs): bookNo(rhs.bookNo), price(rhs.price) {
        std::cout << "Quote(const Quote&)" << std::endl;
    }
    Quote(Quote&& rhs): bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
        std::cout << "Quote(Quote&&)" << std::endl;
    }
    Quote& operator=(const Quote& rhs) { //copy assign
        price = rhs.price;
        bookNo = rhs.bookNo;
        std::cout << "operator=(const Quote&)" << std::endl;
        return *this;
    }   
    Quote& operator=(Quote&& rhs){ //move assign
        price = std::move(rhs.price);
        bookNo = std::move(rhs.bookNo);
        std::cout << "operator=(const Quote&&)" << std::endl;
        return *this;
    }        
    virtual ~Quote() = default; //default destructor

    Quote(const std::string& book, double sales_price):
        bookNo(book), price(sales_price) {
        std::cout << "Quote(const std::string&, double)" << std::endl;
        }
    std::string isbn() const {return bookNo;};
    virtual double net_price(std::size_t n) const {return n * price;};
    //virtual means that this class expects derived classes to define for themselves
    //classes used as the root of an inheritance hierarchy almost always define a virtual destructor
    virtual std::ostream& debug(std::ostream& os) const {
        os << "Quote::bookNo " << bookNo << " Quote::price " << price;
        return os;
    }
private:
    //private members CANNOT be accessed by derived classes
    std::string bookNo;
protected:
    //protected members can be accessed by derived classes
    double price = 0.0;
};

//class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote: public Quote {
public:
    Disc_quote() {
        std::cout << "Disc_quote()" << std::endl;
    };
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { 
            std::cout << "Disc_quote(const std::string&, double, std::size_t, double)" << std::endl;
        };
    Disc_quote(const Disc_quote& rhs): Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {
        std::cout << "Disc_quote(Disc_quote&)" << std::endl;
    }
    Disc_quote(Disc_quote&& rhs): Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), 
        discount(std::move(rhs.discount)) {
            std::cout << "Disc_quote(Disc_quote&&)" << std::endl;
        }
    Disc_quote& operator=(Disc_quote& rhs){
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        std::cout << "operator=(Disc_quote&)" << std::endl;
        return *this;
    }
    Disc_quote& operator=(Disc_quote&& rhs){
        Quote::operator=(std::move(rhs));
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);
        std::cout << "operator=(Disc_quote&&)" << std::endl;
        return *this;
    }

    double net_price(std::size_t) const = 0; //PURE VIRTUAL FUNCTION
protected:
    std::size_t quantity;
    double discount;
};


//derived class: Bulk_quote
class Bulk_quote : public Disc_quote{ // bulk inherits from Disc_quote
public:
    using Disc_quote::Disc_quote;
    double net_price(std::size_t) const override;
    //this overrides the base function in Quote
    virtual std::ostream& debug(std::ostream& os) const override {
        Quote::debug(os) << " Bulk_quote::min_qty " << quantity << " Bulk_quote::price " << discount;
        return os;
    }
};

double Bulk_quote::net_price(std::size_t cnt) const {
    if(cnt >= quantity){
        return cnt * (1 - discount) * price;
    }else{
        return cnt * price;
    }
}

//derived class: Limited_quote
class Limited_quote : public Disc_quote{ // Limited inherits from quote
public:
    using Disc_quote::Disc_quote;
    double net_price(std::size_t) const override;
    //this overrides the base function in Quote
    virtual std::ostream& debug(std::ostream& os) const override {
        Quote::debug(os) << " Limited_quote::max_qty " << quantity << " Limited_quote::price " << discount;
        return os;
    }
};

double Limited_quote::net_price(std::size_t cnt) const {
    if(cnt < quantity){
        return cnt * (1 - discount) * price;
    }else{
        return cnt * price;
    }
}

double print_total(std::ostream& os, const Quote& item, size_t n){
    //depending on type of obj bound to item param,
    //calls either Quote::net_price() or Bulk_quote::net_price()
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() //calls Quote::isbn()
        <<" # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}


//I am copying the test code from github... im really tired right now...
int main() {
  Quote basic0;
  basic0.debug(std::cout) << '\n' << std::endl;

  Quote basic1("abc", 5.5);
  basic1.debug(std::cout) << '\n' << std::endl;

  Quote basic2(basic1);
  basic2.debug(std::cout) << '\n' << std::endl;

  Quote basic3(std::move(basic2));
  basic3.debug(std::cout) << std::endl;
  basic2.debug(std::cout) << '\n' << std::endl;

  basic2 = basic3;
  basic2.debug(std::cout) << '\n' << std::endl;

  basic3 = std::move(basic1);
  basic3.debug(std::cout) << std::endl;
  basic1.debug(std::cout) << '\n' << std::endl;

  std::cout << "============================" << std::endl; 

  Bulk_quote bulk0;
  bulk0.debug(std::cout) << '\n' << std::endl;

  Bulk_quote bulk1("abc", 5.5, 10, 0.2);
  bulk1.debug(std::cout) << '\n' << std::endl;

  Bulk_quote bulk2(bulk1);
  bulk2.debug(std::cout) << '\n' << std::endl;

  Bulk_quote bulk3(std::move(bulk2));
  bulk3.debug(std::cout) << std::endl;
  bulk2.debug(std::cout) << '\n' << std::endl;

  bulk2 = bulk3;
  bulk2.debug(std::cout) << '\n' << std::endl;

  bulk3 = std::move(bulk1);
  bulk3.debug(std::cout) << std::endl;
  bulk1.debug(std::cout) << '\n' << std::endl;

  std::cout << "============================" << std::endl; 

  Limited_quote limit0;
  limit0.debug(std::cout) << '\n' << std::endl;

  Limited_quote limit1("abc", 5.5, 5, 0.1);
  limit1.debug(std::cout) << '\n' << std::endl;

  Limited_quote limit2(limit1);
  limit2.debug(std::cout) << '\n' << std::endl;

  Limited_quote limit3(std::move(limit2));
  limit3.debug(std::cout) << std::endl;
  limit2.debug(std::cout) << '\n' << std::endl;

  limit2 = limit3;
  limit2.debug(std::cout) << '\n' << std::endl;

  limit3 = std::move(limit1);
  limit3.debug(std::cout) << std::endl;
  limit1.debug(std::cout) << '\n' << std::endl;

  return 0;
}