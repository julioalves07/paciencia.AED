#include "pac.h"
#include <time.h>
#include <stdlib.h>

void novoBaralho(carta *baralho[52]){
    srand(time(NULL));
    
    int c=-1;

    for(int i = 0; i < 52; i++){

        baralho[i] = (carta *) calloc(1, sizeof(carta));
        
        if(!(i%13)) c++;
        baralho[i]->valor = i%13 + 1;
        if(c==0) baralho[i]->naipe = 'c';
        if(c==1) baralho[i]->naipe = 'e';
        if(c==2) baralho[i]->naipe = 'o';
        if(c==3) baralho[i]->naipe = 'p';
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