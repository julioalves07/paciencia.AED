#include "pac.h"
#include <stdio.h>

void print();

int main(){

    novoBaralho();
    print();
    embaralha();
    print();

    return 0;
};

void print(){

    carta *atual = monte;

    while(atual != NULL){
        printf("%d%c ", atual->valor, atual->naipe);
        atual = atual->proxima;
    }

    printf("\n");
}