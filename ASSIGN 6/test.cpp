#include<iostream>
#include<fstream>
using namespace std;
class UniqueCopy
{
    int no_of_copies;//always takes true or false value for presence or absence
    int serial_number;
    
    public:
    void get_serial_number()
    {
        cout<<"Enter the serial number\n";
        cin>>serial_number;
        no_of_copies=1;
    }
    int return_serial_number(){
        return serial_number;
    }
    int return_number_of_copies()
    {
        return no_of_copies;
    }
    void update_num_of_copies()//whenever the particular copy is issues the no of copies reduces to 0
    {
        no_of_copies=0;
    }
    void update_num_of_copies_ret()//whenever the particular copy is issues the no of copies becomes true or 1
    {
        no_of_copies=1;
    }
};
class BOOK
{
   int book_id;
   int count_of_avl_serial_nums;//counts the total serial numbers available for this particular book id 
   UniqueCopy Cb[10];//includes the sno for a particular bookid and true of false value for its absence or presence
   char title[30];
   char author[30];
   char publisher[30];
   float price;
   public:
   void set_details()
   {
       cout<<"Enter the book id:";
       cin>>book_id;
       cout<<"Enter the total number of serial numbers for this book id:";
       cin>>count_of_avl_serial_nums;
       for(int i=0;i<count_of_avl_serial_nums;i++)
       {
           Cb[i].get_serial_number();
           //Cb[i].get_no_of_copies();//take it to be a boolean variable since there can be only one serial no for a book
       }
       cout<<"Enter the title:";
       cin>>title;
       cout<<"Enter the author's name:";
       getchar();
       cin>>author;
       cout<<"Enter the publisher:";
       cin>>publisher;
       cout<<"Enter the price:";
       cin>>price;
    }
    int return_book_id()
    {
       return book_id;
    }
    UniqueCopy* return_copy()
   {
       return Cb;
   }
   int return_ind_serial_count()
   {
       return count_of_avl_serial_nums;
   }
    int return_serial_present(int serial_no)
    {
       for(int i=0;i<count_of_avl_serial_nums;i++)
       {
           if(Cb[i].return_serial_number()==serial_no && Cb[i].return_number_of_copies()==1)
           return 1;
       }
       return 0;
    }
    char* ret_book_name()
    {
        return title;
    }
    float ret_price(){
        return price;
    }
};
int main()
{
    int temp;
    ofstream fout;
    ifstream fin;
    fout.open("booklist.dat",ios::app|ios::binary);
    BOOK st;
    while(1)
    {
        cout<<"Press 1 to exit \n";
        cin>>temp;
        if(temp==1)break;
        st.set_details();
        fout.write((char*)&st,sizeof(BOOK));
    }
    fout.close();
    fin.open("booklist.dat",ios::in|ios::binary);
    while(!fin.eof())
    {
      fin.read((char*)&st,sizeof(BOOK));
      if(fin.eof())break;
      cout<<st.ret_book_name()<<"\n";
      cout<<"\n";
    }
    fin.close();
    return 0; 

}