#include "pac.h"
#include <time.h>
#include <conio.h>
#include <stdio.h>
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

        baralho[i]->virada = 0;
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
            if(j==i) baralho[c]->virada = 1;
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
void separarCartas(carta *baralho[52], lista *deck, lista *pile, lista colunas[7], lista pilhas[4]){
    setColunas(baralho, colunas);
    setDeck(baralho, deck);
    setPilhas(pilhas);
    pile->comeco=NULL;
    pile->tamanho=0;
}

void liberaBaralho(carta *baralho[52]){
    for(int i = 0; i < 52; i++){
        free(baralho[i]);
    }
}

void mostrar(lista *deck, lista *pile){
	carta *aux = deck->comeco;
	if(!aux){
		while(pile->comeco){
			aux = pile->comeco;
			pile->comeco = pile->comeco->proxima;
			aux->proxima = deck->comeco;
			aux->virada = 0;
			deck->comeco = aux;
		}
		return;
	}
	deck->comeco = deck->comeco->proxima;
	aux->proxima = pile->comeco;
	aux->virada = 1;
	pile->comeco = aux;
}

void finaliza(lista pilhas[4]){
	if(pilhas[0].comeco->valor == 13 && pilhas[1].comeco->valor == 13 && pilhas[2].comeco->valor == 13 && pilhas[3].comeco->valor == 13){
		printf("\nFim de jogo!");
		getch();
	}
}

int mover(int posicao, int origem, int destino, lista *pile, lista colunas[7], lista pilhas[4]){
	if(origem == 12 || destino == 12 || destino == 7) return 2;
	else if(origem <= 6){ //colunas
		if(!(colunas[origem].comeco)) return 2;
		else if(destino <= 6){
			if(!movimentoColunas(colunas[origem].comeco, colunas[destino].comeco)) return 2;
			carta *aux[posicao];
			for(int i = 0; i < posicao; ++i){
				aux[i] = colunas[origem].comeco;
				colunas[origem].comeco = colunas[origem].comeco->proxima;
			}
			for(int i = posicao - 1; i >= 0; --i){
				aux[i]->proxima = colunas[destino].comeco;
				colunas[destino].comeco = aux[i];
			}
			if(colunas[origem].comeco) colunas[origem].comeco->virada = 1;
		}
		else{
			if(!movimentoFundacao(colunas[origem].comeco, colunas[destino].comeco)) return 2;
			carta *aux = colunas[origem].comeco;
			colunas[origem].comeco = aux->proxima;
			aux->proxima = pilhas[(destino-8)].comeco;
			pilhas[(destino-8)].comeco = aux;
			if(colunas[origem].comeco) colunas[origem].comeco->virada = 1;
		}
	}
	else if(origem == 7 ){ //estoque
		if(!(pile->comeco)) return 2;
		else if(destino <= 6){
			if(!movimentoColunas(pile->comeco, colunas[destino].comeco)) return 2;
			carta *aux = pile->comeco;
			pile->comeco = pile->comeco->proxima;
			aux->proxima = colunas[destino].comeco;
			colunas[destino].comeco = aux;
		}
		else{
			if(!movimentoFundacao(pile->comeco, colunas[destino].comeco)) return 2;
			carta *aux = pile->comeco;
			pile->comeco = aux->proxima;
			aux->proxima = pilhas[(destino-8)].comeco;
			pilhas[(destino-8)].comeco = aux;
		}
	}
	else{ //fundacao
		if(!(pilhas[(origem-8)].comeco)) return 2;
		else if(destino > 7) return 2;
		else{

			if(!movimentoColunas(pilhas[(origem-8)].comeco, colunas[destino].comeco)) return 2;
			carta *aux = pilhas[(origem-8)].comeco;

			pilhas[(origem-8)].comeco = pilhas[(origem-8)].comeco->proxima;
			aux->proxima = colunas[destino].comeco;
			colunas[destino].comeco = aux;
		}
	}
	return 1;
}

int movimentoColunas(carta *origem, carta *destino){
	if(!destino && origem->valor == 13) return 1;
	if(destino->valor - 1 == origem->valor){
		if(origem->naipe == 'e' || origem->naipe == 'p'){
			if(destino->naipe == 'c' || destino->naipe == 'o') return 1;
		}
		else if(origem->naipe == 'c' || origem->naipe == 'o'){
			if(destino->naipe == 'e' || destino->naipe == 'p') return 1;
		}
	}
	return 0;
}

int movimentoFundacao(carta *origem, carta *destino){
	return 1;
	if(!destino && origem->valor == 1) return 1;
	if(destino->valor + 1 == origem->valor){
		if(origem->naipe == 'e' && destino->naipe == 'e') return 1;
		if(origem->naipe == 'c' && destino->naipe == 'c') return 1;
		if(origem->naipe == 'o' && destino->naipe == 'o') return 1;
		if(origem->naipe == 'p' && destino->naipe == 'p') return 1;
	}
	return 0;
}

int idPilha(char index){
	if(index == 'a' || index == 'A') return 0;
	if(index == 'b' || index == 'B') return 1;
	if(index == 'c' || index == 'C') return 2;
	if(index == 'd' || index == 'D') return 3;
	if(index == 'e' || index == 'E') return 4;
	if(index == 'f' || index == 'F') return 5;
	if(index == 'g' || index == 'G') return 6;
	if(index == 'n' || index == 'N') return 7;
	if(index == 'w' || index == 'W') return 8;
	if(index == 'x' || index == 'X') return 9;
	if(index == 'y' || index == 'Y') return 10;
	if(index == 'z' || index == 'Z') return 11;
	return 12;
}

int comando(lista *deck, lista *pile, lista colunas[7], lista pilhas[4]){
	char origem, destino;
	int posicao, numero;

	printf("\noperacao: ");
	if((origem = getch()) != 27){
		printf("%c", origem);
		if(origem == 77 || origem ==109){
			getchar();
			mostrar(deck, pile);
			return 1;
		}
	}
	else return 0;
	scanf("%d", &posicao);
	destino = getchar();
	if((numero = getchar()) >= '0' && numero <= '9') posicao = posicao * 10 + (numero - '0');
	else ungetc(numero, stdin);
	return mover(posicao, idPilha(origem), idPilha(destino), pile, colunas, pilhas);
}

int paciencia(lista *deck, lista *pile, lista colunas[7], lista pilhas[4]){
	printpaciencia(deck, pile, colunas, pilhas);
	int i = comando(deck, pile, colunas, pilhas);
	if(i > 1) i = paciencia(deck, pile, colunas, pilhas);
	else if(i) finaliza(pilhas);
	return i;
}

void printpaciencia(lista *deck, lista *pile, lista colunas[7], lista pilhas[4]){
	system("cls");
	printdeck(deck, pile);
    printpilhas(pilhas);
    printcolunas(colunas);
}

void printcolunas(lista colunas[7]){
    for(int i=0; i<7; i++){
		switch (i){
			case 0:
			printf("A  "); break;
			case 1:
			printf("B  "); break;
			case 2:
			printf("C  "); break;
			case 3:
			printf("D  "); break;
			case 4:
			printf("E  "); break;
			case 5:
			printf("F  "); break;
			case 6:
			printf("G  "); break;
		}

        carta * aux = colunas[i].comeco;
		if(!aux) printf("XX");
		pilhainvertida(aux);
        printf("\n");
    }
}

void pilhainvertida(carta *topo){
	if(!topo) return;
	pilhainvertida(topo->proxima);
	if(topo->proxima) printf(", ");
	if(topo->virada) printf("%d%c", topo->valor, topo->naipe);
	else printf("??");
}

void printdeck(lista * deck, lista * pile){
    carta * aux = deck->comeco;
    printf("M  ");
    if(aux) printf("??");
    else printf("XX");

    aux=pile->comeco;
    printf("\nN  ");
	if(aux) printf("%d%c", aux->valor, aux->naipe);
	else printf("XX");
    printf("\n\n");
}

void printpilhas(lista pilhas[4]){
	for(int i=0; i<4; i++){
		switch (i){
			case 0:
			printf("W  "); break;
			case 1:
			printf("X  "); break;
			case 2:
			printf("Y  "); break;
			case 3:
			printf("Z  "); break;
		}
		carta * aux = pilhas[i].comeco;
		if(!aux) printf("XX");
		else printf("%d%c", aux->valor, aux->naipe);
        printf("\n");
	}
	printf("\n");
}
