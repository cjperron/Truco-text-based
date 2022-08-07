#include"truco.h"
#include"juego.h"
char *getProvincia(Provincia provincia){
    char *res = (char*) malloc(sizeof(char) * 20);
    switch(provincia){
        case BuenosAires:
            strcpy(res, "Buenos Aires");
            return res;
        case EntreRios:
            strcpy(res, "Entre Rios");
            return res;
        case SantaFe:
            strcpy(res, "Santa Fe");
            return res;
        case Cordoba:
            strcpy(res, "Cordoba");
            return res;
        case SantiagoDelEstero:
            strcpy(res, "Santiago Del Estero");
            return res;
        case Tucuman:
            strcpy(res, "Tucuman");
            return res;
        case Salta:
            strcpy(res, "Salta");
            return res;
        case Misiones:
            strcpy(res, "Misiones");
            return res;
        case LaRioja:
            strcpy(res, "La Rioja");
            return res;
        case Formosa:
            strcpy(res, "Formosa");
            return res;
        case Chaco:
            strcpy(res, "Chaco");
            return res;
        case SantaCruz:
            strcpy(res, "Santa Cruz");
            return res;
        case SanJuan:
            strcpy(res, "San Juan");
            return res;
        case SanLuis:
            strcpy(res, "San Luis");
            return res;
        case RioNegro:
            strcpy(res, "Rio Negro");
            return res;
        case LaPampa:
            strcpy(res, "La Pampa");
            return res;
        case Jujuy:
            strcpy(res, "Jujuy");
            return res;
        case Corrientes:
            strcpy(res, "Corrientes");
            return res;
        case Neuquen:
            strcpy(res, "Neuquen");
            return res;
        case Catamarca:
            strcpy(res, "Catamarca");
            return res;
        case Chubut:
            strcpy(res, "Chubut");
            return res;
        case TierraDelFuego:
            strcpy(res, "Tierra del fuego");
            return res;
        case Mendoza:
            strcpy(res, "Mendoza");
            return res;
    }
    return NULL;
}
char *sgetProvincia(Provincia provincia, char* buffer){
    //char *res = (char*) malloc(sizeof(char) * 20);
    switch(provincia){
        case BuenosAires:
            strcpy(buffer, "Buenos Aires");
            return buffer;
        case EntreRios:
            strcpy(buffer, "Entre Rios");
            return buffer;
        case SantaFe:
            strcpy(buffer, "Santa Fe");
            return buffer;
        case Cordoba:
            strcpy(buffer, "Cordoba");
            return buffer;
        case SantiagoDelEstero:
            strcpy(buffer, "Santiago Del Estero");
            return buffer;
        case Tucuman:
            strcpy(buffer, "Tucuman");
            return buffer;
        case Salta:
            strcpy(buffer, "Salta");
            return buffer;
        case Misiones:
            strcpy(buffer, "Misiones");
            return buffer;
        case LaRioja:
            strcpy(buffer, "La Rioja");
            return buffer;
        case Formosa:
            strcpy(buffer, "Formosa");
            return buffer;
        case Chaco:
            strcpy(buffer, "Chaco");
            return buffer;
        case SantaCruz:
            strcpy(buffer, "Santa Cruz");
            return buffer;
        case SanJuan:
            strcpy(buffer, "San Juan");
            return buffer;
        case SanLuis:
            strcpy(buffer, "San Luis");
            return buffer;
        case RioNegro:
            strcpy(buffer, "Rio Negro");
            return buffer;
        case LaPampa:
            strcpy(buffer, "La Pampa");
            return buffer;
        case Jujuy:
            strcpy(buffer, "Jujuy");
            return buffer;
        case Corrientes:
            strcpy(buffer, "Corrientes");
            return buffer;
        case Neuquen:
            strcpy(buffer, "Neuquen");
            return buffer;
        case Catamarca:
            strcpy(buffer, "Catamarca");
            return buffer;
        case Chubut:
            strcpy(buffer, "Chubut");
            return buffer;
        case TierraDelFuego:
            strcpy(buffer, "Tierra del fuego");
            return buffer;
        case Mendoza:
            strcpy(buffer, "Mendoza");
            return buffer;
    }
    return NULL;
}