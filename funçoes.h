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

int lista_process(){





}