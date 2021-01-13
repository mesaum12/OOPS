#include<iostream>
using namespace std;
class Employee
{
   protected:
   int emp_id;
   char name[31];
   char designation[31];
   float basic_pay;
   public:
   virtual float calculate_salary(){}
   virtual void get_details(){}
   void get_emp_details()
   {
        cout<<"Enter the employee id\n";
        cin>>emp_id;
        cout<<"Enter the name\n";
        cin>>name;
        cout<<"Enter the designation\n";
        cin>>designation;
        cout<<"Enter the basic pay of the employee\n";
        cin>>basic_pay;
    }

};
class PermanentEmp:public Employee
{
   float salary;
   public:
   float calculate_salary()
   {
       float hra=0.3*basic_pay,da=0.8*basic_pay;
       salary=basic_pay+ hra + da;
   }
   void show_salary()
   {
       cout<<"Salary :"<<salary;
   }
   void get_details(){
       get_emp_details();
       calculate_salary();
   }
};
class ContractualEmp:public Employee
{
    float salary;
    float allowance;
    public:
    float calculate_salary()
    {
        cout<<"Enter the allowance\n";
        cin>>allowance;
        salary=basic_pay+allowance;
    }
    void show_salary()
    {
       cout<<"Salary :"<<salary;
    }
    void get_details(){
       get_emp_details();
       calculate_salary();
   }
};
int main()
{
   PermanentEmp *p;
   ContractualEmp *c;
   p->get_details();
   p->show_salary();
   cout<<"\n";
   c->get_details();
   c->show_salary();
   return 0;
}