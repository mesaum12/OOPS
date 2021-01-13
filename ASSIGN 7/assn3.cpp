//queue data structure to be used in order to have the first come first serve basis fulfilled
#include<iostream>
#include<queue>
using namespace std;
class student
{
   int roll;
   char name[31];
   int score;
   public:
   student(){}
   void set_details()
   {
       cout<<"ROll:";
       cin>>roll;
       cout<<"Name";
       cin>>name;
       cout<<"Score:";
       cin>>score;
   }
   void show_details()
   {
       cout<<"ROll:";
       cout<<roll<<" ";
       cout<<"Name";
       cout<<name<<" ";
       cout<<"Score:";
       cout<<score<<" ";
   }
   int ret_score(){return score;}
   int ret_roll(){return roll;}
   char* ret_name(){return name;}

};
void add_student(queue<student>&q)
{
    student s;
    s.set_details();
    q.push(s);
}
void display_details(queue<student>&q)
{
     student s;
     while(!q.empty())
     {
         s=q.front();
         s.show_details();
         q.pop();
     }
}
int main()
{
     queue<student>q;
     int choice;
    
     while(1)
     {
         cout<<"1.Add student \n";
         cout<<"2.display details \n";
         cout<<"3.exit the program\n";
         cout<<"Enter your choice\n";
         cin>>choice;
         switch(choice)
         {
             case 1:
                   add_student(q);
                   break;
             case 2:
                   display_details(q);
                   break;
             case 3:
                   exit(0);
             default:
              cout<<"Invalid choice\n";
         }
     }
     return 0;
}