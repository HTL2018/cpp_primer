#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    /* //test1_9
    int i = 50;
    int total = 0;
    while(i < 100)
    {
        total = total + i;
        i++;
    }
    cout << "The sum of 50 to 100 is" << total << "." << endl;
    */

    /* //test1_10
    int i = 10;
    int sum = 0;
    while(i>=0)
    {
        sum += i;
        i--;
    }
    cout << "The sum of 0 to 10 is " << sum << "." << endl;
    */

    /* //test1_11
    int big = 0, small = 0;
    int trans = 0;
    cin >> big >> small;
    if(big == small)
    {
        cout << "The two num is same." << endl;
    }
    else
    {
        if (big < small)
        {
            trans = big;
            big = small;
            small = trans;
        }
        while(small < big+1)
        {
            cout << small << endl;
            small++;
        }

    }
    */

    struct Sales_data {
        string bookNo;//索书号
        unsigned units_sold = 0;//书的本数
        double revenue = 0.0;//本次书的销售总额
    };

    /* //test1_20
    Sales_data book;
    while(cin >> book.bookNo >> book.units_sold >> book.revenue)
    {
        cout << book.bookNo << " " << book.units_sold << " " << book.revenue << endl;
    }
    */

    /* //test1_21
    Sales_data book1,book2;
    cin >> book1.bookNo >> book1.units_sold >> book1.revenue;
    cin >> book2.bookNo >> book2.units_sold >> book2.revenue;
    if(book1.bookNo == book2.bookNo)
    {
        cout << "Sum is " << book1.revenue + book2.revenue << "." << endl;
    }
    else
    {
        cout << "Not same." << endl;
    }
    */

    /* //test1_22
    Sales_data book1, book2;
    cin >> book1.bookNo >> book1.units_sold >> book1.revenue;
    while(cin >> book2.bookNo >> book2.units_sold >> book2.revenue)
    {
        if (book1.bookNo == book2.bookNo)
        {
            book1.units_sold += book2.units_sold;
            book1.revenue += book2.revenue;
        }
        else
        {
            cout << book1.bookNo << " " << book1.units_sold << " " << book1.revenue << endl;
            book1.bookNo = book2.bookNo;
            book1.units_sold = book2.units_sold;
            book1.revenue = book2.revenue;
        }
    }
    cout << book1.bookNo << " " << book1.units_sold << " " << book1.revenue << endl;
    */

    /* //test1_23
    Sales_data book1,book2;

    cin >> book1.bookNo >> book1.units_sold >> book1.revenue;
    int cnt = 1;
    while(cin >> book2.bookNo >> book2.units_sold >> book2.revenue)
    {
        if (book1.bookNo == book2.bookNo)
        {
            cnt += 1;
        }
        else
        {
            cout << book1.bookNo << " " << cnt << "." << endl;
            book1.bookNo = book2.bookNo;
            book1.units_sold = book2.units_sold;
            book1.revenue = book2.revenue;
            cnt = 1;
        }
    }
    cout << book1.bookNo << " " << cnt << "."<< endl;
    */

    return 0;
}
