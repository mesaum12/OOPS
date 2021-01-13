#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
#define MAX_FACULTY_ISSUE 10
#define MAX_STUDENT_ISSUE 200
#define MAX_STUD 50
#define MAX_FAC 30
class UniqueCopy
{
    int no_of_copies;//always takes true or false value for presence or absence
    int serial_number;
    
    public:
    void get_serial_number()
    {
        cout<<"Enter the serial number\n";
        cin>>serial_number;
    }
    void get_no_of_copies()
    {
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
   UniqueCopy Cb[10];//includes the sno for a particular bookid and no of copies of that serial number
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
           Cb[i].get_no_of_copies();//take it to be a boolean variable since there can be only one serial no for a book
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
   Transaction(int s=0)
   {

   }
   void set_returned_or_not(){
       returned_or_not=1;
   }
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
   void set_transaction_details(Transaction &t)//this is paricularly for the transaction list class setting method
   {
       member_id=t.member_id;
       book_id=t.book_id;
       serial_number=t.serial_number;
       strcpy(date_of_transaction,t.date_of_transaction);
       faculty_or_student=t.faculty_or_student;//takes 1 for faculty and 2 for student
       issue_or_return=t.issue_or_return;//takes 0 for issue and 1 for return
       returned_or_not=t.returned_or_not;//for an issue takes 0 becomes 1 when returned
   }
     void update_transaction_return(Transaction &t)
    {
        returned_or_not=1;
    }
};
class FacultyList
{
   faculty f[MAX_FAC];//taking a maxm faculty to be 300
   int number;
   public:
   //the constructor to get the faculty list
    FacultyList(int n=0)
     {
       number=n;
     }

   faculty ret_ith_faculty(int i)
   {
       return f[i];
   }
   int return_total_faculty()
   {
       return number;
   }
   //checks for the existence of a particular faculty against a given member id 
   int check_faculty_existence(int mem_id)
   {
       for(int i=0;i<number;i++)
       {
           if(f[i].return_member_id()==mem_id)
           {
               return 1;
           }
       }
       return 0;
   }
   void update_number_of_issues(Transaction &t)
   {
       for(int i=0;i<number;i++)
       {
           if(t.ret_member_id()==f[i].return_member_id())
           {
               f[i].update_number_of_issues_for_return();
               break;
           }
       }
   }
   void get_details()
   {
       for(int i=0;i<number;i++)
       f[i].set_faculty_details();
   }
};

class studentlist
{
   student s[MAX_STUD];//initialising it with 500 at the initial
   int number;
   public:
   studentlist(int n=0)
   {
       number=n;
   }
   student return_ith_student(int i)
   {
       return s[i];
   }
   int check_student_existence(int mem_id)
   {
       for(int i=0;i<number;i++)
       {
           if(s[i].return_member_id()==mem_id)
           return 1;
       }
       return 0;
   }
   
   int return_number_of_students(){
       return number;
   }
   void update_number_of_issues(Transaction &t)
   {
       for(int i=0;i<number;i++)
       {
           if(t.ret_member_id()==s[i].return_member_id())
           {
               s[i].update_number_of_issues_for_return();
               break;
           }
       }
   }
    void get_details()
   {
       for(int i=0;i<number;i++)
       s[i].set_student_details();
   }
   
};
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
   void update_book_details(Transaction &t){
     for(int i=0;i<number;i++)
     {
         if(book_list[i].return_book_id()==t.ret_book_id())
         {
             for(int j=0;j<book_list[i].return_ind_serial_count();j++)
             {
                 if((book_list[i].return_copy()+j)->return_serial_number()==t.ret_serial_number())
                 {
                     (book_list[i].return_copy()+j)->update_num_of_copies();

                 }
             }
         }
     }
   }
  int check_availability_of_book(int book_id,int serial_no)
   {
         for(int i=0;i<number;i++)
         {
              if(book_list[i].return_book_id()==book_id)
              {
                if(book_list[i].return_serial_present(serial_no))
                return 1;
                else
                return 0;
              }
         }
        return 0;
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
   int return_no_of_total_books()
   {
       return number;
   }

};

class TransactionList
{
    Transaction trans[MAX];
    static int current_number_of_trans;//total number of transactions in the list 
    public:
    TransactionList(int t=0)
    {
        current_number_of_trans=0;
    }
    Transaction get_ith_transaction(int i)
    {
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
    static int return_current_num_of_trans()
    {
        return current_number_of_trans;
    }
    
};
int TransactionList::current_number_of_trans=0;//setting initial number to be zero


int main()
{
   int n,book_id,serial_num,flag=0,type,stu_id,faculty_id,total_faculty,total_students;
   int exit_controller;
   char name[30];
   cout<<"---------------WELCOME TO THE LIBRARY SYSTEM-------------\n";
   cout<<"Enter the number of books in the library\n";
   cin>>n;

   //setting the details for all the books available in the library
   Booklist l(n);
   l.get_details();

   //setting the details for all the faculties
   cout<<"Enter the total number of faculties in the system:";
   cin>>total_faculty;
   FacultyList fl(total_faculty); 
   fl.get_details();

   //setting the details for all the students
   cout<<"Enter the total number of students in the system:";
   cin>>total_students;
   studentlist sl(total_students);
   sl.get_details();
  
   //now we need to do the transaction of a book
   //put it inside a loop so that multiple transactions can be done here
   TransactionList tl;
   while(1)
   {
    flag=0;
    cout<<"Press 1 to exit\n";
    cin>>exit_controller;
    if(exit_controller==1)
    break;

    Transaction t;
    t.get_issue_or_return();//takes the value of issue or return and accordingly calls the function
   
    if(t.ret_issue_or_return()==0 && l.check_availability_of_book(t.ret_book_id(),t.ret_serial_number()))
    {
        flag=1;
        cout<<"Book is present \n";
    }
   
    else if(t.ret_issue_or_return()==0 && flag==0)
    cout<<"The book is not present\n";

   //case 1 :book available and has to be issued
   //block 1 begin
    if(t.ret_issue_or_return()==0 && flag==1)
   {
       //case 1.1.issued in the name of faculty
       //block 1.1
       if(t.ret_faculty_or_student()==1)//1 for faculty issue
       {
          int temp=fl.return_total_faculty();
          for(int i=0;i<temp;i++)
          {
              if(fl.ret_ith_faculty(i).return_member_id()==t.ret_member_id() && fl.ret_ith_faculty(i).check_eligibility_faculty())
              {
                  fl.ret_ith_faculty(i).update_number_of_issues();
                  tl.add_transaction(t);
                  l.update_book_details(t);
                  break;
              }
             
          }

    }
       //block 1.1. ends
       //case 1.2 issue by an student 
       //block 1.2 begins
        else if(t.ret_faculty_or_student()==2 )//if the issue is to be done in the name of student
        {
            int temp=sl.return_number_of_students();
            for(int i=0;i<temp;i++)
            {
              if(sl.return_ith_student(i).return_member_id()==t.ret_member_id() && sl.return_ith_student(i).check_eligibility_student())
              {
                  sl.return_ith_student(i).update_number_of_issues();
                  tl.add_transaction(t);
                  l.update_book_details(t);
                  break;
              } 
            }
        }
        //block 1.2 ends here
    }
    //block 1 end
    //carefully check the case for return continue from here onwards now on
    //block 2 begins
       else if(t.ret_issue_or_return()==1 && flag)
      {
         int setn=0;
         //block 2.1 begins that is return by faculty 
         if(t.ret_faculty_or_student()==1)//1 for faculty submits the book to the librarian
         {
           //check the transaction list if the book was issued in his name or not
           int temp=TransactionList::return_current_num_of_trans();
           for(int i=0;i<temp;i++)
           {
               if(t.ret_member_id()==tl.get_ith_transaction(i).ret_member_id() && tl.get_ith_transaction(i).ret_issue_or_return()==0)
               {
                   fl.update_number_of_issues(t);
                   tl.get_ith_transaction(i).update_transaction_return(t);
                   l.update_book_details_return(t);
                   setn=1;
                   break;

               }
              
           }
            if(setn==0)
            {
                cout<<"The book was not issued in this faculty's name\n";
            }
          
         }
         //block 2.1 ends 
         //block 2.2 begins
         else
         {
             setn=0;
             int temp=TransactionList::return_current_num_of_trans();
             for(int i=0;i<temp;i++)
            {
               if(t.ret_member_id()==tl.get_ith_transaction(i).ret_member_id() && 
               tl.get_ith_transaction(i).ret_issue_or_return()==0)
               {
                   sl.update_number_of_issues(t);
                   tl.get_ith_transaction(i).update_transaction_return(t);
                   l.update_book_details_return(t);
                   setn=1;
                   break;

               }
              
           }
            if(setn==0)
            {
                cout<<"The book was not issued in this member's name\n";
            }
        }
  
       }
       //block 2 ends here
   }
  cout<<"You chose to exit\n";
  return 0;
}
