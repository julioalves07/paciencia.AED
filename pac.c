#include "pac.h"
#include <time.h>
#include <stdlib.h>

void novoBaralho(carta *k[52]){
    srand(time(NULL));
    
    int c=-1;

    for(int i = 0; i < 52; i++){

        k[i] = (carta *) calloc(1, sizeof(carta));
        
        if(!(i%13)) c++;
        k[i]->valor = i%13 + 1;
        if(c==0) k[i]->naipe = 'c';
        if(c==1) k[i]->naipe = 'e';
        if(c==2) k[i]->naipe = 'o';
        if(c==3) k[i]->naipe = 'p';
        k[i]->id = rand();
    }
    
}

void embaralha(carta *k[52]){

    for(int i = 0; i < 52; i++)
        for(int j = 0; j < 52; j++)
            if(k[j]->id > k[i]->id){
                carta *aux = k[j];
                k[j] = k[i];
                k[i] = aux;
            }

}

void novoDeck(){

}

void fundacao(){

}

void pilhas(carta *baralho[]){
    
}

void separaCartas(){

}

void mostrar(){

}

void mover(){

}

void finaliza(){
    
}