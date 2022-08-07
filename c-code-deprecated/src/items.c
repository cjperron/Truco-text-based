#include"defines.h"
#include"truco.h"
#include"juego.h"
int addItemToPj(char* playerName, Item item){
    Jugador* jugador = getPlayerByName(playerName);
    int cantActualItems = devolver_cant_items(playerName);
    if(cantActualItems < 0)
    {
        fprintf(stderr, "%sError leyendo la cantidad de items.%s\n", KRED, KNRM);
        free(jugador);
        return -1;
    }
    if(jugador->inventario == NULL) jugador->inventario = (Item*) malloc (sizeof(Item) * cantActualItems + 1); //Ya que no fue inicializado, la cantidad de items que va a tener ahora es 1
    else jugador->inventario = (Item*) realloc (jugador->inventario, cantActualItems + 1); //porque le estoy apunto de agregar el item
    jugador->inventario[cantActualItems+1] = item; 
    escribir_cant_items( jugador->nombre , cantActualItems+1 );
    free(jugador);
    return 0;
}
int escribir_cant_items(char* playerName, int nItems){
    Jugador *player = getPlayerByName(playerName); //Tengo el jugador con el nombre alocado dinamicamente
    if(player == NULL) return 1;
    char buffer[61];
    strcpy(buffer, RUTA_PLAYERS);
    strcat(buffer, player->nombre);
    strcat(buffer, "itemcant.pj");
    FILE* playerFile = fopen(buffer, "wb");
    fwrite(&nItems, sizeof(int), 1, playerFile);
    if(fclose(playerFile) == EOF){
        fprintf(stderr, "%sError cerrando '%s'.%s\n", KRED, buffer, KNRM);
        free(player);
        return 2;
    }
    free(player);
    return 0;
}
int devolver_cant_items(char* playerName){
    Jugador *player = getPlayerByName(playerName); //Tengo el jugador con el nombre alocado dinamicamente
    if(player == NULL) return -1;
    char buffer[61];
    int cant_items;
    strcpy(buffer, RUTA_PLAYERS);
    strcat(buffer, player->nombre);
    strcat(buffer, "itemcant.pj");
    FILE* playerFile = fopen(buffer, "rb");
    if(playerFile == NULL){
        fprintf(stderr, "%sError abriendo '%s'.%s\n", KRED, buffer, KNRM);
        fclose(playerFile);
        free(player);
        return -2;
    }
    if(fread(&cant_items, sizeof(int),1, playerFile) != 1){
        fprintf(stderr, "%sError leyendo de '%s'.%s\n", KRED, buffer, KNRM);
        free(player)
        fclose(playerFile);
        return -3;
    }
    if(fclose(playerFile) == EOF){
        fprintf(stderr, "%sError cerrando '%s'.%s\n", KRED, buffer, KNRM);
        free(player);
        return -4;
    }
    return cant_items;
}
Jugador* getPlayerByName(char* playerName){
    FILE* archivo_jugadores = fopen(FILE_JUGADORES, "rb");
    if(archivo_jugadores == NULL){
        fprintf(stderr, "%sError al abrir el archivo de jugadores%s", KRED, KNRM);
        return NULL;
    }
    Jugador* player = (Jugador*) malloc(sizeof(Jugador));
    while(fread(player, sizeof(Jugador), 1, archivo_jugadores) == 1){ //leo jugador por jugador
        if(strcmp(playerName, player->nombre) == 0){
            if(fclose(archivo_jugadores) == EOF){
                fprintf(stderr, "%sError cerrando el archivo de jugadores%s\n", KRED, KNRM);
                free(player);
                espera();
                return NULL;
            }
            return player;
        }
    }
    //no se encontro el jugador.
    fprint(stderr, "%sNo se encontro jugador%s\n", KRED, KNRM);
    free(player);
    return NULL;
}