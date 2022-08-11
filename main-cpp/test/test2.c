#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define semilla() srand(time(NULL))
bool cpyRandomName(char* container/*,  Provincia origen */){
    FILE* nameFile;
    nameFile = fopen("../demo/nombres/nombresBSAS.txt", "rt");
    if(nameFile == NULL){
        fprintf(stderr, "Error leyendo el archivo de nombres.\n");
        return false;
    } 
    //Ahora tengo que leer la cant de lineas del archivo
    char chr = fgetc(nameFile);
    int cantLineas = 0;
    while(chr != EOF){
        if(chr=='\n') cantLineas++;
        chr = fgetc(nameFile);
    }
    rewind(nameFile);
    //Tengo la cant total de lineas.
    semilla();
    int linea_random = rand() % cantLineas; // rango de [0 , cantLineas]
    char linea[32];
    cantLineas = 0;
    while(fgets(linea, sizeof(linea), nameFile) != NULL){
        if(cantLineas == linea_random){
            linea[strlen(linea)-1] = '\0';
            strcpy(container, linea);
            if(fclose(nameFile) == EOF){
                fprintf(stderr, "Error cerrando el archivo de nombres.\n");
            }
            return true;
        }
        else cantLineas++;
    }
    return false;
}
int main(){
    char container[21];
    cpyRandomName(container);
    printf("Container: %s\n", container);
    return 0;
}