#include "truco.h"
#include "juego.h"
void mostrarPersonajes()
{
    FILE *file_pj = fopen(FILE_JUGADORES, "rb");
    if (file_pj == NULL)
    {
        fprintf(stderr, "%sError: archivo no existe.%s\n", KRED, KNRM);
        espera();
        return;
    }
    int total = devolver_total_jugadores();
    Jugador *jugadores = leerPersonajes();
    if (total == -1)
    {
        printf("%sError leyendo total.%s\n", KRED, KNRM);
        return;
    }
    for (int i = 0; i < total; i++)
    {
        printf("[id: %s%d%s]\nNombre: %s%s%s\n", KCYN, (jugadores + i)->id, KNRM, KMAG, (jugadores + i)->nombre, KNRM);
        printf("Descripcion: %s\n", (jugadores + i)->descripcion);
        printf("Sexo: ");
        if ((jugadores + i)->sexo == Masculino)
            printf("Hombre\n");
        else
            printf("Mujer\n");
    }
}
// Vulnerabilidad conocida: Si se llama lo suficiente se come la RAM. JAJAJJJJAJS, aunque si reinicias se soluciona.
Jugador *leerPersonajes(void)
{
    FILE *jugadores = fopen(FILE_JUGADORES, "rb");
    if (jugadores == NULL)
    {
        // printf("Error: No se pudo abrir el archivo de jugadores.\n");
        // espera();
        return NULL;
    }
    // El total de jugadores creados esta al inicio.
    int total = devolver_total_jugadores();
    if (total == -1)
    {
        printf("Error leyendo el total.\n");
        espera();
        return NULL;
    }
    Jugador *pj_creados = (Jugador *)malloc(sizeof(Jugador) * total);
    if (fread(pj_creados, sizeof(Jugador), total, jugadores) != total)
    {
        printf("Error en fread.\n");
        espera();
        free(pj_creados);
        return NULL;
    }
    // Tengo el struct de jugadores creados.
    if (fclose(jugadores) == EOF)
    {
        printf("Error en fclose.\n");
        espera();
        free(pj_creados);
        return NULL;
    }
    return pj_creados;
}

// Funcion que crea un personaje luego del ultimo creado.
void crearPersonaje(void)
{
    char buffer[30];
    Jugador jugador = {
        .estadisticas.agresividad.estado = MuyBajo,
        .estadisticas.agresividad.nombre = "Agresividad",
        .estadisticas.agresividad.xp_interna = 0,
        .estadisticas.mentiroso.estado = MuyBajo,
        .estadisticas.mentiroso.nombre = "Mentiroso",
        .estadisticas.mentiroso.xp_interna = 0,
        .estadisticas.pescador.estado = MuyBajo,
        .estadisticas.pescador.nombre = "Mentiroso",
        .estadisticas.pescador.xp_interna = 0,
        .estadisticas.tramposo.estado = MuyBajo,
        .estadisticas.tramposo.nombre = "Tramposo",
        .estadisticas.tramposo.xp_interna = 0,
        .estadisticas.dinero = 0.0,
        .estadisticas.xp = 0,
        .inventario = NULL,
    };
    FILE *jugadores = fopen(FILE_JUGADORES, "ab");
    if (jugadores == NULL)
    {
        printf("%sError al abrir el archivo de jugadores.%s\n", KRED, KNRM);
        espera();
        return;
    }
    // Se pudo abrir el archivo
    int total_jugadores = devolver_total_jugadores();
    printf("Nombre del personaje: ");
    scanf("%[^\n]s", jugador.nombre);
    myflush(stdin);
    printf("Descripcion del personaje: ");
    scanf("%[^\n]s", jugador.descripcion);
    fflush(stdin);
    myflush(stdin);
    do
    {
        printf("Sexo del personaje (m/f): ");
        scanf("%30s", buffer);
        myflush(stdin);
    } while (tolower(buffer[0]) != 'm' && tolower(buffer[0]) != 'f');
    if (tolower(buffer[0]) == 'm')
        jugador.sexo = Masculino;
    else if (tolower(buffer[0]) == 'f')
        jugador.sexo = Femenino;
    jugador.id = total_jugadores;
    fwrite(&jugador, sizeof(Jugador), 1, jugadores);

    write_total_jugadores(++total_jugadores);

    if (fclose(jugadores) == EOF)
    {
        printf("%sError cerrando el archivo de jugadores.%s\n", KRED, KNRM);
        espera();
        return;
    }
    //Ahora tengo que escribir los datos del jugador en un archivo en /players
    writeSeparatePlayerFile(&jugador)
    //Luego de esto vienen todos los seteos de las estadisticas?
    escribir_cant_items(jugador.nombre, 0);
    printf("Personaje creado.\n");
    mypause();
    return;
}
// Genera un jugador en especifico a partir de la lista completa de jugadores.
Jugador *seleccionar_pj(Jugador *lista_de_jugadores)
{
    int sel;
    if (lista_de_jugadores == NULL)
    {
        printf("\nError lista_de_jugadores es NULL.\n");
        espera();
        return NULL;
    }
    mostrarPersonajes();
    printf("Ingrese el personaje a elejir [id]: ");
    scanf("%d", &sel);
    return devolver_pj(lista_de_jugadores, sel);
}
Jugador *devolver_pj(Jugador *lista_de_jugadores, int id)
{
    FILE *archivo_jugadores = fopen(FILE_JUGADORES, "rb+");
    if (archivo_jugadores == NULL)
    {
        fprintf(stderr, "%sError leyendo el archivo de jugadores.%s\n", KRED, KNRM);
        espera();
        return NULL;
    }
    int total_jugadores = devolver_total_jugadores();
    Jugador *jugadores_disponibles = leerPersonajes();
    for (int i = 0; i < total_jugadores; i++)
    {
        if ((jugadores_disponibles + i)->id == id)
        {
            FILE *archivo_seleccionado = fopen(FILE_PJ_SEL, "wb");
            if (archivo_seleccionado == NULL)
            {
                fprintf(stderr, "%sError abriendo el archivo de personajes seleccionados.%s\n", KRED, KNRM);
                return NULL;
            }
            //Jugador temp = *(jugadores_disponibles + i);
            fwrite(jugadores_disponibles+i, sizeof(Jugador), 1, archivo_seleccionado);
            if(fclose(archivo_seleccionado) == EOF){
                fprintf(stderr, "%sError cerrando el archivo de pj seleccionado%s", KRED, KNRM);
                return NULL;
            }
            if(fclose(archivo_jugadores) == EOF){
                fprintf(stderr, "%sError cerrando el archivo de jugadores%s", KRED, KNRM);
                return NULL;
            }
            return jugadores_disponibles + i;
        }
    }
    printf("%sJugador no existe.%s\n", KRED, KNRM);
    free(jugadores_disponibles);
    espera();
    return NULL;
}
int devolver_total_jugadores(void)
{
    FILE *archivo_total = fopen(FILE_TOTAL, "rb");
    if (archivo_total == NULL)
    { // El archivo no existe
        archivo_total = fopen(FILE_TOTAL, "wb");
        if (archivo_total == NULL)
        {
            printf("Ocurrio un error al abrir temporalmente el sensitive.dat\n");
            espera();
            return -1;
        }
        int temp = 0;
        fwrite(&temp, sizeof(int), 1, archivo_total);
        if (fclose(archivo_total) == EOF)
        {
            printf("Ocurrio un error al cerrar el sensitive.dat\n");
            espera();
            return -1;
        }
    }
    archivo_total = fopen(FILE_TOTAL, "rb");
    if (archivo_total == NULL)
    {
        printf("Error al abrir el sensitive.dat\n");
        espera();
        return -1;
    }
    int total;
    if (fread(&total, sizeof(int), 1, archivo_total) != 1)
    {
        printf("Ocurrio un error al leer el sensitive.dat\n");
        espera();
        return -1;
    }
    if (fclose(archivo_total) == EOF)
    {
        printf("Error cerrando el archivo.\n");
        espera();
        return -1;
    }
    return total;
}
Jugador *devolver_pj_seleccionado(void)
{
    FILE *archivo_pj_seleccionados = fopen(FILE_PJ_SEL, "rb");
    if (archivo_pj_seleccionados == NULL)
    {
        //printf("No existe archivo de pj seleccionado.\n");
        return NULL;
    }
    Jugador *personaje = (Jugador *)malloc(sizeof(Jugador));
    if (fread(personaje, sizeof(Jugador), 1, archivo_pj_seleccionados) != 1)
    {
        //printf("NO HAY PERSONAJE SELECCIONADO\n");
        if (fclose(archivo_pj_seleccionados) == EOF)
        {
            fprintf(stderr, "%sError cerrando el archivo de personaje seleccionado.%s\n", KRED, KNRM);
            exit(1);
        }
        return NULL;
    }
    if (fclose(archivo_pj_seleccionados) == EOF)
    {
        fprintf(stderr, "%sError cerrando el archivo de personaje seleccionado.%s\n", KRED, KNRM);
        exit(1);
    }
    return personaje;
}
int writeSeparatePlayerFile(Jugador* player){
    char buffer[101];
    strcpy(buffer, RUTA_PLAYERS);
    strcat(buffer, player->nombre);
    strcat(buffer, ".pj");
    FILE* player_file = fopen(buffer, "wb");
    fwrite(player, sizeof(Jugador), 1, player_file);
    if(fclose(player_file) == EOF){
        fprintf(stderr, "%sError al cerrar '%s'.%s", KRED, buffer, KNRM);
        return -1;
    }
    return 0;
}
int write_total_jugadores(int total){
    FILE *total_file = fopen(FILE_TOTAL, "wb"); 
    fwrite(&total, sizeof(int), 1, total_file);
    fclose(total_file);
    return 0;
}