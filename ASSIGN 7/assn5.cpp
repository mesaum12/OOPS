#include<iostream>
#include<map>
using namespace std;
class student 
{
   int roll ;
   char name[31];
   int score;
   public:
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
   int ret_score(){return score;}
   int ret_roll(){return roll;}
   char* ret_name(){return name;}
};
void add_student(map<int,int>&mp)
{
    student s;
    s.set_details();
    mp.insert({s.ret_roll(),s.ret_score()});
    cout<<"Student added\n";
}
void display_student_marks(map<int,int>&mp,int roll)
{
   map<int,int>::iterator it;
   for(it=mp.begin();it!=mp.end();++it)
   {
       if(it->first==roll)
       {
           cout<<"The marks obtained by this student is: "<<it->second<<"\n";break;
       }
       
   }
   if(it==mp.end())
   {
       cout<<"The roll number doesn't exist \n";
   }
}
int main()
{
    //vector<student>v;
    map<int,int>mp;
    int choice,roll;
    while(1)
    {
      cout<<"1.Add student \n";
      cout<<"2.Display score for a particular roll\n";
      cout<<"3.exit the program\n";
      cout<<"Enter your choice\n";
      cin>>choice;
      switch(choice)
      {
          case 1:
                add_student(mp);
               // mp.insert(make_pair(s.ret_roll,s.))
                break;
          case 2:
                cout<<"Enter the roll number whose marks is to be displayed\n";
                cin>>roll;
                display_student_marks(mp,roll);
                break;
          case 3:
                exit(0);
         
          default:
               cout<<"Invalid choice\n";
               

      }
    }
    return 0;
}