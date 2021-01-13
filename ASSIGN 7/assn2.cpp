#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
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
bool compare(student &s1,student &s2)
{
    return s1.ret_score()>s2.ret_score();
}
void add_student(vector<student>&v)
{
    student s;
    s.set_details();
    v.push_back(s);

}
void display_list(vector<student>&v)
{
    for(int i=0;i<v.size();i++)
     v[i].show_details();
}
void my_merge(vector<student>&v,vector<student>&v1,vector<student>&res)
{
    vector<student>::iterator itr1,itr2;
    itr1=v.begin(),itr2=v1.begin();
    while(itr1!=v.end())
    {
        res.push_back(*itr1);
        itr1++;
    }
    
    while(itr2!=v1.end())
    {
       res.push_back(*itr2);
       itr2++;
    }
    
}
int main()
{
     vector<student>v,v1,res(50);
     vector<student>::iterator it;
     student s;
     string str;
     int choice,max;
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
     cout<<"9.sort the list \n";
     cout<<"10.display the complete list \n";
     cout<<"Enter your choice\n";
     cin>>choice;

     switch(choice)
     {
         case 1:
                add_student(v);
                break;
         case 2:
                s.set_details();
                for(it=v.begin();it!=v.end();it++)
                {
                    if((*it).ret_roll()==s.ret_roll())
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
               it=max_element(v.begin(),v.end());
               cout<<"The maximum score is :"<<(*it).ret_score()<<"\n";
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
         case 9:
               sort(v.begin(),v.end(),compare);
               cout<<"sort successful\n";
               break;
         case 10:
               display_list(v);
               break;
         case 11:
                cout<<"For Merging the list, initilise the second list \n";
                cout<<"Enter number of students in the second list \n";
                int number;
                cin>>number;
                for(int i=0;i<number;i++)
                add_student(v1);
                merge(v.begin(),v.end(),v1.begin(),v1.end(),res.begin());
                //my_merge(v,v1,res);
                display_list(res);
                break;
         default:
              cout<<"Invalid choice\n";
       }
     }
     return 0;
}