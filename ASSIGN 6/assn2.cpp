#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define MAX 10
class Exception
{
    char *name;
    public:
    Exception(char *s='\0')
    {
        name=new char[strlen(s)+1];
        strcpy(name,s);
    }
    void display()
    {
        cout<<name<<"\n";
    }
};
class student
{
   int roll;
   char name[31];
   int score;
   public:
   student(){}
   void set_details()
   {
       cout<<"Name:";
       cin>>name;
       cout<<"ROll:";
       cin>>roll;
       cout<<"Score:";
       cin>>score;
   }
   void show_details()
   {
       cout<<"Name: ";
       cout<<name<<"\n";
       cout<<"ROll: ";
       cout<<roll<<"\n";
       cout<<"Score: ";
       cout<<score<<"\n";
   }
   int ret_score(){
       return score;
   }
   int ret_roll()
   {
       return roll;
   }
   char* ret_name()
   {
       return name;
   }
};
void add_student(student **s,int *t)
{
    int temp=*t;
   ((*s)+temp)->set_details();
   (*t)++;
}
void display_details(student *s,int index,int current_count)
{
   ((s)+index)->show_details();
}
int main()
{
  int n,choice,current_count=0,index;
  cout<<"Enter the maximum number of students in the list\n";
  cin>>n;
  student *s;
  s=new student[n+1];
  while(1)
  {
      cout<<"1.Add student to the list\n";
      cout<<"2.Display students from the list against a particular index\n";
      cout<<"3.Exit from the program\n";
      cout<<"Enter your choice\n";
      cin>>choice;
      switch(choice)
      {
          case 1:
                if(current_count<n)
                add_student(&s,&current_count);
                else
                {
                    cout<<"The maximum number of students in the list is reached\n";
                }
                break;
          case 2:
                cout<<"Enter the index of the student to be displayed\n";
                cin>>index;
                try{
                     if(index>=current_count)
                     {
                         char temp[]="Please enter a valid index";
                         throw Exception(temp);
                     }
                     else
                     display_details(s,index,current_count);
                 }
                 catch(Exception &e)
                 {
                     e.display();
                 }
          case 3:
               exit(0);
         default:
               cout<<"Invalid choice\n";

      }

  }
    delete []s;
    return 0;
}