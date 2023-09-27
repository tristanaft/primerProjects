#include<string>
#include<iostream>


//original class: Quote
class Quote{
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const {return bookNo;};
    virtual double net_price(std::size_t n) const {return n * price;};
    //virtual means that this class expects derived classes to define for themselves
    virtual ~Quote() = default; //default destructor
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
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { };
    double net_price(std::size_t) const = 0; //PURE VIRTUAL FUNCTION
private:
    std::size_t quantity;
    double discount;
};


//derived class: Bulk_quote
class Bulk_quote : public Disc_quote{ // bulk inherits from Disc_quote
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
    Disc_quote(book, p, qty, disc) {}
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
 Limited_quote() = default;
 Limited_quote(const std::string& book, double p, std::size_t qty, double disc):
    Disc_quote(book, p, qty, disc) {}
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



int main(){

   //Disc_quote dq;
   //get errors:
   //error: variable type 'Disc_quote' is an abstract class 
   //Disc_quote dq;
   //note: unimplemented pure virtual method 'net_price' in 'Disc_quote'
   //double net_price(std::size_t) const = 0; //PURE VIRTUAL FUNCTION

    return 0;
}

