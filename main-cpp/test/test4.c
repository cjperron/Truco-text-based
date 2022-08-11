#include<stdio.h>
#include<stdlib.h>
void hacerAlgo(){
    printf("Hola bobo\n");
}
int retornarAlgo(){
    printf("Retorno algo\n");
    return 5;
}
int main(){
    void (*a)() = hacerAlgo;
    printf("LOL\n");
    a();
    int (*b)() = retornarAlgo;
    if(b() == 5){
        printf("Retorne 5\n");
    }
    else{
        printf("Rompi todo.\n");
    }
    return 0;
}