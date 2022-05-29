#include<stdlib.h>
#include<stdio.h>
#define ID_LEN 20
#define TRUE 1
#define FALSE 0


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
typedef int Quantum;
void process_init(Process p[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        p[i].waiting_time = 0;
        p[i].return_time = 0;
        p[i].response_time = 0;
        p[i].completed = FALSE;
    }
}

void main(){
    Process *process;

    process = (Process *) malloc(sizeof(Process) * 5);
    process_init( process , 5);
    int i=0;
    for(i=0;i<5;i++){
        printf("\n %d",process[i].completed);

    }


}