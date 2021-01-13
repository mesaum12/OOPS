#include<iostream>
using namespace std;
class Withdraw
{
    int ac_num;
    float amount;
    public:
    void get_withdrawal_details()
    {
        cout<<"Enter the account number :";
        cin>>ac_num;
        cout<<"Enter the amount to withdraw: ";
        cin>>amount;
    }
    friend class ACCOUNT;
    float ret_withdrawal_balance(){
        return amount;
    }
    int ret_withdrawal_account(){
        return ac_num;
    }
};
class ACCOUNT
{
   int account_number;
   float balance;
   public:
   int ret_account_number(){return account_number;}
   void get_balance()
   {
       cout<<"Account Balance:";
       cin>>balance;
   }
   void get_account_number(int acc)
   {
      account_number=acc;
   }
   void show_details()
   {
       cout<<"Account Number: ";
       cout<<account_number<<" ";
       cout<<"Balance: ";
       cout<<balance<<" ";
   }
   void update_account_details(Withdraw &w)
   {
       if(balance>=w.ac_num)
       {
           balance-=w.amount;
       }
   }
};

class Account_List
{
    ACCOUNT *ptr;
    public:
   
    ACCOUNT *get_pointer(){return ptr;}
    Account_List(int n=0)
    {
        if(n==0)
        ptr=nullptr;
        else
        ptr=new ACCOUNT[n];
    }
    
};

int main()
{
    int account_number,flag=0,flag1=0;
    int n;
    cout<<"Enter the number of accounts \n";
    cin>>n;
    Account_List l(n);
    ACCOUNT *ptr;
    ptr=l.get_pointer();//getting the start pointer of the list so that other values can be accessed 
  
    for(int i=0;i<n;i++)
    {
        flag1=0;//setting the flag1 to be zero 
        cout<<"Enter the account number\n";
        cin>>account_number;
        for(int j=0;j<i;j++)
        {
            if((ptr+j)->ret_account_number()==account_number)
            {
                cout<<"The account number already exists\n";
                flag1=1;
                break;
            }
        }
        if(flag1==0)
        {
             (ptr+i)->get_account_number(account_number);
             (ptr+i)->get_balance();
        }
       
    }
    cout<<"Displaying a particular account details\n";
    cout<<"Enter the account number\n";
    cin>>account_number;
    for(int i=0;i<n;i++)
    {
        if((ptr+i)->ret_account_number()==account_number)
        {
            (ptr+i)->show_details();
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"The account number do not exist please check the account number correctly\n";
    }
    Withdraw w;
    w.get_withdrawal_details();
    flag=0;
     for(int i=0;i<n;i++)
    {
        if((ptr+i)->ret_account_number()==w.ret_withdrawal_account())
        {
            (ptr+i)->update_account_details(w);
            (ptr+i)->show_details();
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"Account not found in the account list\n";
    }
    
    return 0;
} 