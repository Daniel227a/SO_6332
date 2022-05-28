#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
printf("\nAAAAAAAAAAAa\n");
 pid_t x;
 //pid_t y;
 x=fork();
 //y=fork();
 if(x!=0){
      printf("\nfilho X %d",x);
      //printf("\nfilho Y %d",y);
      printf("\npai X %d",getpid());

 }
 //if(y!=0){
   // printf("\nfilho Y %d",y);
     /// printf("\npai%d Y",getpid());


 //}



 return 0;

    
}