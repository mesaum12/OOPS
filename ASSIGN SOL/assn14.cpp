#include<iostream>
#include<cstring>
using namespace std;
class sales
{
   int item_code,qty_sold;
   public:
   void set_item_code(int ic){item_code=ic;}
   void get_qty_to_sell(int quan){ qty_sold=quan;}
   int ret_qty_sold(){return qty_sold; }
   friend void update_stock(sales &s);
   void set_details(int icode,int sell){item_code=icode,qty_sold=sell;}
   int get_item_code(){
       return item_code;
   }
};
class Item
{
   int item_code;
   float price;
   int qty;
   char name[31];

   public:
   void set_item(int i_code);
   void get_details();
   int get_item_code(){
       return item_code;
   }
   int get_quan(){return qty;}
   float get_price(){return price;}
   void update_stock(sales &s)
   {
      if(s.get_item_code()==item_code)
      {
        if(s.ret_qty_sold()<=qty)
         qty=qty-s.ret_qty_sold();
      }
      else
      cout<<"Item not available\n";
   }
    void change_rate(float new_rate)
   {
       price=new_rate;
   }
   void set_qty(int quan){qty=quan;}
};
void Item::set_item(int item_Code)
{
    //int i_code,qty;float price;char i_name[31];
    item_code=item_Code;
    cout<<"Enter the name of the item\n";
    cin>>name;
    cout<<"Enter the price\n";
    cin>>price;
    cout<<"Enter the qty available\n";
    cin>>qty;

}
void Item::get_details()
{
    cout<<"Item Code:"<<item_code<<" Name:"<<name<<" Price:"<<price<<" Quantity Avail:"<<qty<<"\n";

}
int search_item(int item_code,Item it[],int x=100)
{
    int i;
    for(i=0;i<x;i++)
    {
       if(it[i].get_item_code()==item_code)
       return i;
    }
    return -1;
}
int main()
{
    Item it[100];
    int number,choice,icode,quantity,t;
    cout<<"1.Enter the number of items\n";
    cin>>number;
    for(int i=0;i<number;i++)
    {
        cout<<"Enter the item code\n";
        cin>>icode;
        if(search_item(icode,it,i)==-1)
        it[i].set_item(icode);
        else
        {
            cout<<"Item is already present\n";
        }
        
    }
    while(1)
    {
        cout<<"-------Choose among the following options-------"<<"\n";
    cout<<"1.Display item details\n";
    cout<<"2.Sell a particular item\n";
    cout<<"3.Change the rate of an item\n";
    cout<<"4.Add an existing item\n";
    cout<<"5.Get the price of a particular item\n";
    cout<<"6.Get quantity available for a particular item\n";
    cout<<"7.Exit the program\n";
    cout<<"\nEnter your choice:";
    cin>>choice;
       switch(choice)
       {
        case 1:
               cout<<"Enter the item code\n";
               cin>>icode;
               if(search_item(icode,it,number)==-1)cout<<"Item is not present\n";
               else
               {
                   it[search_item(icode,it)].get_details();
                   cout<<"\n";
               }
               break;
        case 2:
              cout<<"Enter the item code to be sold\n";
              cin>>icode;
              t=search_item(icode,it,number);
              if(t==-1)cout<<"Item not present\n";
              else
              {
                  cout<<"Enter the quantity to be sold\n";
                  cin>>quantity;
                  sales s;
                  s.set_details(icode,quantity);
                  it[t].update_stock(s);

              }
              break;
              
              
        case 3:
               cout<<"Enter the item code whose rate is to be changed\n";
               cin>>icode;
               t=search_item(icode,it,number);
               if(t==-1)cout<<"Item not present\n";
               else
               {
                   cout<<"Enter the new rate:";
                   float nrate;cin>>nrate;
                   it[t].change_rate(nrate);
               }
               break;
               
        case 4:
               cout<<"Enter the item code :";
               cin>>icode;
               if(search_item(icode,it,number)==-1)
               cout<<"Item not found\n";
               else
               {
                   cout<<"Enter the qty to be added\n";
                   cin>>quantity;
                   t=search_item(icode,it);
                   it[t].set_qty(it[t].get_quan()+quantity);
               }
               break;
               
        case 5:
              cout<<"Enter the item_code \n";
              cin>>icode;
               t=search_item(icode,it,number);
              if(t==-1)cout<<"Item not found\n";
              else
              {
                  cout<<it[t].get_price()<<"\n";
              }
              break;
        case 6:
              cout<<"Enter the item_code \n";
              cin>>icode;
              t=search_item(icode,it,number);
              if(t==-1)cout<<"Item not found\n";
              else
              {
                  cout<<it[t].get_quan()<<"\n";
              }
              break;
        case 7:
              exit(0);

        default:
              cout<<"Invalid choice\n";
              

       }
    }
    
    return 0;
}
