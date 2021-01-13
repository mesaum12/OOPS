#include<iostream>
using namespace std;
class Cricketer
{
  protected:
  char name[31];
  char dob[15];
  int matches_played;
  public:
  void set_CricketerCommon_details()
  {
       cout<<"Name:";
       cin>>name;
       cout<<"Dob: ";
       cin>>dob;
       cout<<"Matches played: ";
       cin>>matches_played;
  }

};
class Batsmen:virtual public Cricketer
{
   protected:
   int total_runs;
   float avg_score;
   public:
   void set_other_details_batsmen()
   {
       cout<<" Total runs: ";
       cin>>total_runs;
       cout<<"Avg Score: ";
       cin>>avg_score;
   }
  /* void set_details()
   {
       cout<<"Name:";
       cin>>name;
       cout<<"Dob: ";
       cin>>dob;
       cout<<"Matches played: ";
       cin>>matches_played;
   }*/
   void show_batsmen_details()
   {
       cout<<"Name: of batsman";
       cout<<name;
       cout<<"Dob: ";
       cout<<dob;
       cout<<"Matches played: ";
       cout<<matches_played;
       cout<<"Total Runs:";
       cout<<total_runs;
       cout<<"average score:";
       cout<<avg_score;
   }
       
};
class Bowler:virtual public Cricketer
{
    protected:
   int no_of_wickets;
   float avg_economy;
   public:
   void set_other_details_bowler(){
       cout<<"No of Wickets\n";
       cin>>no_of_wickets;
       cout<<"Avg Economy: ";
       cin>>avg_economy;
   }
  /*  void set_details()
    {
       cout<<"Name:";
       cin>>name;
       cout<<"Dob: ";
       cin>>dob;
       cout<<"Matches played: ";
       cin>>matches_played;
      
    }
    */
   void show_bowler_details()
   {
       cout<<"Name: of Bowler";
       cout<<name;
       cout<<"Dob: ";
       cout<<dob;
       cout<<"Matches played: ";
       cout<<matches_played;
       cout<<"No of wickets:";
       cout<<no_of_wickets;
       cout<<"Avg Economy: ";
       cout<<avg_economy;
   }
};
class DoubleWicket
{
    
   Bowler bowler;
   Batsmen batmn;
   public:
   void set_pair_details()
   {
       bowler.set_CricketerCommon_details();
       bowler.set_other_details_bowler();
       batmn.set_CricketerCommon_details();
       batmn.set_other_details_batsmen();
   }
   void show_details()
   {
       batmn.show_batsmen_details();
       bowler.show_bowler_details();
   }

};
class Allrounder : public Batsmen, public Bowler
{
    public:

    void show_allrounder_details()
    {
         cout<<"Name:"<<name<<"\n";
         cout<<"Date Of Birth"<<dob<<"\n";
         cout<<"Matches Played"<<matches_played<<"\n";
         cout<<"Wickets taken"<<no_of_wickets<<"\n";
         cout<<"Avg Economy"<<avg_economy<<"\n";
         cout<<"Total Score"<<total_runs<<"\n";
         cout<<"Avg Score"<<avg_score<<"\n";

    }
};
int main()
{
    Allrounder al;
    al.set_CricketerCommon_details();
    al.set_other_details_batsmen();
    al.set_other_details_bowler();
    al.show_allrounder_details();

    Batsmen bt;
    bt.set_CricketerCommon_details();
    bt.set_other_details_batsmen();
    bt.show_batsmen_details();

    Bowler bo;
    bo.set_CricketerCommon_details();
    bo.set_other_details_bowler();
    bo.show_bowler_details();

    DoubleWicket d;
    d.set_pair_details();
    d.show_details();
    return 0;
}