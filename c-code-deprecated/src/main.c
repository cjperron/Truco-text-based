#include "truco.h"
#include "juego.h"
int main(int argc, char* argv[])
{
    writeConfigFile();
    char *buffer = NULL;
    Carta *mazo = NULL;
    Jugador *pj_seleccionado = NULL; //Si es null va a saltar que lo tiene que elejir.
    Option* opciones = readConfigFile();
    if(opciones==NULL){
        fprintf(stderr, "%sError en las funciones de config.%s\n", KRED, KNRM);
        return 1;
    } 
    mazo = leerMazo(); // Lee de "mazo.truco"
    if (mazo == NULL)
        mazo = crearMazo(); // Lo crea en "mazo.truco"
    buffer = (char *)malloc(sizeof(char) * 30);
    do
    {
        system("clear");
        pj_seleccionado = devolver_pj_seleccionado();
        printf("\t%sT  R  U  C  O\t\t%sUnix Version%s\n1. Jugar\n2. Opciones\n3. Salir\n\n%s>>",KGRN,KCYN,KBLU,KNRM);
        scanf("%30s", buffer);
        myflush(stdin);
        switch (buffer[0])
        {
        case '1':
            menuDeJuego(mazo, pj_seleccionado);
            break;
        case '2':
            do{
            system("clear");
            printf("%s0. Volver%s\n", KWHT, KNRM);
            printOptions(opciones);
            printf("\nIngrese opcion: ");
            scanf("%30s", buffer);
            myflush(stdin);
            switch(buffer[0]){
                case '0':
                    break;
                case '1':
                    if(opciones[0].comportamiento() != 0){
                        fprintf(stderr, "%sError de opcion 1.%s\n", KRED, KNRM);
                        mypause();
                    }
                    break;
                case '2':
                    if(opciones[1].comportamiento() != 0){
                        fprintf(stderr, "%sError de opcion 2.%s\n", KRED, KNRM);
                        mypause();
                    }
                    break;
                case '3':
                    if(opciones[2].comportamiento() != 0){
                        fprintf(stderr, "%sError de opcion 3.%s\n", KRED, KNRM);
                        mypause();
                    }
                    break;
                default:
                    printf("Error: No reconocido\n");
                    break;
            }
            } while(buffer[0] != '0');
            strcpy(buffer, "");
            break;
        case '3':
            system("clear");
            break;
        default:
            printf("\nError: No reconocido");
            sleep(1);
        }
    } while (buffer[0] != '3');
    free(buffer);
    free(mazo);
    return 0;
}

void myflush(FILE *in)
{
    int ch;
    do
        ch = fgetc(in);
    while (ch != EOF && ch != '\n');
    clearerr(in);
}
void mypause(void)
{
    printf("Press [Enter] to continue . . .");
    fflush(stdout);
    getchar();
}