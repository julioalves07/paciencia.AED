#include "pac.h"
#include <stdio.h>

void print(carta *baralho[52]);

int main(){
    carta *baralho[52];

    novoBaralho(baralho);
    // print(baralho);
    embaralha(baralho);
    print(baralho);

    return 0;
};

void print(carta *baralho[52]){

    for(int i = 0; i < 52; i++)
        printf("%d%c ", baralho[i]->valor, baralho[i]->naipe);

    printf("\n");
}