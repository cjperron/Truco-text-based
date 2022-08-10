#include "mazo.h"

Mazo::Mazo(void)
{
    int j = 1;
    for (int i = 0; i < 10; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i] = Carta(Espada, j, "Espada " + std::to_string(j));
        j++;
    }
    j = 1;
    for (int i = 10; i < 20; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i] = Carta(Basto, j, "Basto " + std::to_string(j));
        j++;
    }
    j = 1;
    for (int i = 20; i < 30; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i] = Carta(Oro, j, "Oro " + std::to_string(j));
        j++;
    }
    j = 1;
    for (int i = 30; i < 40; i++)
    {
        while (j > 7 && j < 10) j++;
        cartas[i] = Carta(Copa, j, "Copa " + std::to_string(j));
        j++;
    }
}
Carta Mazo::getCarta(int index)
{
    return this->cartas[index];
}
void Mazo::mezclarMazo(void)
{
    srand(time(NULL));
    for (int i = 0; i < CANT_CARTAS_TRUCO; i++)
    {
        int j = rand() % CANT_CARTAS_TRUCO;
        Carta aux = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = aux;
    }
}
string Mazo::toString()
{
    string res = "Mazo {\n";
    for (int i = 0; i < CANT_CARTAS_TRUCO; i++)
    {
        res.append(this->cartas[i].toString()+"\n");
    }
    res.append("\n }");
    return res;
}
