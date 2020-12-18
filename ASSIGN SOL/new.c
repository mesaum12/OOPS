#include<stdio.h>
int f(int x)
{
    if(x<2)return x;
    else
    {
        return f(x-1)+f(x-2);
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}