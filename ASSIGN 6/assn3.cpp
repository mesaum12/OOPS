#include<iostream>
using namespace std;
template<class X>
class Array
{
   X *arr;
   int size;
   public:
   Array(int n=0){
       size=n;
       arr=new X[size];
   }
   void set_elements()
   {
       for(int i=0;i<size;i++)
       {
           cout<<"Enter the element:";
           cin>>arr[i];
       }

   }
   X ret_sum()
   {
       X sum=0;
       for(int i=0;i<size;i++)
       {
         sum+=arr[i];
       }
       return sum;
   }
   X ret_max()
   {
       X max=arr[0];
       for(int i=1;i<size;i++)
       {
           if(arr[i]>max)
           max=arr[i];
       }
       return max;
   }
};
int main()
{
   Array<int>a_int(5);
   a_int.set_elements();
    cout<<"The max elements of the integer array is :"<<a_int.ret_max()<<"\n";
    cout<<"The sum  of the integer array elements is :"<<a_int.ret_sum()<<"\n";
  
   cout<<"\n";
   Array<float>a_float(5);
   a_float.set_elements();
   cout<<"The max elements of the float array is :"<<a_float.ret_max()<<"\n";
   cout<<"The sum  of the float array elements is :"<<a_float.ret_sum()<<"\n";
   
   cout<<"\n";
   Array<double>a_double(5);
   a_double.set_elements();
   cout<<"The max elements of the double array is :"<<a_double.ret_max()<<"\n";
   cout<<"The sum  of the float double elements is :"<<a_double.ret_sum()<<"\n";

   cout<<"\n";
   Array<char>a_char(5);
   a_char.set_elements();
   cout<<"The max elements of the double array is :"<<a_char.ret_max()<<"\n";
   
   return 0;
}