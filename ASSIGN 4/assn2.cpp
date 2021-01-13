#include<iostream>
using namespace std;
class Complex
{
    int real;
    int imag;
    public:
    Complex(int r=0,int i=0)
    {
        real=r;
        imag=i;
    }
   friend Complex operator+(Complex ,Complex);
   friend Complex operator-(Complex ,Complex);
   friend ostream& operator<<(ostream &os,Complex &t);
   friend void operator>>(istream &is,Complex &c);
};
Complex operator+(Complex t1,Complex t)
{
        Complex c;
        c.real=t1.real+t.real;
        c.imag=t1.imag+t.imag;
        return c;
}
Complex operator-(Complex t1,Complex t)
{
        Complex c;
        c.real=t1.real-t.real;
        c.imag=t1.imag-t.imag;
        return c;
}
ostream& operator<<(ostream &os,Complex &t)
{
       os<<t.real<<"+"<<t.imag<<"i"<<"\n";
        return os;
}
void operator>>(istream &is,Complex &c)
{
       cout<<"Real:";
       is>>c.real;
       cout<<"Imag:";
       is>>c.imag;
}
   
int main()
{
   Complex c1(4,5),c2(7,9),c3,c4,c5;
   c5=c1+c2;
   cout<<c5<<"\n";
   cin>>c3;
   cout<<c3;
   c5=7+c2;
   cout<<c5<<"\n";
   return 0;

}