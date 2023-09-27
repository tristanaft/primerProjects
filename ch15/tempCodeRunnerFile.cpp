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

//derived class: Bulk_quote
class Bulk_quote : public Quote{ // bulk inherits from quote
public:
    double net_price(std::size_t n) const override;
    //this overrides the base function in Quote
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const {
    if(n>=min_qty)
        return n*price*(1-discount);
    else
        return n*price;
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

    Quote basic("isbn", 10.0);
    Bulk_quote bulk;
    print_total(std::cout, basic, 20);

    return 0;
}

