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
private:
    //private members CANNOT be accessed by derived classes
    std::string bookNo;
protected:
    //protected members can be accessed by derived classes
    double price = 0.0;
};

//derived class: Limited_quote
class Limited_quote : public Quote{ // Limited inherits from quote
public:
 Limited_quote() = default;
 Limited_quote(const std::string& book, double p, std::size_t qty, double disc):
    Quote(book, p), max_qty(qty), discount(disc) {}
    double net_price(std::size_t) const override;
    //this overrides the base function in Quote
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
    //calls either Quote::net_price() or Limited_quote::net_price()
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() //calls Quote::isbn()
        <<" # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}



int main(){

    Quote basic("isbn", 10.0);
 Limited_quote small("isbn2", 10.0, 10, 0.1);
    print_total(std::cout, basic, 5);
    print_total(std::cout, small, 5);

    return 0;
}

