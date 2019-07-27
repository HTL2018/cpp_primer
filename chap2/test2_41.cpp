#include <iostream>

struct Sales_data{
    std::string bookNo;//索书号
    unsigned uvits_sold = 0;//本次卖出书的本书
    int revenue = 0;//书的单价
};

int main()
{/*  //test1_23
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
            }
            else
            {
                std::cout << data1.bookNo << "  " << cnt << std::endl;
                data1.bookNo = data2.bookNo;
                cnt = 1;
            }
        }
        std::cout << data1.bookNo << "  " << cnt << std::endl;
    }
   */
    /* // test1_20
    Sales_data data1;
        while(std::cin >> data1.bookNo >> data1.uvits_sold >> data1.revenue)
          {
              std::cout << data1.bookNo << "  " <<  data1.uvits_sold << "  " <<  data1.revenue << std::endl;
          }
    */


    /*test1_22 此处程序为自己添加,可以将输入的多组数据每种书的索书号和总销售额进行输出;(要求同种书籍要连续输入)
    double price = 0.0;//卖书所得总钱数
    Sales_data data1, data2;
    if(std::cin >> data1.bookNo >> data1.uvits_sold >> data1.revenue)
    {
        int cnt = 1;
        price = data1.uvits_sold*data1.revenue;
        while(std::cin >> data2.bookNo >> data2.uvits_sold >> data2.revenue)
        {
            if (data1.bookNo == data2.bookNo)
            {
                cnt += 1;
                price = price + data2.uvits_sold * data2.revenue;
            }
            else
            {
                if(cnt == 1)
                {std::cout << data1.bookNo << " " << data1.uvits_sold * data1.revenue << std::endl;}
                else
                {std::cout << data1.bookNo << " " << price << std::endl;}
                data1.bookNo = data2.bookNo;
                data1.uvits_sold = data2.uvits_sold;
                data1.revenue = data2.revenue;
                price = data2.uvits_sold * data2.revenue;
            }
        }
        std::cout << data1.bookNo << " " << price << std::endl;
    }
    */

    /*test1_21
    double price = 0.0;//卖书所得的总钱数
    Sales_data data1, data2;
    std::cin >> data1.bookNo >> data1.uvits_sold >> data1.revenue;
    std::cin >> data2.bookNo >> data2.uvits_sold >> data2.revenue;
    if (data1.bookNo == data2.bookNo)
    {
        std::cout << data1.bookNo << " " << data1.uvits_sold * data1.revenue + data2.uvits_sold * data2.revenue << std::endl;
    }
    else
    {
        std::cout << " Not Same." << std::endl;
    }
    */












    return 0;
}
