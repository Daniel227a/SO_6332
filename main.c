#include "CpuSchedulingAlgorithms.h"
#include"FCFS.h"
#include<string.h>
#include<time.h>
//#include"Lotery.h"
#include"RR.h"
#include"funçoes.h"
#include"SJF.h"
#include"SRT.h"
int Cont_process_completed(int process_cont,Process *process){
    int i;
    int temp_prrocess_completed=0;
    for(i=0;i<process_cont;i++){

        if(process[i].completed==1){

            
            temp_prrocess_completed++;
        }


    }
    //printf("%d",temp_prrocess_completed);
return temp_prrocess_completed;


}

void main(){


    int process_count = 0;

    int i = 0;


    Quantum quantum;

    Process *process;

    FILE *fp = fopen("process.txt", "r");


    if (fp == NULL) {
        printf("FILE OPEN ERROR! - Verificar Arquivo do Entrada\n");
       // return 0;
    }

    fscanf(fp, " %d", &process_count);

    process = (Process *) malloc(sizeof(Process) * process_count);


    while (i < process_count) {
        fscanf(fp, "%s %d %d %d",
               process[i].id, &process[i].arrive_time, &process[i].burst, &process[i].priority);

        i++;

    }

    fscanf(fp, " %d", &quantum);


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
   // ===============================================================
    // Lotery(process, process_count);
 //quantum=3;
//===========================
//RR(process,  process_count, quantum);

  
  /*
    i=0;
    int k;
    k=bruts_time_sort(process,i, process_count,temp);

   for (i=0;i<process_count;i++){
       k=bruts_time_sort(process,i, process_count,temp);
        
   }
  */  
//========================
 //SJF(process, process_count);
  SRT(process,process_count)  ;
 
}
