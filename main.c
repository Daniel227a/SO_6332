#include "CpuSchedulingAlgorithms.h"
#include"FCFS.h"
#include<string.h>
#include<time.h>
typedef struct Bilhete
{
    char id[255];
    int inicio;
    int fim;
    int completa;


    /* data */
}bilhete;


void main(){


    int process_count = 0;

    int i = 0;
    int j;


    Quantum quantum;

    Process *process;
    Process *temp;
    FILE *fp = fopen("process.txt", "r");


    if (fp == NULL) {
        printf("FILE OPEN ERROR! - Verificar Arquivo do Entrada\n");
       exit(1);
    }

    fscanf(fp, " %d", &process_count);

    process = (Process *) malloc(sizeof(Process) * process_count);
    temp=(Process *) malloc(sizeof(Process) * process_count);
    while (i < process_count) {
        fscanf(fp, "%s %d %d %d",
               process[i].id, &process[i].arrive_time, &process[i].burst, &process[i].priority);

        i++;
    }
    i=0;
    process_init(process,process_count);
    /*  

    for (i=0;i<process_count;i++){

        printf(" id %s",process[i].id);
        printf(" tempo de espera (waiting_time): %d",process[i].arrive_time);
        printf(" é o tempo total gasto pelo processo para sua execução na CPU (brust): %d",process[i].burst);
        printf(" priridade : %d",process[i].priority);
        printf("\n");

    }
    */

   //FCFS FEITO
   //===================================================================//
   /*
    FCFS(process , process_count);
    
    for(i=0;i<process_count;i++){

        printf(" id %s",process[i].id);
        printf(" tempo de espera (waiting_time): %d",process[i].arrive_time);
        printf(" (brust): %d",process[i].burst);
        printf(" priridade : %d",process[i].priority);
        printf(" return time : %d",process[i].return_time);
        printf(" turnoroud %d",process[i].return_time);
        printf("\n");

    }
    fcfs_print_gantt_chart(process ,process_count);
     print_table(process, process_count);

     =============================================================

     */
    int cont_bilhetes=0;
    bilhete *aloca_bilhete;
    aloca_bilhete=(bilhete *) malloc(sizeof(bilhete) * process_count);

    for(i =0;i<process_count;i++){

        cont_bilhetes+=process[i].priority;

    }
    bilhete vet_bilhete[cont_bilhetes];

    for (int i = 0; i < process_count; i++)
    {
        
        if(i!=0){
            
            strcpy(aloca_bilhete[i].id,process[i].id);
            aloca_bilhete[i].inicio=aloca_bilhete[i-1].fim;
            aloca_bilhete[i].fim=process[i].priority+aloca_bilhete[i].inicio;

        }else{

            strcpy(aloca_bilhete[i].id,process[i].id);
            aloca_bilhete[i].inicio=0;
            aloca_bilhete[i].fim=process[i].priority;
        }   

    }
    for(int i =0;i<process_count;i++){
        for (int y= aloca_bilhete[i].inicio;y<=aloca_bilhete[i].fim;y++){

             strcpy(vet_bilhete[y].id,aloca_bilhete[i].id);
        }
    }
    
    for(i =0;i<cont_bilhetes;i++){

        vet_bilhete[i].completa=0;
        printf("%s   ",vet_bilhete[i].id);

    }
     int premiado=0;
    int cont_process_completed=0;

  srand((unsigned)time(NULL));
            srand(time(NULL));
  
      for (int i = 0; i <process_count; i++)
    {    
            srand((unsigned)time(NULL));
            srand(time(NULL));
            premiado=(rand()%cont_bilhetes);
       if(process[i].completed!=1 && (strcmp(vet_bilhete[premiado].id,process[i].id))){
           srand((unsigned)time(NULL));
            srand(time(NULL));
           cont_process_completed+=1;
           process[i].completed=1;
           //printf("\n%d",premiado);
           printf("\n o processo %s",process[i].id);
           printf("\n");

       }
       
         if(cont_process_completed ==process_count-1){
           cont_process_completed+=1;

           for (j=0;j<process_count;j++){

               if( process[j].completed!=1){
                     process[j].completed=1;
                      printf("\n o processo %s",process[j].id);

               }

                
           }
          
            break;
       }else if(cont_process_completed!=6 && i== process_count-1){
           i=0;
           srand((unsigned)time(NULL));
            srand(time(NULL));
       }
  

     }



/*
  
   for (int i = 0; i <process_count; i++)
   {
        srand((unsigned)time(NULL));
        srand(time(NULL));
       premiado=(rand()%cont_bilhetes);
       if(process[i].completed!=1 && (strcmp(vet_bilhete[premiado].id,process[i].id))){

           cont_process_completed+=1;
           process[i].completed=1;
           printf("%s ",process[i].id);

       }else if(process[i].completed!=0){
           i--;
       }

  

   }
   
*/


for (int i=0;i<process_count;i++){


    printf("\n o processo %s  esta %d ",process[i].id ,process[i].completed);
}
//printf("\n%d",process_count);

/*   
    int premiado=0;
  
   srand((unsigned)time(NULL));
    srand(time(NULL));
 // premiado=(rand()%cont_bilhetes);
    
    for(i=0;i<process_count;i++){
      premiado=(rand()%cont_bilhetes);
       
       
        

            if(vet_bilhete[premiado] && aloca_bilhete[i].completa!=1){

                process[i].completed=TRUE;
                aloca_bilhete[i].completa=1;
               premiado=(rand()%cont_bilhetes);
                printf("%s\n",process[i].id);
                printf("\n%d premio",premiado);
                break;
            }else if(aloca_bilhete[i].completa==1){
              i--;
            // premiado=(rand()%cont_bilhetes);
            }


            


    }


    for (i=0;i<process_count;i++){
       printf("%s ",aloca_bilhete[i].id);
       printf("%d ",aloca_bilhete[i].inicio);
       printf("%d ",aloca_bilhete[i].fim);
        printf("\n");
    }

*/

}

