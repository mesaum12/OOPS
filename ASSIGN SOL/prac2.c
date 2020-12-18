#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
   char name[31];int roll;
}student;
int main()
{
    
   FILE *ptr=fopen("name.txt","wb+"),*ptr2;
   if(ptr)
   {
       student s;
       int n,i;
       printf("Enter the number of students\n");
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
           printf("Name:");
           scanf("%s",s.name);
           printf("Roll:");
           scanf("%d",&(s.roll));
           fwrite(&s,sizeof(student),1,ptr);
       }
       ptr2=fopen("name.txt","rb");
       while(fread(&s,sizeof(student),1,ptr2))
       {
            printf("%s %d\n",s.name,s.roll);
       }
       fclose(ptr2);
       fclose(ptr);
   }
   return 0;
}