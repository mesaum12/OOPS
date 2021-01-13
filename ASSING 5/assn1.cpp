#include<iostream>
#include<cstdlib>
#include<cstring>
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
   Subject *sub;
   int n;
   public:
   Subject *get_sub_ptr(){return sub;}
   void get_subjects(int n)
   {
       if(n==0)
       sub=nullptr;
       else
       {
           sub=new Subject[n+1];
           for(int i=0;i<n;i++)
           {
              (sub+i)->get_details();
           }
       }
       
   }
   ~SubjectList(){
       cout<<"subjectlist destructor is called here\n";
   }
   int get_number_of_subs(){
       return n;
   }
   void show_subjects()
   {
       for(int i=0;i<n;i++)
       {
           (sub+i)->show_sub_details();
            cout<<"\n";
       }
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
       slist.get_subjects(temp);
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
       cout<<"name";
   }
   int chosen_subject(int code)
   {
      int temp=slist.get_number_of_subs();
      for(int i=0;i<temp;i++)
      {
          if((slist.get_sub_ptr()+i)->get_scode()==code)
          return 1;
      }
      return 0;
   }
};
class StudentList
{
   Student *ptr;
   int n_students;
   public:
   StudentList(int n=0)
   {
       n_students=n;
       if(n_students==0)
       ptr=nullptr;
       else
       ptr=new Student[n_students];
   }
   Student* get_ptr(){
       return ptr;
   }
    ~StudentList(){
       
       cout<<"studentlist destructor is called here\n";
   }
};
int main()
{
    int n,i,roll,flag,code;
    cout<<"Enter the number of students in the list\n";
    cin>>n;
    StudentList L(n);//creating a student list of n students 
    //taking the students details consisting of name,roll and subjects
    for(int i=0;i<n;i++)
    {
        (L.get_ptr()+i)->set_details();
    }
    //provided student name display subjects
    int choice;
    while(1)
    {
        cout<<"1.Get subject details of a particular student\n";
        cout<<"2.Get student list for a particular subject\n";
        cout<<"3.Exit the program\n";
        cout<<"Enter your choice\n";
        cin>>choice;
        if(choice==5)break;
        switch(choice)
        {
            case 1:
                   flag=0;
                   cout<<"Enter the roll number of that student\n";
                   cin>>roll;
                   for(int i=0;i<n;i++)
                   {
                       if(((L.get_ptr()+i)->display_roll())==roll)
                       {
                            flag=1;
                           (L.get_ptr()+i)->show_subjects();
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
                       if((L.get_ptr()+i)->chosen_subject(code))
                       (L.get_ptr()+i)->display_name();
                   }
                   cout<<"\n";
                   break;
                   
            case 3:
                  exit(0);

            default:
                  printf("Invalid choice\n");
                  break;
        }
    }

    return 0;
}