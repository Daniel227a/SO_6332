#include "CpuSchedulingAlgorithms.h"
#include"FCFS.h"
#include<string.h>
typedef struct Bilhete
{
    char id[255];
    int inicio;
    int fim;

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
    int vet_bilhete[cont_bilhetes];

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
    for (i=0;i<process_count;i++){
       printf("%s ",aloca_bilhete[i].id);
       printf("%d ",aloca_bilhete[i].inicio);
       printf("%d ",aloca_bilhete[i].fim);
        printf("\n");
    }

}

