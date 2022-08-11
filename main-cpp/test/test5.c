#include<stdio.h>
typedef struct{
    int x;
    int y;
} Punto ;
int main(){
    Punto puntos[3];
    Punto algun_punto ={
        .x = 10,
        .y = 5
    };
    puntos[0] = algun_punto;
    printf("puntos[0].x = %d",puntos[0].x);
    printf("puntos[0].y = %d",puntos[0].y);
    return 0;
}