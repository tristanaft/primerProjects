#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>


//original class: Quote
class Quote{
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price):
        bookNo(book), price(sales_price) {}


    virtual ~Quote() = default;
    Quote(const Quote &) = default;
    Quote(Quote &&) = default;
    Quote &operator=(const Quote &) = default;
    Quote &operator=(Quote &&) = default;

    
    std::string isbn() const {return bookNo;};
    virtual double net_price(std::size_t n) const {return n * price;};
    virtual std::ostream& debug(std::ostream& os) const {
        os << "Quote::bookNo " << bookNo << " Quote::price " << price;
        return os;
    }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote: public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double pri,
                std::size_t qty, double disc)
        : Quote(book, pri), quantity(qty), discount(disc) { }

    virtual ~Disc_quote() = default;
    Disc_quote(const Disc_quote &) = default;
    Disc_quote(Disc_quote &&) = default;
    Disc_quote &operator=(const Disc_quote &) = default;
    Disc_quote &operator=(Disc_quote &&) = default;

    double net_price(std::size_t n) const = 0; //PURE VIRTUAL FUNCTION
protected:
    std::size_t quantity;
    double discount;
};



class Bulk_quote : public Disc_quote{ // bulk inherits from Disc_quote
public:
    using Disc_quote::Disc_quote;
    double net_price(std::size_t cnt) const override{
        if(cnt >= quantity){
            return cnt * (1 - discount) * price;
        }else{
            return cnt * price;
        }
    }
    virtual std::ostream& debug(std::ostream& os) const override {
        Quote::debug(os) << " Bulk_quote::min_qty " << quantity << " Bulk_quote::price " << discount;
        return os;
    }
};



//derived class: Limited_quote
class Limited_quote : public Disc_quote{ // Limited inherits from quote
public:
    using Disc_quote::Disc_quote;
    double net_price(std::size_t cnt) const override{
    if(cnt < quantity){
        return cnt * (1 - discount) * price;
    }else{
        return cnt * price;
    }
}
    //this overrides the base function in Quote
    virtual std::ostream& debug(std::ostream& os) const override {
        Quote::debug(os) << " Limited_quote::max_qty " << quantity << " Limited_quote::price " << discount;
        return os;
    }
};



double print_total(std::ostream& os, const Quote& item, size_t n){
    //depending on type of obj bound to item param,
    //calls either Quote::net_price() or Bulk_quote::net_price()
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() //calls Quote::isbn()
        <<" # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}


int main() {

    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Quote>("blah", 50));
    basket.push_back(std::make_shared<Bulk_quote>("blah", 50, 10, 0.25));
    basket.push_back(std::make_shared<Limited_quote>("blah", 50, 20, 0.2));
    double total;
    for(auto q : basket){
        //q->debug(std::cout) << std::endl;
        std::cout << q->net_price(15) << std::endl;
        total += q->net_price(15);
    }
    std::cout << "Total: " << total <<std::endl;

  return 0;
}