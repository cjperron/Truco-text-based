#include "juego.h"
#include "truco.h"
#include "defines.h"
bool writeConfigFile(void){
    FILE* option_file = fopen(FILE_OPTION, "wb");
    if(option_file == NULL){
        fprintf(stderr, "%sError abriendo option file%s", KRED, KNRM);
        return false;
    }
    //Option* opciones = (Option *) malloc(sizeof(Option) * CANT_OPCIONES);
    char buffer[12+4];
    Option opciones[CANT_OPCIONES] = { //Esto en realidad seria correcto, ya que se hace 1 sola vez, y las opciones no cambian
        {.nombre = "Borrar Jugadores",          .id=0,  .comportamiento = removeJugadores},
        {.nombre = "Borrar todos los datos",    .id=1,  .comportamiento = removeAll},
        {.nombre = "Introducir codigo . . . .?",.id=2,  .comportamiento = ingresarCodigo}
    };
    fwrite(opciones, sizeof(Option), CANT_OPCIONES, option_file);
    if(fclose(option_file) == EOF){
        fprintf(stderr, "%sError cerrando option file%s", KRED, KNRM);
        //free(opciones);
        return false;
    }
    //free(opciones);
    return true;
}

Option *readConfigFile(void){
    FILE* option_file = fopen(FILE_OPTION, "rb");
    if(option_file == NULL){
        //fprintf(stderr, "%sError abriendo el option file%s\n", KRED, KNRM);
        if(fclose(option_file) == EOF){
            //fprintf(stderr, "%sError cerrando el option file%s\n", KRED, KNRM);
        }
        //espera();
        return NULL;
    }
    Option* opciones = (Option*) malloc(sizeof(Option) * CANT_OPCIONES);
    if(fread(opciones, sizeof(Option), CANT_OPCIONES, option_file) != CANT_OPCIONES){
        fprintf(stderr, "%sError en fread de config file%s\n", KRED, KNRM);
        if(fclose(option_file) == EOF){
            fprintf(stderr, "%sError cerrando el option file%s\n", KRED, KNRM);
        }
        free(opciones);
        return NULL;
    }
    return opciones;
}
void printOptions(Option* opciones){
    for(int i=0;i<CANT_OPCIONES;i++){
        printf("%s%d. %s%s\n",KWHT, i+1,opciones[i].nombre, KNRM);
    }
}
void doOptionN(Option* opciones, int n){
    for(int i=0;i<CANT_OPCIONES;i++){
        if(opciones[i].id == n){
            opciones[i].comportamiento();
            return;
        }
    }
}
int removeJugadores(void){
    if(remove(FILE_JUGADORES) != 0){
        fprintf(stderr, "%sError removiendo el archivo de jugadores%s\n", KRED, KNRM);
        return 1;
    }
    if(remove(FILE_TOTAL) != 0){
        fprintf(stderr, "%sError removiendo el archivo de total de jugadores%s\n", KRED, KNRM);
        return 2;
    };
    return 0;
}
int removeAll(void){
    if(remove(FILE_JUGADORES) != 0){
        fprintf(stderr, "%sError removiendo el archivo de jugadores%s\n", KRED, KNRM);
        return 1;
    }
    if(remove(FILE_TOTAL) != 0){
        fprintf(stderr, "%sError removiendo el archivo de total de jugadores%s\n", KRED, KNRM);
        return 2;
    };
    if(remove(FILE_MAZO) != 0){
        fprintf(stderr, "%sError removiendo el archivo de mazo%s\n", KRED, KNRM);
        return 3;
    };
    if(remove(FILE_PJ_SEL) != 0){
        fprintf(stderr, "%sError removiendo el archivo depj seleccionado %s\n", KRED, KNRM);
        return 4;
    };
    if(remove(FILE_LOG) != 0){
        fprintf(stderr, "%sError removiendo el archivo de log%s\n", KRED, KNRM);
        return 5;
    };
    return 0;
}
int ingresarCodigo(void){
    char buffer[20];
    system("clear");
    printf("%sIngrese codigo: %s", KYEL, KNRM);
    scanf("%20s", buffer);
    myflush(stdin);
    /* 
    Lo correcto seria leer de pj seleccionados asi obtengo el jugador seleccionado.
    Hago que el codigo ingresado se compare con los codigos disponibles en un archivo de codigos.
    Si todo es correcto, le agrego el item al pj seleccionado.
    Ahora tendria que copiar eso en jugadores.truco .... 
    |--> ideal tener una funcion que copie algo (void*) a un Jugador*
    */
    return 0;
}