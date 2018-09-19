//
//  Sales_item.cpp
//  Practice
//
//  Created by 姚懿恒 on 2018/9/19.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Sales_item.hpp"
string Sales_item::getBookNo() const
{
    return this->bookNo;
}
double Sales_item::averangePrice() const
{
    if (this->units_sold)
        
        return this->revenue / this->units_sold;
    else
        return 0;
}


istream& operator>>(istream &is, Sales_item &item)
{
    double price;
    is >> item.bookNo>>item.units_sold >> price;
    if (is)
    {
        item.revenue = price;
    }
    else
    {
        item = Sales_item();
    }
    
    return is;
}
ostream& operator<<(ostream &out,const Sales_item &item)
{
    out << item.getBookNo()<<" " << item.units_sold
    << " " << item.revenue <<" "<<item.averangePrice();
    
    return out;
}
//相等相加相加等
Sales_item& Sales_item::operator+=(const Sales_item& item)
{
    this->units_sold += item.units_sold;
    this->revenue += item.revenue;
    
    return *this;
}
Sales_item operator+(const Sales_item& item1, const Sales_item& item2)
{
    Sales_item temp(item1);
    temp += item2;
    return temp;
}
bool operator==(const Sales_item &item1, const Sales_item &item2)
{
    return (item1.getBookNo() == item2.getBookNo() &&
            item1.units_sold == item2.units_sold &&
            item1.revenue == item2.revenue);
}

//bool operator!=(const Sales_item &item1, const Sales_item item2)
//{
//    return !(item1 == item2);
//}
