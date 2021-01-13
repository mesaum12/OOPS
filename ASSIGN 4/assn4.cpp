#include<iostream>
#include<cstring>
using namespace std;
class String
{
   char *str;
   int size;
   public:
   //making the deafault constructor
   String(char *s='\0',int n=0)
   {
       size=n;
       if(size==0)
       str=nullptr;
       else
       {
           str=new char[size+1];
           strcpy(str,s);
       }
       
   }
  // overloading the copy constructor
   String(const String &s)
   {
        size=s.size;
        int i;
        if(size==0)
        str=nullptr;
        else
        {
            str=new char[size+1];
            for(i=0;i<size;i++)
            str[i]=s.str[i];
            str[i]='\0';
        }
   }
   //overloading the assignment operator
   void operator=(String &s)
   {
        size=s.size;int i;
        if(size==0)
        str=nullptr;
        else
        {
            str=new char[size+1];
            for(i=0;i<size;i++)
            str[i]=s.str[i];
            str[i]='\0';
        }
   }
   friend String operator+(String &s1,String &s2);
   bool operator==(String &s)
   {
       return (!strcmp(str,s.str));
   }
   bool operator<(String &s)
   {
       return (strcmp(str,s.str)<0);
   }
   bool operator>(String &s)
   {
       return (strcmp(str,s.str)>0);
   }
   friend ostream& operator<<(ostream &os,String &s);
};
   ostream& operator<<(ostream &os,String &s)
   {
       os<<s.str;
   }
   String operator+(String &s1,String &s2)
   {
       String temp;
       temp.size=strlen(s1.str)+strlen(s2.str)+1;
       temp.str=new char[temp.size];
       strcpy(temp.str,s1.str);
       strcat(temp.str,s2.str);
       //temp.size=s1.size+s2.size;
       return temp;
   }
int main()
{
   cout<<"This program is dealing with string class and corresponding operations\n\n";
   char name[]="Diwali";
   char name2[]="Happy";
   String s(name,strlen(name)+1);
   String s2(name2,strlen(name2)+1);
   cout<<"Copying  one string to another\n";
   String s3(s);//calling the copy constructor
   cout<<"Printing the newly copied string: "<<s3<<"\n";
   cout<<"Calling the assignment operator\n";
   s3=s2;
   cout<<"printing the newly assigned string: "<<s3<<"\n";
   cout<<"concatenating the strings and putting it in a new string \n";
   String temp=(s2+s);
   cout<<"Printing the concatenated string: "<<temp<<"\n";
   cout<<"\nchecking for the relational operators\n";
   bool flag=(s==s2);
   cout<<"checking for the equality:"<<flag<<"\n";
   flag=(s<s2);
   cout<<"checking for lesser: "<<flag<<"\n";
   flag=(s>s2);
   cout<<"checking for greater: "<<flag<<"\n";
   return 0;

}