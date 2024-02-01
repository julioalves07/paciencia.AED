#include "pac.h"
#include <time.h>
#include <stdlib.h>

void novoBaralho(carta *baralho[52]){
    srand(time(NULL));
    
    for(int i = 0; i < 52; i++){
        baralho[i] = (carta *) calloc(1, sizeof(carta));
        baralho[i]->valor = i%13 + 1;

        if(i < 13) baralho[i]->naipe = 'c';
        else if(i < 26) baralho[i]->naipe = 'e';
        else if(i < 39) baralho[i]->naipe = 'o';
        else baralho[i]->naipe = 'p';

        baralho[i]->id = rand();
    }
    
}

void embaralha(carta *baralho[52]){

    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51-i; j++)
            if(baralho[j]->id > baralho[j+1]->id){
                carta *aux = baralho[j];
                baralho[j] = baralho[j+1];
                baralho[j+1] = aux;
            }

}

void novoDeck(){

}

void fundacao(){

}

void pilhas(){
    
}

void separaCartas(){

}

void mostrar(){

}

void mover(){

}

void finaliza(){
    
}