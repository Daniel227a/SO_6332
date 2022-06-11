#include<stdio.h>
#include<stdlib.h>
#include"Process.h"
void lerTxt();

void lerTxt(){
    FILE *fp = fopen("process.txt", "r");
    char c;
    do
    {
    //faz a leitura do caracter no arquivo apontado por pont_arq
    c = fgetc(fp);
    
    //exibe o caracter lido na tela
    printf("%c" , c);    
    
    }while (c != EOF);

}

void arrive_time_sort(Process *process,int i, int process_count){

    int cont=0;
    int i,j;
    Process temp_process;
    temp=(Process *) malloc(sizeof(Process) * process_count);
    for(j=i+1;j<process_cont;j++){
        if((process[i].burst+process[i].arrive_time)>process[j].arrive_time){

            temp[cont]=process[j].arrive_time;
            cont++;
        }

    }
    for(i=0;i<cont-1;i++){
        for(j=i+1;j<cont;j++){
            if(process[i]>process[j]){
                temp_process=temp[i];
                temp[i]=temp[j];
                temp[j]=temp_process;

            }
          
        }


    }




}
