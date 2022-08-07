#include "truco.h"
#include"juego.h"
void menuDeJuego(Carta *mazo, Jugador* pj_seleccionado)
{
    char *buffer = (char *) malloc(sizeof(char) * 30);
    Jugador* lista_de_jugadores = leerPersonajes();
    if(lista_de_jugadores == NULL){
        printf("%sSe detecto que no hay personaje creado . . .%s\n",KRED,KNRM);
        crearPersonaje();
        lista_de_jugadores = leerPersonajes();
    }
    do
    {
        system("clear");
        printf("%s1. Partido vs IA%s\n2. Torneo 'San Bonifacio'\n%s3. Personaje\n%s4. Salir%s\n\n",KGRN,KYEL,KCYN,KRED,KNRM);
        if(pj_seleccionado != NULL){
            printf("%sPersonaje seleccionado: %s%s%s\n",KWHT,KMAG, pj_seleccionado->nombre,KNRM);
        }
        else printf("%sSeleccione personaje. . .%s\n",KRED,KNRM);
        do{
            printf(">>");
            scanf("%30s", buffer);
            myflush(stdin);
        } while(isdigit(buffer[0]) == 0);
        switch (buffer[0])
        {
        case '1':
            // Faltaria desarrollar la IA y el Partido en si.

            break;
        case '2':
            // Esto es un quilombo
            break;
        case '3':
            // Hay que leer los datos de un Jugador Creado.
            char* respuesta = (char*) malloc (sizeof(char) * 10);
            do{
            system("clear");
            printf("%sP E R S O N A J E%s\n1. Crear personaje%s\n2. Elejir personaje%s\n3. Salir%s\n\n",KCYN,KYEL,KGRN,KRED,KNRM);
            do{
            printf(">>");
            scanf("%10s", respuesta); //pinto que sea 10.
            myflush(stdin);
            fflush(stdin);
            } while(isdigit(respuesta[0]) == 0);
            switch(respuesta[0]){
                case '1':
                    crearPersonaje();
                    break;
                case '2':
                    pj_seleccionado = seleccionar_pj(lista_de_jugadores);
                    
                    break;
                case '3':
                    break;
                default:
                    break;
            }
            } while (respuesta[0] != '3');
            free(respuesta);
            break;
        case '4':
            break;
        default:
            fprintf(stderr,"%sError: No reconocido%s\n",KRED,KNRM);
            break;
        }
    } while (buffer[0] != '4');
    free(buffer);
    return;
}