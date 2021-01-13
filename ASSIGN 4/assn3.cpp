#include<iostream>
using namespace std;
class ARRAY
{
   int *arr;
   int size;
   public:
   int* ret_array(){
       return arr;
   }
   ARRAY(int n=0,int value=0)
   {
       size=n;
       if(n==0)arr=nullptr;
       else 
       {
           arr=new int[size];
           for(int i=0;i<n;i++)
           arr[i]=0;
       }
   }
   ARRAY(const ARRAY &t)
   {
       size=t.size;
       if(size==0)arr=nullptr;
       else
       {
           arr=new int[size];
           for(int i=0;i<size;i++)
           arr[i]=t.arr[i];
       }
       
   }
   ARRAY(int p[],int s=0)
   {
        for(int i=0;i<s;i++)
        arr[i]=p[i];

   }
   void operator=(const ARRAY &t)
   {
       size=t.size;
       if(size==0)arr=nullptr;
       else
       {
           arr=new int[size];
           for(int i=0;i<size;i++)
           arr[i]=t.arr[i];
       }
   }
   void display(){
       for(int i=0;i<size;i++)
       cout<<arr[i]<<" ";
   }
   ~ARRAY()
   {
       if(arr)
       delete []arr;
       cout<<"des called\n";
   }
   friend ARRAY operator+(ARRAY &t,ARRAY &s);
   int operator[](int i){
       return arr[i];
   }
   friend ARRAY operator*(ARRAY&,int);
   friend ARRAY operator*(int,ARRAY&);
   
   
};
  ARRAY operator+(ARRAY &t,ARRAY &s)
  {
      ARRAY result(t.size);
      for(int i=0;i<t.size;i++)
      result.ret_array()[i]=(t.arr[i]+s.arr[i]);
      return result;
      
  }
  ARRAY operator*(ARRAY &t,int s)
  {
      ARRAY result(t.size);
      for(int i=0;i<t.size;i++)
      result.ret_array()[i]=t.arr[i]*5;
      return result;
  }
   ARRAY operator*(int s,ARRAY &t)
  {
      ARRAY result(t.size);
      for(int i=0;i<t.size;i++)
      result.ret_array()[i]=t.arr[i]*5;
      return result;
  }
int main()
{
      ARRAY a(10);
      ARRAY b;
      b=a;//assigning one array object to another
      ARRAY c(5),d(c);//
      d.display();
      cout<<"\n";
      ARRAY s(10);
      s=c+d;
      s.display();
      cout<<"\n";
      b.display();
      cout<<"\n";
      cout<<b[4];
      b=a*5;

      cout<<"Done here ";
      b.display();
       cout<<"Done here 2";
      b=5*a;
      b.display();
      int ar[10];
      for(int i=0;i<10;i++)
      ar[i]=2;
      ARRAY F(ar,10);
      F.display();
      return 0;
}