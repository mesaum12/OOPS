/*
1.	In a library, for each book book-id, serial number (denotes copy number of a book), title, author, 
publisher and price are stored. 
Book-id and serial number together will be unique identifier for a book. Members are either student or faculty. 
Each member has unique member-id. Name, e-mail, address are also to be stored. For any transaction 
(book issue or return), members are supposed to place transactions slip. User will submit member-id, 
book-id, and serial number (only for book return). While processing a transaction, check the validity of the member.
While issuing, availability of a copy of the book is to be checked. While returning a book,
 it is to be checked whether this copy was issued to the member or not. A student member can have 2 books 
 issued at a point of time. For faculty members it is 10. Transaction information is to be stored like date of
  transaction, member-id, book-id, serial number, returned or not. 
An entry is made when book is issued and updated when the book is returned.
*/
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10000
#define MAX_FACULTY_ISSUE 10
#define MAX_STUDENT_ISSUE 2
class UniqueCopy
{
    int book_id;
    int serial_number;
    int no_of_copies;
    public:
    void get_serial_number()
    {
        cout<<"Enter the serial number\n";
        cin>>serial_number;
    }
    void get_no_of_copies()
    {
        cout<<"Enter the no of copies\n";
        cin>>no_of_copies;
    }
    int return_serial_number(){
        return serial_number;
    }
    int return_number_of_copies()
    {
        return no_of_copies;
    }
    void update_num_of_copies()
    {
        no_of_copies++;
    }
    void update_num_of_copies_ret()
    {
        no_of_copies--;
    }
};
class BOOK
{
   int book_id;
   int count_of_avl_serial_nums;
   UniqueCopy Cb[10];//includes the sno for a particular bookid and no of copies of that serial number
   char title[30];
   char author[30];
   char publisher[30];
   float price;
   //int total_number_of_copies_avl;
   static int number_currently_avl;
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
           Cb[i].get_no_of_copies();
       }
       cout<<"Enter the title:";
       cin>>title;
       cout<<"Enter the author's name:";
       cin>>author;
       cout<<"Enter the publisher:";
       cin>>publisher;
       cout<<"Enter the price:";
       cin>>price;
      // cout<<"Enter the total number of copies available:";
       //cin>>total_number_of_copies_avl;
   }
   int return_book_id(){
       return book_id;
   }
   int return_copy_details(){
       for(int i=0;i<count_of_avl_serial_nums;i++)
       {
           if(Cb[i].return_number_of_copies())
           return 1;
       }
       return 0;
   }
   UniqueCopy
   * return_copy()
{
       return Cb;
   }
   int return_ind_serial_count(){
       return count_of_avl_serial_nums;
   }
};
int BOOK::number_currently_avl=0;
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
      current_number_of_issues=0;
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
     return (current_number_of_issues<10);
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
      cin>>email;
      cout<<"Address:";
      cin>>address;
      curr_number_of_issues=0;
    }
   int check_eligibility_student()
   {
       return (curr_number_of_issues<2);
   }
   void update_number_of_issues(){
       curr_number_of_issues++;
   }
    void update_number_of_issues_for_return(){
      curr_number_of_issues--;
  }
};
class FacultyList
{
   faculty f[300];
   int number;
  public:
   faculty ret_ith_faculty(int i)
   {
       return f[i];
   }
   int return_total_faculty()
   {
       return number;
   }
   int check_faculty_existence(int memid)
   {
       for(int i=0;i<number;i++)
       {
           if(f[i].return_member_id()==memid)
           {
               return 1;
           }
       }
       return 0;
   }
   FacultyList(int n=0){
       number=n;
   }
   friend void update_transaction_list(Transaction &t);
  
};
class studentlist
{
   student s[500];
   int number;
   public:
   student return_ith_student(int i)
   {
       return s[i];
   }
   int check_student_existence(int memid)
   {
       for(int i=0;i<number;i++)
       {
           if(s[i].return_member_id()==memid)
           return 1;
       }
       return 0;
   }
   studentlist(int n=0)
   {
       number=n;
   }
   int return_number_of_students(){
       return number;
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
   void set_returned_or_not(){
       returned_or_not=1;
   }
      void get_issue_details()
     {
       cout<<"Member id:";
       cin>>member_id;
       cout<<"Book Id:";
       cin>>book_id;
      // cout<<"Serial Number:";
       //cin>>serial_number;
       cout<<"Enter 1 for faculty and 2 for student\n";
       cin>>faculty_or_student;
       cout<<"Date of Transaction:";
       cin>>date_of_transaction;
       returned_or_not=0;
      // cout<<"Returned(1) or Not(0) ?";
       //cin>>returned_or_not;
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
        if(issue_or_return==0)
        get_issue_details();
        else
        get_return_details();
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
   int returned_or_not(){
       return returned_or_not;
   }
   int ret_faculty_or_student()
   {
       return faculty_or_student;
   }
   friend void update_book_details(Transaction &t)
   {
       
   }
   int ret_issue_or_return(){
       return issue_or_return;
   }
   void set_transaction_details(Transaction &t)
   {
       member_id=t.member_id;
       book_id=t.book_id;
       serial_number=t.serial_number;
       strcpy(date_of_transaction,t.date_of_transaction);
       faculty_or_student=t.faculty_or_student;//takes 1 for faculty and 2 for student
       issue_or_return=t.issue_or_return;//takes 0 for issue and 1 for return
       returned_or_not=t.returned_or_not;
   }
};
class TransactionList
{
    Transaction trans[MAX];
    static int current_number_of_trans;
    public:
    void set_initial(){
        current_number_of_trans=0;
    }
    Transaction get_ith_transaction(int i){
        return trans[i];
    }
    void add_transaction(Transaction &t)
    {
       trans[current_number_of_trans].set_transaction_details(t);
       current_number_of_trans++;
    }
    void update_transaction(Transaction &t)
    {
       for(int i=0;i<current_number_of_trans;i++)
       {
           if(trans[i].ret_member_id()==t.ret_member_id())
           {
               trans[i].set_returned_or_not();
           }
       }
    }
};
int TransactionList::current_number_of_trans=0;//setting initial number to be zero
class Booklist
{
   BOOK book_list[MAX];
   int number;
   public:
   Booklist(int n)
   {
       number=n;
   }
   void get_details()
   {
      for(int i=0;i<number;i++)
      book_list[i].set_details();
   }
   BOOK ret_ith_book(int i)
   {
       return book_list[i];
   }
   void update_book_details(Transaction &t)
   {
     
   }
   int check_availability_of_book(int book_id)
   {
         for(int i=0;i<number;i++)
         {
              if(book_list[i].return_book_id()==book_id){
                if(book_list[i].return_copy_details())
                {
                    return 1;
                }
         }
           return 0;
        }
   }
   void update_book_details_return(Transaction &t)
   {
       for(int i=0;i<number;i++)
       {
           if(book_list[i].return_book_id()==t.ret_book_id())
           {
               UniqueCopy
                *ptr=book_list[i].return_copy();
            int temp=book_list[i].return_ind_serial_count();
               for(int j=0;j<temp;i++)
               {
                   if((ptr+j)->return_serial_number()==t.ret_serial_number())
                   {
                      (ptr+j)->update_num_of_copies_ret();
                   }
               }
           }
       }
   }

};

int main()
{
   int n,book_id,serial_num,flag=0,type,stu_id,faculty_id,total_faculty,total_students;
   char name[30];
   cout<<"Enter the number of books in the library\n";
   cin>>n;
   //setting the details for all the books available in the library
   Booklist l(n);
   for(int i=0;i<n;i++)
   l.ret_ith_book(i).set_details();
   //setting the details for all the faculties
   cout<<"Enter the total number of faculties in the system:";
   cin>>total_faculty;
   FacultyList fl(total_faculty); 
   for(int i=0;i<total_faculty;i++)
   fl.ret_ith_faculty(i).set_faculty_details();
   //setting the details for all the students
   studentlist sl(total_students);
   for(int i=0;i<total_students;i++)
   sl.return_ith_student(i).set_student_details();
  
   //now we need to do the transaction of a book
   //put it inside a loop so that multiple transactions can be done here
   TransactionList tl;
   Transaction t;
   t.get_issue_or_return();
   
   if(t.ret_issue_or_return()==0 && l.check_availability_of_book(t.ret_book_id()) )
   flag=1;
   
   if(t.ret_issue_or_return()==0 && flag==0)
   cout<<"The book is not present\n";
   
   if(t.ret_issue_or_return()==0 && flag)
   {
       if(t.ret_faculty_or_student()==1)//1 for faculty
       {
          int temp=fl.return_total_faculty();
          for(int i=0;i<temp;i++)
          {
              if(fl.ret_ith_faculty(i).return_member_id()==t.ret_member_id() 
              && fl.ret_ith_faculty(i).check_eligibility_faculty())
              {
                  fl.ret_ith_faculty(i).update_number_of_issues();
                  tl.add_transaction(t);
                  l.update_book_details(t);
                  break;
              } 
          }

       }
       else if(t.ret_faculty_or_student()==2 && flag)
       {
            int temp=sl.return_number_of_students();
            for(int i=0;i<temp;i++)
            {
              if(sl.return_ith_student(i).return_member_id()==t.ret_member_id() 
              && sl.return_ith_student(i).check_eligibility_student())
              {
                  sl.return_ith_student(i).update_number_of_issues();
                  tl.add_transaction(t);
                  l.update_book_details(t);
                  break;
              } 
            }
       }
    }
       else if(t.ret_issue_or_return()==1)
      {
         if(t.ret_faculty_or_student()==1)//1 for faculty
        {
          int temp=fl.return_total_faculty();
          for(int i=0;i<temp;i++)
          {
              if(fl.ret_ith_faculty(i).return_member_id()==t.ret_member_id())
              {
                  fl.ret_ith_faculty(i).update_number_of_issues_for_return();
                  tl.update_transaction(t);
                  l.update_book_details_return(t);
                  break;
              } 
          }
        }
        else
        {
            int temp=sl.return_number_of_students();
            for(int i=0;i<temp;i++)
            {
              if(sl.return_ith_student(i).return_member_id()==t.ret_member_id())
              {
                  sl.return_ith_student(i).update_number_of_issues_for_return();
                  //tl.add_transaction(t);
                  tl.update_transaction(t);
                  l.update_book_details_return(t);
                  break;
              } 
            }
          
        }
   return 0;
}
