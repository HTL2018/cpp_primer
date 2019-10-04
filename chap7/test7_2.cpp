#include <iostream>

struct Sales_data{
    std::string bookNo;//索书号
    unsigned uvits_sold = 0;//本次卖出书的本书
    int revenue = 0;//书的单价
    Sales_data& combine(const Sales_data&);
    std::string isbn() const { return this->bookNo; }
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    uvits_sold += rhs.uvits_sold;
    revenue += rhs.revenue;
    return *this;
}


int main()
{

    //test1_23
    Sales_data data1;
    if(std::cin >> data1.bookNo >> data1.uvits_sold >> data1.revenue)
    {
        Sales_data data2;
        int cnt = 1;
        while(std::cin >> data2.bookNo >> data2.uvits_sold >> data2.revenue)
        {
            if(data1.bookNo == data2.bookNo)
            {
                cnt += 1;
                data1.combine(data2);
            }
            else
            {
                std::cout << data1.bookNo <<  "  " << data1.uvits_sold << " " << data1.revenue << " " << cnt << std::endl;
                data1.bookNo = data2.bookNo;
                data1.uvits_sold = data2.uvits_sold;
                data1.revenue = data2.revenue;
                cnt = 1;
            }
        }
        std::cout << data1.bookNo <<  "  " << data1.uvits_sold << " " << data1.revenue << " " << cnt << std::endl;
    }

/*
    // test1_20
    Sales_data data1;
        while(std::cin >> data1.bookNo >> data1.uvits_sold >> data1.revenue)
          {
              std::cout << data1.bookNo << "  " <<  data1.uvits_sold << "  " <<  data1.revenue << std::endl;
          }
*/

    return 0;
}
