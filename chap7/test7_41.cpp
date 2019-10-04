#include "test7_41.h"

using std::cout;
using std::endl;

// constructor
Sales_data::Sales_data(std::istream &is) : Sales_data()
{
    std::cout << "Sales_data(istream &is)" << std::endl;
    read(is, *this);
}

// member functions
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += revenue;
    return *this;
}

// friend function
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

int main()
{
    cout << "1. default way: " << endl;
    cout << "----------------" << endl;
    Sales_data s1;

    cout << "\n2. use std::string as parameter: " << endl;
    cout << "-----------------------------------" << endl;
    Sales_data s2("htl");

    cout << "\n3. complete parameter: " << endl;
    cout << "-------------------------" << endl;
    Sales_data s3("htl", 3, 25.8);

    cout << "\n4. use istream as parameter:" << endl;
    cout << "------------------------------" << endl;
    Sales_data s4(std::cin);

    return 0;
}
