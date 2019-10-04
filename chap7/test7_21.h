#ifndef CP5_test7_21_h
#define CP5_test7_21_h

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Sales_data {
    //friend
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);

    public:
    //constructor
        Sales_data() = default;
        Sales_data(const std::string &s) : bookNo(s) {  }
        Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {  }
        Sales_data(std::istream &is)  {read(is, *this);}

        string const& isbn() const { return bookNo; };
        Sales_data& combine(const Sales_data&);

    private:
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

//nomember functions
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

//member function
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
