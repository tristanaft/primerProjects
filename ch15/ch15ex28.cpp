#include<string>
#include<iostream>
#include<vector>


//original class: Quote
class Quote{
public:
    //constructors, explicitly written instead of default.
    Quote(): bookNo(std::string()), price(0.0) {
    }
    Quote(const Quote& rhs): bookNo(rhs.bookNo), price(rhs.price) {
    }
    Quote(Quote&& rhs): bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
    }
    Quote& operator=(const Quote& rhs) { //copy assign
        price = rhs.price;
        bookNo = rhs.bookNo;
        return *this;
    }   
    Quote& operator=(Quote&& rhs){ //move assign
        price = std::move(rhs.price);
        bookNo = std::move(rhs.bookNo);
        return *this;
    }        
    virtual ~Quote() = default; //default destructor

    Quote(const std::string& book, double sales_price):
        bookNo(book), price(sales_price) {
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
    };
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { };
    Disc_quote(const Disc_quote& rhs): Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {
    }
    Disc_quote(Disc_quote&& rhs): Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), 
        discount(std::move(rhs.discount)) {
        }
    Disc_quote& operator=(Disc_quote& rhs){
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        return *this;
    }
    Disc_quote& operator=(Disc_quote&& rhs){
        Quote::operator=(std::move(rhs));
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);
        return *this;
    }

    double net_price(std::size_t) const = 0; //PURE VIRTUAL FUNCTION
private:
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
        Quote::debug(os) << " Bulk_quote::min_qty " << min_qty << " Bulk_quote::price " << discount;
        return os;
    }
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t cnt) const {
    if(cnt >= min_qty){
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
        Quote::debug(os) << " Limited_quote::max_qty " << max_qty << " Limited_quote::price " << discount;
        return os;
    }
private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

double Limited_quote::net_price(std::size_t cnt) const {
    if(cnt < max_qty){
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



int main() {

    std::vector<Quote> basket;
    basket.push_back(Quote("0-201-82470-1", 50.0));
    basket.push_back(Bulk_quote("0-201-82470-1", 50.0, 10, 0.25));
    basket.push_back(Limited_quote("0-201-82470-1", 50.0, 10, 0.25));

    double total = 0;
    for(auto q: basket){
        std::cout  << q.net_price(20) << std::endl;
        total += q.net_price(20);
    }
    std::cout << "Total: " << total << std::endl;
    std::cout << "Note: this total is incorrect, it does not factor in the discounts." << std::endl;
    








  return 0;
}