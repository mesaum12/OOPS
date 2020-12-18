#include<iostream>
#include<cstring>
using namespace std;
class String
{
   char *ptr;
   int size;
   public:
   //creating the default string constructor
   String(int s=0)
   {
       size=s;
       if(s!=0)
       {
           ptr=new char[size+1];
           ptr[0]='\0';
       }
       else
       {
           ptr=nullptr;
       }
       
   }
   //overloading  the system provided string copy constructor 
   String(const String &s)
   {
      size=s.size;
      if(size!=0)
      {
          ptr=new char[size+1];
          for(int i=0;i<size;i++)
          ptr[i]=s.ptr[i];

      }
      else
      {
          ptr=nullptr;
      }
      
   }
   void operator=(String s)
   {
        size=s.size;
        if(size!=0)
        {
            ptr=new char[size+1];
            for(int i=0;i<size;i++)
            ptr[i]=s.ptr[i];
        }
        else
        {
            ptr=nullptr;
        }
        
   }
   int operator==(String s)
   {
      return (strcmp(ptr,s.ptr)==0);
   }
   int operator<(String s)
   {
      return (strcmp(ptr,s.ptr)==-1);
   }
   int operator>(String s)
   {
     return (strcmp(ptr,s.ptr)>1);
   }
   ~String()
   {
       delete ptr;
   }
};
int main()
{
   String s(10),s2,s3;
   const char *name="Rahul",*title="Pramanick";
   s2(name);
   s3(title);
   cout<<"comparison  of the string using the == relational operator"<<(s2==s3)<<"\n";
   cout<<"comparison  of the string using the < relational operator"<<(s2<s3)<<"\n";
   cout<<"comparison  of the string using the > relational operator"<<(s2>s3)<<"\n";
   s=s2;
   cout<<"The string s is "<<s<<"\n";
   return 0;


}