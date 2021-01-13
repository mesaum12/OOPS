#include<iostream>
#include<cstdlib>
#include<cstring>
#define MAX 100
#define MAX_SUB 15
using namespace std;
class Subject
{
   int scode;
   char sname[10];
   public:
   void get_details(){
       cout<<"Subject Code:";
       cin>>scode;
       cout<<"Subject Name:";
       cin>>sname;
   }
   void show_sub_details()
   {
       cout<<"Subcode:"<<scode<<" "<<"Subject:"<<sname;
   }
   int get_scode(){
       return scode;
   }
};
class SubjectList
{
   Subject sub[MAX_SUB];
   int n;
   public:
  // Subject *get_sub_ptr(){return sub;}
    void get_number_of_subjects(int number)
    {
       n=number;
       for(int i=0;i<n;i++)
       sub[i].get_details();
    }
   int ret_number_of_subs(){
       return n;
   }
   void show_subjects()
   {
       for(int i=0;i<n;i++)
       {
            sub[i].show_sub_details();
            cout<<"\n";
       }
   }
   int chosen_subject_exists(int code)
   {
       for(int i=0;i<n;i++)
       {
           if(sub[i].get_scode()==code)
            return 1;
       }
       return 0;
   }
   
};
class Student 
{
   int roll;
   char name[31];
   SubjectList slist;
   public:
   void set_details()
   {
       int temp;
       cout<<"ROLL:";
       cin>>roll;
       cout<<"Name:";
       cin>>name;
       cout<<"Number of subjects chosen\n";
       cin>>temp;
       slist.get_number_of_subjects(temp);
       
   }
   void show_subjects()
   {
       slist.show_subjects();
       
   }
   int display_roll(){
       return roll;
   }
   void display_name()
   {
       cout<<name<<"\n";
   }
   SubjectList ret_subject_list()
   {
       return slist;
   }
};
class StudentList
{
   Student st[MAX];
   int n_students;
   
   public:
   StudentList(int n=0)
   {
       n_students=n;
   }
   void set_list()
   {
      for(int i=0;i<n_students;i++)
      {
          st[i].set_details();
      }
   }
   Student ret_student(int i)
   {
       return st[i];
   }
};
int main()
{
    int n,i,roll,flag,code;
    cout<<"Enter the number of students in the list\n";
    cin>>n;
    StudentList L(n);//creating a student list of n students 
    //taking the students details consisting of name,roll and subjects
    L.set_list();
    
    //provided student name display subjects
    int choice;
    while(1)
    {
        cout<<"1.Get subject details of a particular student\n";
        cout<<"2.Get student list for a particular subject\n";
        cout<<"3.Exit the program\n";
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                   flag=0;
                   cout<<"Enter the roll number of that student\n";
                   cin>>roll;
                   for(int i=0;i<n;i++)
                   {
                       if(L.ret_student(i).display_roll()==roll)
                       {
                            flag=1;
                            L.ret_student(i).show_subjects();
                       }
                   }
                   if(flag==0)
                   cout<<"Roll number not found\n";

                   break;

            case 2:
                   cout<<"Enter the subject code against which students are to be displayed\n";
                   cin>>code;
                   for(int i=0;i<n;i++)
                   {
                       if(L.ret_student(i).ret_subject_list().chosen_subject_exists(code))
                       L.ret_student(i).display_name();
                   }
                   cout<<"\n";
                   break;
                   
            case 3:
                  exit(0);

            default:
                  printf("Invalid choice\n");
        }
    }

    return 0;
}