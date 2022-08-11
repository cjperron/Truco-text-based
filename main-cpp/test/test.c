#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void writeFile(const char* fileName, int cantidad_de_numeros);
int* readFile(const char* fileName, int cantidad_de_numeros);
int main(){
    int cant;
    printf("Ingrese cantidad de numeros a guardar en el bin: ");
    scanf("%d", &cant);
    writeFile("test.bin", cant);
    int* numeros = readFile("test.bin", cant);
    for(int i=0;i<cant;i++)
        printf("numeros[%d] = %d\n", i,numeros[i]);
    return 0;
}
int* readFile(const char* fileName, int cantidad_de_numeros){
    FILE* file = fopen(fileName, "rb");
    int* numeros = (int*) malloc(sizeof(int)*cantidad_de_numeros);
    fread(numeros, sizeof(int), cantidad_de_numeros, file);
    fclose(file);
    return numeros;
}
void writeFile(const char* fileName, int cantidad_de_numeros){
    FILE* file = fopen(fileName, "wb");
    int* numeros = (int*) malloc(sizeof(int) * cantidad_de_numeros);
    for(int i = 0; i < cantidad_de_numeros;i++){
        numeros[i] = cantidad_de_numeros - i;
    }
    fwrite(numeros, sizeof(int), cantidad_de_numeros, file);
    fclose(file);
    free(numeros);
    return;
}