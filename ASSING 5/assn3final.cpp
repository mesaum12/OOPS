#include<iostream>
using namespace std;
class Employee
{
    protected:
    int id;
    float basic_pay;
    char name[31];
    public:
    void get_details(){
        cout<<"Id: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"Basic Pay: ";
        cin>>basic_pay;
    }
    virtual float calculate_salary(){

    }
    virtual void show_details(){

    }

};
class peremp:public Employee
{
    float salary;
    public:
    float calculate_salary(){
        salary=basic_pay+0.3*basic_pay+0.8*basic_pay;
    }
    void show_details()
    {
        cout<<"Salary of permanent employee is:"<<salary<<"\n";
    }
};
class contremp:public Employee
{
    float salary;
    float allowance;
    public:
    float calculate_salary(){
        cout<<"Enter the allowance \n";
        cin>>allowance;
        salary=allowance+basic_pay;
    }
    void show_details()
    {
        cout<<"Salary of contractual employee is:"<<salary<<"\n";
    }
};
int main()
{
   Employee *d;
   peremp p;
   contremp c;
   //A base class pointer to pointing to a 
   d=&p;
   d->get_details();
   d->calculate_salary();
   d->show_details();

   d=&c;
   d->get_details();
   d->calculate_salary();
   d->show_details();
   return 0;
}