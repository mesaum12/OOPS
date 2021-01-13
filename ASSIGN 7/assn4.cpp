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
       cout<<"Name:";
       cin>>name;
       cout<<"Score:";
       cin>>score;
   }
   void show_details()
   {
       cout<<"ROll:";
       cout<<roll<<" ";
       cout<<"Name:";
       cout<<name<<" ";
       cout<<"Score:";
       cout<<score<<" ";
   }
   bool operator<(const student &s) const{
        return score<s.score;
   }
   int ret_score(){return score;}
   int ret_roll(){return roll;}
   char* ret_name(){return name;}

};
void add_student(priority_queue<student>&s)
{
      student s1;
      s1.set_details();
      s.push(s1);
}
void display_student(priority_queue<student>&q)
{
    while(!q.empty())
    {
        student s;
        s=q.top();
        s.show_details();
        cout<<"\n";
        q.pop();
    }
}
int main()
{
    priority_queue<student>s;
    int choice;
    while(1)
    {
      cout<<"1.Add student \n";
      cout<<"2.Display student\n";
      cout<<"3.exit the program\n";
      cout<<"Enter your choice\n";
      cin>>choice;
      switch(choice)
      {
          case 1:
                add_student(s);
                break;
          case 2:
                display_student(s);
                break;
          case 3:
                exit(0);
         
          default:
               cout<<"Invalid choice\n";
      }
    }
    return 0;
}