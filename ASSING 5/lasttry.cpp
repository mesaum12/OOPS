#include<iostream>
using namespace std;
class SingleCopy
{
    int serial_num;
    int number_of_copies;
    public:

    void set_serial_num()
    {
        cout<<"Serial num:";
        cin>>serial_num;

    }
    void set_number_of_copies()
    {
        cout<<"Number of copies of this serial number:";
        cin>>number_of_copies;
    }
    int ret_serial_num()
    {
        return serial_num;
    }
    int ret_number_of_copies();
};
class Book
{
   int book_id;
   int count_of_avl_serial_nums; 
   SingleCopy Cb[10];
   char title[30];
   char author[30];
   char publisher[30];
   float price;
   public:
   void set_details()
   {
       cout<<"Book Id:";
       cin>>book_id;
       cout<<"count of avl serial nums:";
       cin>>count_of_avl_serial_nums;
       for(int i=0;i<count_of_avl_serial_nums;i++)
       {
           Cb[i].set_serial_num();
           Cb[i].set_number_of_copies();
       }
   }
   int ret_book_id()
   {
       return book_id;
   }
   int ret_count_of_avl_serial_nums()
   {
       return count_of_avl_serial_nums;
   }
   SingleCopy* ret_single_copy_ptr()
   {
       return Cb;
   }
  

};
class Booklist
{
    Book b[100];
    int total_number_of_books;
    public:
    Booklist(int n=0)
    {
        total_number_of_books=n;
    }
    int ret_total_number_of_books();
    Book ret_ith_book(int i)
    {
        return b[i];
    } 
     int available_book(int book_id,int serial_num)
     {
       for(int i=0;i<total_number_of_books;i++)
       {
          if(b[i].ret_book_id()==book_id)
          {
              for(int j=0;j<b[i].ret_count_of_avl_serial_nums();j++)
              {
                   if((b[i].ret_single_copy_ptr()+j)->ret_serial_num()==serial_num 
                   && (b[i].ret_single_copy_ptr()+j)->ret_number_of_copies()>0)
                   return 1;
              }
          }

       }
       return 0;
     }
};
class Member
{
   int member_id;
   char name[31];
   char address[31];
   char email_id[30];
   public:
   void set_member_details();
   int ret_member_id();
};
class Faculty:public Member
{
   int current_number_of_book_issues;
   public:
   void set_current_number_of_book_issues()
   {
       current_number_of_book_issues=0;
   }
   int ret_current_number_of_book_issues()
   {
       return current_number_of_book_issues;
   }
};
class Student:public Member
{
   int current_number_of_book_issues;
   public:
   int ret_current_number_of_book_issues();
   void set_current_number_of_book_issues()
   {
       current_number_of_book_issues=0;
   }
};
class FacultyList
{
   Faculty f[50];
   int total_number_faculties;
   public:
   FacultyList(int n=0)
   {
       total_number_faculties=n;
   }
   int ret_total_number_faculties()
   {
       return total_number_faculties;
   }
   Faculty ret_ith_faculty(int i)
   {
      return f[i];
   }
   int check_eligibility(Transaction &t)
   {
       for(int i=0;i<total_number_faculties;i++)
       {
           if(f[i].ret_member_id()==t.ret_member_id() && f[i].ret_current_number_of_book_issues()<10)
           return 1;
       }
       return 0;
   }
};
class StudentList
{
   Student s[50];
   int total_number_students;
   public:
   StudentList(int n=0)
   {
       total_number_students=n;
   }
   int ret_total_number_students()
   {
       return total_number_students;
   }
   Student ret_ith_student(int i)
   {
        return s[i];
   }
    int check_eligibility(Transaction &t)
   {
       for(int i=0;i<total_number_students;i++)
       {
           if(s[i].ret_member_id()==t.ret_member_id() && s[i].ret_current_number_of_book_issues()<2)
           return 1;
       }
       return 0;
   }
};
class Transaction
{
    int member_id;
    int book_id;
    int serial_number;
    int issue_or_return;//1 for issue and 2 for return
    int faculty_or_student;//0 for faculty 1 for student
    public:
    int ret_member_id();
    int ret_serial_number();
    void get_trans_details(int type)
    {
        issue_or_return=type;
       
        cout<<"Enter the book_id";
        cin>>book_id;
        cout<<"Enter the serial number:";
        cin>>serial_number;
        cout<<"Enter the member id:";
        cin>>member_id;
        cout<<"Enter 0 for faculty and 1 for student issue\n";
        cin>>faculty_or_student;

    }
    int ret_faculty_or_student()
    {
        return faculty_or_student;
    }
};
class TransactionList
{
   Transaction t[50];
   static int current_number_of_trans;
   public:
   TransactionList(int t=0)
   {}
   static int ret_current_number_of_trans()
   {
       return current_number_of_trans;
   }
   Transaction ret_ith_trans();
};
int TransactionList::current_number_of_trans=0;//static variable declaration

int main()
{
    int n,choice;
    cout<<"total number of books in the library\n";
    cin>>n;
    Booklist l(n);
    for(int i=0;i<n;i++)
    l.ret_ith_book(i).set_details();

    cout<<"Enter the number of faculties:";
    cin>>n;
    FacultyList fl(n);
    for(int i=0;i<n;i++)
    {
        fl.ret_ith_faculty(i).set_member_details();
        fl.ret_ith_faculty(i).set_current_number_of_book_issues();
    }

    cout<<"Enter the number of students:";
    cin>>n;
    StudentList sl(n);
    for(int i=0;i<n;i++)
    {
        sl.ret_ith_student(i).set_member_details();
        sl.ret_ith_student(i).set_current_number_of_book_issues();
    }

    TransactionList tl;//initialising the transaction list at the beginning 
    while(1)
    {
        cout<<"1.Issue a book\n";
        cout<<"2.Return a book\n";
        cout<<"3.Exit the program\n";
        cout<<"Enter your choice\n";
        cin>>choice;
        Transaction t;
        t.get_trans_details(choice);//we got the transaction detials now 
        //case 1 :issue
        if(choice==1)
        {
            //if the book is available
             if(l.available_book(t.ret_member_id(),t.ret_serial_number()))
             {
                   //case 1.1 check for the faculty and eligiblity and do the updations
                   if(t.ret_faculty_or_student()==0)
                   {
                         if(fl.check_eligibility(t))//the faculty is eligible now do the updations
                         {
                               fl.update_number_of_current_issues()
                         }
                         else
                         {
                             cout<<"Sorry this member is not eligible\n";
                         }
                         
                   }
                   //case 1.2 check for student the eligibility and do the updations 
                   else
                   {
                       
                   }
                   
             }
             else
             {
                 cout<<"Sorry the book is not available\n";
             }
             
        }
        //case 2:return the book
        else if(choice==2)
        {
            
        }
        else
        {
            cout<<"You decided to exit -----ThankYou---- \n";
            exit(0);
        }
        


    }
    return 0;
}

