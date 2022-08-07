#include "truco.h"
Carta *crearMazo(void)
{
    FILE *archivo_mazo = fopen(FILE_MAZO, "wb");
    if (archivo_mazo == NULL)
    { // No se pudo abrir el archivo de mazo.
        printf("Error: No se pudo abrir el archivo de mazo.\n");
        espera();
        return NULL;
    } // Se pudo abrir el archivo de mazo.
    // El total de cartas creadas esta al inicio.
    Carta *mazo = (Carta *)malloc(sizeof(Carta) * CANT_CARTAS_TRUCO);
    int j = 1;
    char num[3];
    for (int i = 0; i < 10; i++)
    {
        (mazo + i)->palo = Espada;
        if (j == 8)
            while (j < 10)
                j++;
        (mazo + i)->valor = j;
        sprintf(num, "%d", j);
        (mazo + i)->nombre[0] = '\0';
        strcat((mazo + i)->nombre, num);
        strcat((mazo + i)->nombre, " de Espadas");
        j++;
    }
    j = 1;
    for (int i = 10; i < 20; i++)
    {
        (mazo + i)->palo = Oro;
        if (j == 8)
            while (j < 10)
                j++;
        (mazo + i)->valor = j;
        sprintf(num, "%d", j);
        (mazo + i)->nombre[0] = '\0';
        strcat((mazo + i)->nombre, num);
        strcat((mazo + i)->nombre, " de Oro");
        j++;
    }
    j = 1;
    for (int i = 20; i < 30; i++)
    {
        (mazo + i)->palo = Basto;
        if (j == 8)
            while (j < 10)
                j++;
        (mazo + i)->valor = j;
        sprintf(num, "%d", j);
        (mazo + i)->nombre[0] = '\0';
        strcat((mazo + i)->nombre, num);
        strcat((mazo + i)->nombre, " de Basto");
        j++;
    }
    j = 1;
    for (int i = 30; i < 40; i++)
    {
        (mazo + i)->palo = Copa;
        if (j == 8)
            while (j < 10)
                j++;
        (mazo + i)->valor = j;
        sprintf(num, "%d", j);
        (mazo + i)->nombre[0] = '\0';
        strcat((mazo + i)->nombre, num);
        strcat((mazo + i)->nombre, " de Copa");
        j++;
    }
    fwrite(mazo, sizeof(Carta), CANT_CARTAS_TRUCO, archivo_mazo);
    return mazo;
}
// Funcion que lee el archivo de mazo, y devuelve el mazo leido.
Carta *leerMazo(void)
{
    FILE *archivo_mazo = fopen(FILE_MAZO, "rb");
    if (archivo_mazo == NULL)
    {
        return NULL;
    }
    Carta *mazo = (Carta *)malloc(sizeof(Carta) * CANT_CARTAS_TRUCO);
    if (fread(mazo, sizeof(Carta), CANT_CARTAS_TRUCO, archivo_mazo) != CANT_CARTAS_TRUCO) //No existe mazo.truco
    {
        //printf("Error en fread.\n");
        //espera();
        if (fclose(archivo_mazo) == EOF)
    {
        printf("Error en fclose.\n");
        espera();
        free(mazo);
        return NULL;
    }
        free(mazo);
        return NULL;
    }
    // Tengo el struct de cartas creadas.
    if (fclose(archivo_mazo) == EOF)
    {
        printf("Error en fclose.\n");
        espera();
        free(mazo);
        return NULL;
    }
    return mazo;
}
// Devuelve el puntero con el array shuffleado.
Carta *mezclarMazo(Carta *mazo)
{
    if (mazo == NULL)
    {
        printf("Mazo es NULL.");
    }
    return NULL;
}
// Muestra el mazo, y lo guarda en log.txt.
void debugMostrarMazo(Carta *mazo)
{
    FILE *log = fopen(FILE_LOG, "a");
    char time_string[12];
    time_t ahora = time(&ahora);
    struct tm *now = localtime(&ahora);
    strftime(time_string, 12, "%H:%M:%S", now);
    fprintf(log, "[%s]\n", time_string);
    for (int i = 0; i < CANT_CARTAS_TRUCO; i++)
    {
        printf("Carta [%i]: \nPalo: ", i);
        fprintf(log, "Carta [%i]: \nPalo: ", i);
        switch ((mazo + i)->palo)
        {
        case Espada:
            printf("Espada\n");
            fprintf(log, "Espada\n");
            break;
        case Basto:
            printf("Basto\n");
            fprintf(log, "Basto\n");
            break;
        case Oro:
            printf("Oro\n");
            fprintf(log, "Oro\n");
            break;
        case Copa:
            printf("Copa\n");
            fprintf(log, "Copa\n");
            break;
        }
        printf("Valor: %d\nNombre: %s\n\n", (mazo + i)->valor, (mazo + i)->nombre);
        fprintf(log, "Valor: %d\nNombre: %s\n\n", (mazo + i)->valor, (mazo + i)->nombre);
    }
    fclose(log);
    espera();
    return;
}