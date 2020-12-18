#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
   char name[31];
   int roll;
   int score;
}student;
int main()
{
   
   int n,i;
   printf("Enter the number of students\n");
   scanf("%d",&n);
   student *s;
   s=(student*)malloc(n*sizeof(student));
   if(s)
   {
      FILE *ptr=fopen("student.txt","rb+");
      for(i=0;i<n;i++)
      {
          student t;
         printf("Name:");
         scanf("%s",(s+i)->name);
         printf("Roll:");
         scanf("%d",&((s+i)->roll));
         scanf("%d",&((s+i)->score));
         fwrite(&t,sizeof(student),1,ptr);
      }
     //FILE *ptr2=fopen("student.txt","rb");
       for(i=0;i<n;i++)
      {
          student t;
          
          if(ptr)
          while(fread(&t,sizeof(student),1,ptr)>0)
          {
              printf("%s %d %d\n",t.name,t.roll,t.score);
          }
      }
      //fclose(ptr2);
      fclose(ptr);
   }
   return 0;
}