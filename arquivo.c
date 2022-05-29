#include<stdlib.h>
#include<stdio.h>
#define ID_LEN 20
#define TRUE 1
#define FALSE 0
typedef int Quantum;
typedef struct _process
{
    char id[ID_LEN];
    int arrive_time;//hora de chegada
    int waiting_time;//tempo de espera
    int return_time;
    int turnaround_time;
    int response_time;//tempo de resposta
    int burst;
    int priority;
    int completed;
} Process;
void main(){

     int process_count = 0;

    int i = 0;


    Quantum quantum;

    Process *process;

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