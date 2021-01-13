/*For each student roll, name and phone number are to be maintained. For each subject store subject code, name. 
A student may choose number of subjects from a list of subjects. A subject may be chosen by number of students. 
Given a roll number system must able to display the subjects chosen by the student 
and also be able to display the students corresponding to a subject code. Design the classes and implement the system.*/
#include<iostream>
#define MAX 10
using namespace std;
class Subject
 {
     int sub_code;
     char sub_name[15];
     public:
     void set_sub_code()
     {
         cout<<"Subject Code:";
         cin>>sub_code;
     }
     void set_sub_name()
     {
         cout<<"Subject Name:";
         cin>>sub_name;
     }
     int ret_sub_code(){return sub_code;}
     char* ret_sub_name(){return sub_name;}
};
 class SubjectList
 {
     Subject subj[MAX];
     int number_of_subj;
     public:
     SubjectList(int n=0){number_of_subj=n;}
     void get_subjects(int number)
     {
         number_of_subj=number;
         for(int i=0;i<number;i++)
         {
              subj[i].set_sub_code();
              subj[i].set_sub_name();
         }
     }
     void display_subject_list(){
         for(int i=0;i<number_of_subj;i++)
         {
             cout<<"Subject Code:"<<subj[i].ret_sub_code()<<"Subject Name:"<<subj[i].ret_sub_name()<<"\n";
         }
     }
     int ret_number_of_subs(){
         return number_of_subj;
     }
     Subject ret_sub_i(int i){
         return subj[i];
     }
 };
class Student 
{
   int roll;
   char name[31];
   char phone_number[11];
   SubjectList Sl;
   public:
   void get_sub_list()
   {
       int x;
       cout<<"Enter the number of subjects chosen by this student\n";
       cin>>x;
       Sl.get_subjects(x);

   }
   void get_roll_number()
   {
       cout<<"Enter the roll number:";
       cin>>roll;
   }
   void get_name()
   {
       cout<<"Enter the  name:";
       cin>>name;
   }
   void get_phone_number()
   {
       cout<<"Enter the phone number:";
       cin>>phone_number;
   }
   int ret_roll(){
       return roll;
   }
   char* ret_name()
   {
       return name;
   }
   char* ret_phone_number()
   {
       return phone_number;
   }
   SubjectList return_sub_list(){
      return Sl;
   }
   int check_subject_chosen(int code)
   {
       int limit=Sl.ret_number_of_subs();
       for(int i=0;i<limit;i++)
       {
           if(Sl.ret_sub_i(i).ret_sub_code()==code)
            return 1;
       }
       return 0;
   } 
};
 
 class StudentList
 {
    Student s[100];
    int n;
    public:
    StudentList(int number=0)
    {
      n=number;
    }
    void list_init()
    {
       for(int i=0;i<n;i++)
       {
          
           s[i].get_roll_number();
           s[i].get_name();
           s[i].get_phone_number();
           s[i].get_sub_list();
       }
       
    }
    Student ret_student(int i){
        return s[i];
    }
   
 };
 
 int main()
 {
     int number,roll,flag=0,scode;
     cout<<"Enter the number of students \n";
     cin>>number;
     StudentList l(number);
     l.list_init();
     cout<<"Enter the roll number of the student whose subject list is to be displayed\n";
     cin>>roll;
     for(int i=0;i<number;i++)
     {
         if(l.ret_student(i).ret_roll()==roll)
         {
             l.ret_student(i).return_sub_list().display_subject_list();
             flag=1;
         }
     }
     if(flag==0)
     cout<<"The roll numeber is not found in the student list \n";
     cout<<"Enter a particular subject code to get the student list who chose the given subject\n";
     cin>>scode;
     for(int i=0;i<number;i++)
     {
         if(l.ret_student(i).check_subject_chosen(scode))
         cout<<l.ret_student(i).ret_name()<<"\n";
     } 
     return 0;
}