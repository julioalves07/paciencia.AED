#include "pac.h"
#include <stdio.h>

//teste
void printcolunas(lista colunas[7]){
    for(int i=0; i<7; i++){
        carta * aux = colunas[i].comeco;
        while(aux){
            printf("%d%c, ", aux->valor, aux->naipe);
            aux = aux->proxima;
        }
        printf("\n");
    }
    printf("\n");
}
//teste
void printdeck(lista * deck){
    carta * aux = deck->comeco;
    while(aux){
        printf("%d%c, ", aux->valor, aux->naipe);
        aux = aux->proxima;
    }
    printf("\n");
}

int main(){
    carta *baralho[52];
    lista deck, colunas[7], pilhas[4];

    novoBaralho(baralho);
    embaralha(baralho);
    separarCartas(baralho, &deck, colunas, pilhas);
    //testes
    printcolunas(colunas);
    printdeck(&deck);
    
    liberaBaralho(baralho);
    return 0;
}