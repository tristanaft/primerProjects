// based on ex15.28
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>


class Quote {
public:

  Quote() = default;
  Quote(const std::string &book, double pri) : bookNo(book), price(pri) { }

  virtual ~Quote() = default;
  Quote(const Quote &) = default;
  Quote(Quote &&) = default;
  Quote &operator=(const Quote &) = default;
  Quote &operator=(Quote &&) = default;

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual std::ostream &debug(std::ostream &os) const {
    os << "Quote::bookNo " << bookNo << " Quote::price " << price;
    return os;
  }


protected:
  double price = 0.0;

private:
  std::string bookNo;
};

class Disc_quote : public Quote {
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


  double net_price(std::size_t n) const = 0;


  std::ostream &debug(std::ostream &os) const override {
    Quote::debug(os) << " Disc_quote::quantity " << quantity
        << " Disc_quote::discount " << discount;
    return os;
  }


protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
  using Disc_quote::Disc_quote;

  double net_price(std::size_t n) const override {
    if (n >= quantity)
      return n * price * (1 - discount);
    else
      return n * price;
  }

};

class Limit_quote : public Disc_quote {
public:
  using Disc_quote::Disc_quote;

  double net_price(std::size_t n) const override {
    if (n <= quantity)
      return n * price * (1 - discount);
    else
      return (n - quantity) * price + quantity * price * (1 - discount);
  }

};

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}




int main() {
  //test_copy_control_members();

  std::vector<std::shared_ptr<Quote>> v;
  v.push_back(std::make_shared<Quote>("abc", 5.5));
  v.push_back(std::make_shared<Bulk_quote>("abc", 5.5, 10, 0.2));
  v.push_back(std::make_shared<Limit_quote>("abc", 5.5, 10, 0.2));

  //for (const auto &q : v)
  //  print_total(std::cout, *q, 20);
  for(auto q : v){
    q->debug(std::cout) << std::endl;
    std::cout << q->net_price(15) << std::endl;
  }

  return 0;
}