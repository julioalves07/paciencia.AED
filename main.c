#include "pac.h"
#include <stdio.h>

int main(){
    carta *baralho[52];
    lista deck, pile, colunas[7], pilhas[4];

    novoBaralho(baralho);
    embaralha(baralho);
    separarCartas(baralho, &deck, &pile, colunas, pilhas);

    ///inicio do jogo
	while(paciencia(&deck, &pile, colunas, pilhas));
    liberaBaralho(baralho);
    return 0;
}
