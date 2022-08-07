# Truco text based
    Jugar al truco en la terminal
> ## Tema juego en si
>    El juego tiene 3 modos en si:
>    - **Partido vs IA**
>    1. El modo es straightfoward, jugas un partido vs una IA que tiene los stats randomizados...
>    2. Podes usar *cheat codes* de forma ilimitada
>    - **Torneo san bonifacio**
>    1. Es como el primer modo, solo que son varios partidos seguidos hasta ganar el torneo y te dan xp y plata para tu personaje.
>    2.  Podes usar *cheat codes* de forma ilimitada.
>    - **Modo carrera**
>    1. El plato fuerte, tenes que ganar las ligas de todas las provincias
>    2. el menu figura el estado de la liga (siempre se generan nuevos contrincantes) y el siguiente partido
>    3. Para conseguir *cheat codes* se debe de acudir al mercado, y gastar la plata obtenida en los cheat codes, se desbloquean mejores mercados con mejores cheat codes si se tiene mayor lvl.
>   4. como se avanza a la sig. provincia? comprando un cheat code especial que sale en el mercado de mayor nivel, que tiene una chance de desbloquearte el *BOSS FINAL* de la provincia. Le tenes que ganar 3 veces seguidas y tiene las stats al maximo (y puede que utilize un cheat code)

## Que mierda es un cheat code
>   - Un cheat code en si te puede dar (como tambien no...) una ventaja como una carta en especifico, o puntos en el partido
>   - Puede salir el tiro por la culata y cagarte la match, si es que te "decubren"
>   - Mientras mejor sea el cheat code, mas caro sale.

## Como quiero que funcione
>   1. El mazo es una clase que tiene un array de Cartas (tambien una clase)
>   2. Cada jugador se guarda en archivos separados, y cómo es cada uno, está especificado en los archivos, aunque puede estar sujeto a cambio.
>   3. El partido es una clase
>   4. El mercado es una clase
>   5. Los cheat codes son clases polimorficas, que varian lo que hacen, pero siempre tienen en comun algo: que son un codigo que se ingresa En partida, o algunos como Easter Egg en el Menu principal.
>      Cada codigo esta guardado en un archivo binario (asi no son tan faciles de ver y decifrar), y lo ideal es que por ej: todos los codigos que agregan puntos se agrupen en un archivo, los que dan cartas en otro, los de easter egg en otro, y así.
>   6. Las opciones por ahora son medio LOL, asi que me delimito a hacer que reseteen el progreso
