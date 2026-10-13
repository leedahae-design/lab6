
#pragma once // 헤더가드 만들어야 여러번 include 해도 문제 없음
#include <iostream>

namespace leedahae2449069
{
  class book 
  {
    //private: 
    int ID;     // id: 1~1000
    int Price; // price:0~50000 
    void testID() 
    {
      if (ID< 1 || ID  > 1000)
      {
        std::cout<<"invalid book ID\n";
        std::exit(1);

      }

    }
    void testPrice()
    {
      if (Price< 0 || Price>50000)
      {
        std::cout<<"invalid book Price id\n";
        std::exit(1);
      }
    }
    public:
       book(int d=1,int p=0):ID{d}, Price{p}
       {
        testID(); testPrice();
       }

    void input()

    {
      std::cout<<"enter book ID:";
      std::cin >>ID; testID();
      std::cout<<"enter book Price:";
      std::cin >>Price; testPrice();



    }

    void setID(int d){ID=d;testID();}
    void setPrice(int p){Price=p;testPrice();}
    void print() const
    {
      std::cout << ID <<", "<< Price << "won\n";
    }
     friend std::ostream& operator<<(std::ostream& os, const book& b)
     {
      os << b.ID<< "," << b.Price <<"won\n";
      return os;
    
     }

    int getID() const {return ID;}
    int getPrice() const {return Price;}
    
    book operator++(){return book{ID, ++Price};} // price만 증가
    book operator++(int){return book{ID, Price++};}
    friend std::istream& operator>>(std::istream& is, book& b)
    {
      //is >> b.ID>> b.Price; b.testID(); b.testPrice();
      std::cout<<"enter book ID:";
      is >> b.ID; b.testID();
      std::cout<<"enter book Price:";
      is >> b.Price; b.testPrice();

      return is;
    }
   

     friend bool operator==(const book& b1, const book& b2)
     {
         return b1.ID == b2.ID && b1.Price == b2.Price;
     }

     friend int operator+(const book& b1, const book& b2)
     {
         return b1.Price + b2.Price;
     }

  }; // 여기에는 세미쿨론 넣어야 함. class는 정의라서. 끝이라는 의미로 세미쿨론
}
