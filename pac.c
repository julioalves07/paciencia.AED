#include "pac.h"
#include <time.h>
#include <stdlib.h>

carta *monte = NULL;

void novoBaralho(){
    carta *baralho = NULL;
    
	baralho = (carta *)malloc(sizeof(carta));
    monte = baralho;

    for(int i = 0; i<4; i++){
        for(int j = 1; j <= 13; j++){
            baralho->valor = j;

            if(i == 0) baralho->naipe = 'c';
            else if(i == 1) baralho->naipe = 'e';
            else if(i == 2) baralho->naipe = 'o';
            else if(i == 3) baralho->naipe = 'p';
		
            if(i!=3 || j!=13){
                baralho->proxima = (carta *)malloc(sizeof(carta));
                baralho = baralho->proxima;
            } else
                baralho->proxima = NULL;
        }
    }
}

void embaralha(){
    srand(time(NULL));

    for(int i = 51; i > 0; i--){
        int j = rand()%(i + 1);

        carta *carta1 = monte;
        carta *carta2 = monte;

        for(int k = 0; k<i; k++)
            carta1 = carta1->proxima;

        for(int k = 0; k<j; k++)
            carta2 = carta2->proxima;

        int v_temp = carta1->valor;
        char n_temp = carta1->naipe;
        carta1->valor = carta2->valor;
        carta1->naipe = carta2->naipe;
        carta2->valor = v_temp;
        carta2->naipe = n_temp;
    }

}

void novoDeck(){
    carta *aux;



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