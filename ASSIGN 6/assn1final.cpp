#include<iostream>
#include<fstream>
#include<cstring>
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
class Member
{
   protected:
   int member_id;
   char email[30];
   char address[50];
   public:
   int return_member_id()
   {
       return member_id;
   }
   char* return_email()
   {
       return email;
   }
   char* return_address()
   {
       return address;
   }

};
class faculty:public Member
{
  int current_number_of_issues;
  public:
  void set_faculty_details()
  {
      cout<<"Member Id:";
      cin>>member_id;
      cout<<"Email:";
      cin>>email;
      cout<<"Address:";
      cin>>address;
      current_number_of_issues=0;//setting the initial number of issues of any faculty to be zero 
  }
  int ret_number_of_issues()
  {
      return current_number_of_issues;
  }
  void update_number_of_issues()
  {
      current_number_of_issues++;
  }
   int  check_eligibility_faculty()
  {
     return (current_number_of_issues<10);//for faculty maxm no issued at any point of time is 10 
  }
  void update_number_of_issues_for_return(){
      current_number_of_issues--;
  }
};
class student:public Member
{
     int curr_number_of_issues;
     public:
     void set_student_details()
     {
      cout<<"Member Id:";
      cin>>member_id;
      cout<<"Email:";
      getchar();
      cin>>email;
      cout<<"Address:";
      getchar();
      cin>>address;
      curr_number_of_issues=0;
    }
   int check_eligibility_student()
   {
       return (curr_number_of_issues<2);//for student the current number of issues at any point of time is 2
   }
   void update_number_of_issues(){
       curr_number_of_issues++;
   }
    void update_number_of_issues_for_return(){
      curr_number_of_issues--;
  }
};
class Transaction
{
   int member_id;
   int book_id;
   int serial_number;
   char date_of_transaction[15];
   int faculty_or_student;//takes 1 for faculty and 2 for student
   int issue_or_return;//takes 0 for issue and 1 for return
   int returned_or_not;//takes 1 if returned otherwise 0
   public:
    Transaction(int s=0){}
     void get_issue_details()
     {
       cout<<"Member id:";
       cin>>member_id;
       cout<<"Book Id:";
       cin>>book_id;
       cout<<"Serial Number:";
       cin>>serial_number;
       cout<<"Enter 1 for issue by faculty and 2 for student\n";
       cin>>faculty_or_student;
       cout<<"Date of Transaction:";
       cin>>date_of_transaction;
       returned_or_not=0;
     }
     void get_return_details()
     {
       cout<<"Member id:";
       cin>>member_id;
       cout<<"Book Id:";
       cin>>book_id;
       cout<<"Serial Number:";
       cin>>serial_number;
     }
    void get_issue_or_return()
    {
        cout<<"Enter 0 for issue and 1 for return:";
        cin>>issue_or_return;
        if(issue_or_return==0)
        get_issue_details();//if the book is to be issued check it
        else
        get_return_details();//if the book is to be returned take the necessary details
    }
    int ret_member_id(){
       return member_id;
   }
   int ret_book_id(){
       return book_id;
   }
   int ret_serial_number(){
       return serial_number;
   }
   char* ret_date_of_trans(){
     return date_of_transaction;
   }
   int book_returned_or_not(){
       return returned_or_not;
   }
   int ret_faculty_or_student()
   {
       return faculty_or_student;
   }
    int ret_issue_or_return(){
       return issue_or_return;
   }
   void set_transaction_details(Transaction &t)//this is particularly for the transaction list class setting method
   {
       member_id=t.member_id;
       book_id=t.book_id;
       serial_number=t.serial_number;
       strcpy(date_of_transaction,t.date_of_transaction);
       faculty_or_student=t.faculty_or_student;//takes 1 for faculty and 2 for student
       issue_or_return=t.issue_or_return;//takes 0 for issue and 1 for return
       returned_or_not=t.returned_or_not;//for an issue takes 0 becomes 1 when returned
   }
     void update_transaction_return()
    {
        returned_or_not=1;
    }
};
//check from here 
bool check_availability_of_book(int book_id,int serial_num,char *fn)
{
    ifstream f;BOOK b;
    f.open(fn,ios::in|ios::binary);
    while(!f.eof())
    {
        f.read((char *)&b,sizeof(BOOK));
        if(f.eof())break;
        if(b.return_book_id()==book_id )
        {
            if(b.return_serial_present(serial_num))
            {
              f.close();
              return true;
            }
            
        }
    }
    f.close();
    return false;
}

/*int return_total_faculty()
{
    int temp;
    fstream f;
    f.open("facultylist.dat",ios::binary);
    f.seekg(0,ios::end);
    temp=f.tellg()/sizeof(faculty);
    return temp;

}*/
void update_book_details(Transaction &t)
{
    fstream f("booklist.dat",ios::in|ios::out|ios::binary);
    BOOK b;
    while(!f.eof())
    {
       
       f.read((char*)&b,sizeof(BOOK));
       if(f.eof())break;
       if(b.return_book_id()==t.ret_book_id())
       {
           /* if(t.ret_issue_or_return()==0)
            b.return_copy()->update_num_of_copies();
            else if(t.ret_issue_or_return()==1)
            b.return_copy()->update_num_of_copies_ret();
            f.seekp(-1*sizeof(BOOK),ios::cur);//move the pointer or marker to the position for changing the data 
            f.write((char*)&b,sizeof(BOOK));
            break;*/
            for(int j=0;j<b.return_ind_serial_count();j++)
             {
                 if((b.return_copy()+j)->return_serial_number()==t.ret_serial_number())
                 {
                     if(t.ret_issue_or_return()==0)
                     (b.return_copy()+j)->update_num_of_copies();
                     else if(t.ret_issue_or_return()==1)
                     (b.return_copy()+j)->update_num_of_copies_ret();
                     f.seekp(-1*sizeof(BOOK),ios::cur);//move the pointer or marker to the position for changing the data 
                     f.write((char*)&b,sizeof(BOOK));
                     break;
                     f.close();
                     return;
                 }
             }
            
       }
    }
    f.close();
    if(f.eof())
    f.clear();
    
}
void update_list(Transaction &t,char *fn)//make it for student too 
{
    fstream f;
    f.open(fn,ios::out|ios::in);
    while(!f.eof())
    {
        if(t.ret_faculty_or_student()==1 )
        {
           faculty fs;
           f.read((char*)&fs,sizeof(faculty));
           if(fs.return_member_id()==t.ret_member_id() )
           {
            fs.update_number_of_issues_for_return();
            f.seekp(-1*sizeof(faculty),ios::cur);
            f.write((char*)&fs,sizeof(faculty));
            break;
           }
        }
        else
        {
           student st;
           f.read((char*)&st,sizeof(student));
           if(st.return_member_id()==t.ret_member_id() )
           {
            st.update_number_of_issues_for_return();
            f.seekp(-1*sizeof(student),ios::cur);
            f.write((char*)&st,sizeof(student));
            break;
           }
        }
    }
    f.close();
}
int main()
{
    
    ofstream flout,slout,blout,tlout;//for appending data to these files
    fstream bl;
    int flag=0,temp,exit_controller;
    //flout.open("facultylist.dat",ios::app|ios::binary);
    //slout.open("studentlist.dat",ios::app|ios::binary);
    //blout.open("booklist.dat",ios::app|ios::binary);
    
    faculty f;
    student s;
    BOOK b;

    //initialise the booklist by taking data from the user and then storing it in the file 
     blout.open("booklist.dat",ios::app|ios::binary);
     cout<<"initialise the booklist\n";
     while(1)
     {
      cout<<"Press 1 to exit:";
      cin>>temp;
      if(temp==1)break;
      b.set_details();
      blout.write((char*)&b,sizeof(BOOK));
     } 
     blout.close();
     
     //display book list 
     bl.open("booklist.dat",ios::in|ios::binary);
     while(!bl.eof())
     {
         bl.read((char*)&b,sizeof(BOOK));
         if(bl.eof())break;
         else
         cout<<b.return_book_id()<<" "<<b.ret_book_name()<<" "<<b.ret_price()<<"\n";
     }
     bl.close();

     
    //initialilse the faculty list and store the list in the text file facultylist.dat
     cout<<"initialilse the faculty list\n";
     flout.open("facultylist.dat",ios::app|ios::binary);
     do
     {
      cout<<"Press 1 to exit:";
      cin>>temp;
      if(temp==1)break;
      f.set_faculty_details();
      flout.write((char*)&f,sizeof(faculty));
     } while (1);
     flout.close();
     //initialilse the student list and store the list in the text file facultylist.dat
     cout<<"initialilse the student list\n"; 
     slout.open("studentlist.dat",ios::app|ios::binary);
     do
     {
      cout<<"Press 1 to exit:";
      cin>>temp;
      if(temp==1)break;
      s.set_student_details();
      slout.write((char*)&s,sizeof(student));
     } while (1);
     slout.close();
     //we have successfully made the book,student and faculty list and now we need to handle the case'
     //when book is to be issued and then store the correct details in the transaction list and update whenerver
     //the book is returned by the faculy or the student
     fstream fl,sl,tl;
     while(1)
     {
         flag=0;
         cout<<"--Welcome to the library management system \t press 1 to exit\n---";
         cin>>exit_controller;
         if(exit_controller==1)
         break;
         Transaction t;
     t.get_issue_or_return();
     char fn[31];
     strcpy(fn,"booklist.dat");
      if(t.ret_issue_or_return()==0 && check_availability_of_book(t.ret_book_id(),t.ret_serial_number(),fn))
      {
        flag=1;
        cout<<"Book is present \n";
      }
      else if(t.ret_issue_or_return()==0 && flag==0)
      cout<<"The book is not present\n";
      
   //case 1 :book available and has to be issued
   //block 1 begins here
    if(t.ret_issue_or_return()==0 && flag==1)
    {
       //case 1.1.issued in the name of faculty
       //block 1.1 begins here 
       if(t.ret_faculty_or_student()==1)//1 for faculty issue
       {
          fl.open("facultylist.dat",ios::in|ios::binary);
          faculty f;
          while(!fl.eof())
          {
             
             fl.read((char *)&f,sizeof(faculty));
             if(fl.eof())break;
             if(f.return_member_id()==t.ret_member_id() && f.check_eligibility_faculty())
             {
                 f.update_number_of_issues();
                 
                 fl.seekp(-1*sizeof(faculty),ios::cur);
                 fl.write((char*)&f,sizeof(faculty));
                
                 //append this transaction 
                 ofstream tl_out;
                 tl_out.open("transactionlist.dat",ios::app|ios::binary);
                 tl.write((char *)&tl,sizeof(Transaction));
                 tl_out.close();//closing the transaction file after we have appended the value

                 update_book_details(t);
                 break;
             }
             
          }
          fl.close();
       }
       //block 1.1. ends
       //case 1.2 issue by an student 
       //block 1.2 begins
        else if(t.ret_faculty_or_student()==2)//if the issue is to be done in the name of student
        {
            sl.open("studentlist.dat",ios::in|ios::ate|ios::binary);
            student s;
            while(!sl.eof())
            {
             sl.read((char *)&s,sizeof(student));
             if(s.return_member_id()==t.ret_member_id() && s.check_eligibility_student())
             {
                 s.update_number_of_issues();

                 sl.seekp(-1*sizeof(student),ios::cur);
                 sl.write((char*)&s,sizeof(student));

                 ofstream tl_out;
                 tl_out.open("transactionlist.dat",ios::app|ios::binary);
                 tl_out.write((char *)&tl,sizeof(Transaction));
                 tl_out.close();
                 update_book_details(t);
                 break;
             }

            }
            sl.close();
        }
        //block 1.2 ends here
    }
    //block 1 ends
    //case 2 for the return of a book ,carefully check the case for return of the book
    //block 2 begins
     else if(t.ret_issue_or_return()==1 && flag)
      {
         int setn=0;
         //block 2.1 begins that is return by faculty 
         if(t.ret_faculty_or_student()==1)//1 for faculty submits the book to the librarian
         {
           Transaction tr;
           tl.open("transaction.dat",ios::in|ios::out|ios::binary);
           while(!tl.eof())
           {
             
             tl.read((char *)&tr,sizeof(Transaction));
             if(tl.eof())break;
             if(tr.ret_member_id()==t.ret_member_id() && tr.ret_issue_or_return()==0)
             {
                strcpy(fn,"facultylist.dat");
                update_list(tr,fn);
                tr.update_transaction_return();
                tl.seekp(-1*sizeof(Transaction),ios::cur);
                tl.write((char*)&tr,sizeof(Transaction));
                update_book_details(t);
                setn=1;
                break;
              }
            }
            tl.close();
            if(setn==0)
            cout<<"The book was not issued in this faculty's name\n";
          }
         //block 2.1 ends 
         //block 2.2 begins
         else
         {
           Transaction tr;
           tl.open("transaction.dat",ios::in|ios::out|ios::binary);
           while(!tl.eof())
           {
                
                tl.read((char *)&tr,sizeof(Transaction));
                if(tl.eof())break;
                if(tr.ret_member_id()==t.ret_member_id() && tr.ret_issue_or_return()==0)
                {
                strcpy(fn,"studentlist.dat");
                update_list(tr,fn);
                tr.update_transaction_return();

                tl.seekp(-1*sizeof(Transaction),ios::cur);
                tl.write((char*)&tr,sizeof(Transaction));
                update_book_details(t);
                setn=1;
                break;
                }
              
            }
            tl.close();
            if(setn==0)
            cout<<"The book was not issued in this member's name\n";
            
        }
      
      }//block 2 ends here
     }
     cout<<"You chose to exit\n";
     fl.close();sl.close();bl.close();
     return 0;
}
       
