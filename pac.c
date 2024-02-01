#include "pac.h"
#include <time.h>
#include <stdlib.h>

//Aloca um baralho de cartas dinamicamente e salva todas em um vetor estático
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

//Embaralha as cartas pelo id aleatório
void embaralha(carta *baralho[52]){
    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51-i; j++)
            if(baralho[j]->id > baralho[j+1]->id){
                carta *aux = baralho[j];
                baralho[j] = baralho[j+1];
                baralho[j+1] = aux;
            }
}

//Coloca a quantidade certa de cartas em cada coluna e seta a última carta de cada coluna como virada
void setColunas(carta *baralho[52], lista colunas[7]){
    int c=0;
    for(int i = 0; i < 7; i++){
        colunas[i].comeco=0;
        colunas[i].tamanho=i+1;
        for(int j = 0; j <= i; j++){
            baralho[c]->proxima = colunas[i].comeco;
            colunas[i].comeco = baralho[c];
            if(j==0) baralho[c]->virada = 1;
            c++;
        }
    }
}

//Coloca o restante das cartas no deck
void setDeck(carta *baralho[52], lista *deck){
    deck->comeco = 0;
    deck->tamanho = 24;
    for(int i=28; i<52; i++){
        baralho[i]->proxima = deck->comeco;
        deck->comeco = baralho[i];
    }
}

//Limpa o lixo de memória nas pilhas
void setPilhas(lista pilhas[4]){
    for(int i = 0; i < 4; i++){
        pilhas[i].comeco = 0;
        pilhas[i].tamanho = 0;
    }
}

//Setup com o baralho já criado
void separarCartas(carta *baralho[52], lista *deck, lista colunas[7], lista pilhas[4]){
    setColunas(baralho, colunas);
    setDeck(baralho, deck);
    setPilhas(pilhas);
}

void liberaBaralho(carta *baralho[52]){
    for(int i = 0; i < 52; i++){
        free(baralho[i]);
    }
}

void mostrar(){

}

void mover(){

}

void finaliza(){
    
}