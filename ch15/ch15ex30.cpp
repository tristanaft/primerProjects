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
    //reference qualifiers see p 546
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() const && {return new Quote(std::move(*this));}
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
    Bulk_quote* clone() const & override {return new Bulk_quote(*this);}
    Bulk_quote* clone() const && override {return new Bulk_quote(std::move(*this));}
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
    Limited_quote* clone() const & override {return new Limited_quote(*this);}
    Limited_quote* clone() const && override {return new Limited_quote(std::move(*this));}
};

double print_total(std::ostream& os, const Quote& item, size_t n){
    //depending on type of obj bound to item param,
    //calls either Quote::net_price() or Bulk_quote::net_price()
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() //calls Quote::isbn()
        <<" # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

class Basket{
public:
    void add_item(const std::shared_ptr<Quote>& sale){items.insert(sale);}
    void add_item(const Quote& sale){items.insert(std::shared_ptr<Quote>(sale.clone()));}
    void add_item(const Quote&& sale)
        {items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}
    double total_receipt(std::ostream&);
private:
    static bool compare(const std::shared_ptr<Quote>& lhs,
                        const std::shared_ptr<Quote>& rhs)
        {return lhs->isbn() < rhs->isbn();}
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
    //vscode is saying theres an error with initializer_list again... not sure why?
};

double Basket::total_receipt(std::ostream& os){
    double sum = 0.0;
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}


int main() {
    Basket bsk;
    bsk.add_item(std::make_shared<Quote>("123", 50));
    bsk.add_item(Quote("123", 50));
    bsk.add_item(std::make_shared<Quote>("123", 50));
    bsk.add_item(Bulk_quote("234", 50, 5, 0.25));
    bsk.add_item(std::make_shared<Bulk_quote>("234", 50, 5, 0.25));
    bsk.add_item(std::make_shared<Bulk_quote>("234", 50, 5, 0.25));
    bsk.add_item(std::make_shared<Bulk_quote>("234", 50, 5, 0.25));
    bsk.add_item(std::make_shared<Bulk_quote>("234", 50, 5, 0.25));
    bsk.add_item(std::make_shared<Bulk_quote>("234", 50, 5, 0.25));
    
    bsk.total_receipt(std::cout);

  return 0;
}