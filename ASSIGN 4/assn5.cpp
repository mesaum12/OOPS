#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char *ptr;
    int size;
    int *pc;
    public:
    String(char *s='\0',int n=0)
    {
        size=n;
        if(n==0)
        ptr=nullptr;
        else 
        {
            ptr=new char[size+1];
            pc=new int;
            *pc=1;
            strcpy(ptr,s);
        }
    }
    String(const String &s)
    {
        ptr=s.ptr;
        size=s.size;
        pc=s.pc;
        (*pc)++;
    }
    void operator=(const String &s)
    {
         ptr=s.ptr;
        size=s.size;
        pc=s.pc;
        (*pc)++;
    }
    ~String()
    {
        (*pc)--;
        cout<<"Destructor called for time: "<<*pc<<"\n";
        if(*pc==0)
        {
            if(ptr)
            delete []ptr;
            delete pc;
            cout<<"Finally the memory is released this time\n";
        }
    }
};
int main()
{
  char name[]="saurabh";
  String s(name,strlen(name));
  String s2(s);
  String s3;
  s3=s;
  return 0;
}