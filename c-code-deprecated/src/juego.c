#include"truco.h"
#include"juego.h"
void generarPartido(Jugador* jugador, Jugador* oponente, Carta* mazo, Partido* partido){
    partido->mazo = mazo;
    partido->Player1 = jugador;
    partido->Oponente = oponente;
    FILE* log_file = fopen(FILE_LOG, "at");
    char time_string[12];
    time_t ahora = time(&ahora);
    struct tm *now = localtime(&ahora);
    strftime(time_string, 12, "%H:%M:%S", now);
    fprintf(log_file, "----------------\n[%s]\n----------------\n", time_string);
    fprintf(log_file,"Partido Generado: \n%s VS %s\n----------------\n");
    if(fclose(log_file) == EOF){
        fprintf(stderr, "%sError cerrando el archivo de log.%s\n",KRED,KNRM);
        return;
    }
    return;
}
bool cpyRandomName(char* container){
    FILE* nameFile;
    nameFile = fopen("./nombres/nombresBSAS", "rt");
    if(nameFile == NULL){
        fprintf(stderr, "%sError leyendo el archivo de nombres.%s\n",KRED,KNRM);
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
    char linea[31];
    cantLineas = 0;
    while(fgets(linea, sizeof(linea), nameFile) != NULL){
        if(cantLineas == linea_random){
            linea[strlen(linea)-1] = '\0';
            strcpy(container, linea);
            if(fclose(nameFile) == EOF){
                fprintf(stderr, "%sError cerrando el archivo de nombres.%s\n",KRED,KNRM);
            }
            return true;
        }
        else cantLineas++;
    }
    return false;
}
