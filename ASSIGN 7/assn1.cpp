#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
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
   bool operator<(const student &s) const{
     return score<s.score;
   }

};
int main()
{
     vector<student>v;
     vector<student>::iterator it,max_it;
     student s;
     string str;
     int choice,max,roll_to_remove;
     while(1)
     {
         cout<<"1.Add student \n";
     cout<<"2.Remove student\n";
     cout<<"3.display student details\n";
     cout<<"4.Return number of students\n";
     cout<<"5.Return student with highest score\n";
     cout<<"6.Show students with the current substring\n";
     cout<<"7.Show students without the current substring\n";
     cout<<"8.Exit the program\n";
     //cout<<"9.sort the list \n";
     cout<<"Enter your choice\n";
     cin>>choice;

     switch(choice)
     {
         case 1:
                s.set_details();
                v.push_back(s);
                break;
         case 2:
                //s.set_details();
                cout<<"Enter the roll number of the student to be removed from the list\n";
                cin>>roll_to_remove;
                for(it=v.begin();it!=v.end();it++)
                {
                    if((*it).ret_roll()==roll_to_remove)
                    {
                        v.erase(it);
                        cout<<"Data successfully removed\n";
                        break;
                    }
                }
                break;
         case 3:
               cout<<"Enter the roll number of the student whose details is to be displayed\n";
               int roll;
               cin>>roll;
                for(it=v.begin();it!=v.end();it++)
                {
                    if((*it).ret_roll()==roll)
                    {
                       (*it).show_details();
                       break;
                    }
                }
                break;
         case 4:
               cout<<"The number of students is :"<<v.size()<<"\n";
               break;
         case 5:
              /* max=v[0].ret_score();
               for(it=v.begin();it!=v.end();it++)
               {
                   if((*it).ret_score()>max)
                   max=(*it).ret_score();

               }
               cout<<"The maximum score is :"<<max<<"\n";
               break;*/
               max_it=max_element(v.begin(),v.end());
               cout<<"The maximum score is :"<<(*max_it).ret_score()<<"\n";
               break;
         case 6:
               cout<<"Enter the substring to be found in the name of the students\n";
               cin>>str;
               for(it=v.begin();it!=v.end();it++)
               {
                   string temp;
                   temp=(*it).ret_name();
                   int found=temp.find(str);
                   if(found!=string::npos)
                   {
                      cout<<temp<<"\n";
                   }
               }
               break;
         case 7:
               cout<<"Enter the substring to be found in the name of the students\n";
               cin>>str;
               for(it=v.begin();it!=v.end();it++)
               {
                   string temp;
                   temp=(*it).ret_name();
                   int found=temp.find(str);
                   if(found==string::npos)
                   {
                      cout<<"temp"<<"\n";
                   }
               }
               break;
         case 8:
               exit(0);
         
         default:
              cout<<"Invalid choice\n";
       }
     }
     return 0;
}