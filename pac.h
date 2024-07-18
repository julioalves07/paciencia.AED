#ifndef __PAC_H__
#define __PAC_H__

//Virada serve para dizer se a carta está virada pra cima e é pra ser usada na função de mostrar
typedef struct _carta {
    int valor, id, virada;
    char naipe;
    struct _carta *proxima;
} carta;

typedef struct {
    int tamanho;
    carta *comeco;
} lista;

void novoBaralho(carta *baralho[52]);
void embaralha(carta *baralho[52]);
void setColunas(carta *baralho[52], lista colunas[7]);
void setDeck(carta *baralho[52], lista *deck);
void setPilhas(lista pilhas[4]);
void separarCartas(carta *baralho[52], lista *deck, lista *pile, lista colunas[7], lista pilhas[4]);
void liberaBaralho(carta *baralho[52]);

void mostrar(lista *deck, lista *pile);
void finaliza(lista pilhas[4]);
int mover(int posicao, int origem, int destino, lista *pile, lista colunas[7], lista pilhas[4]);
int movimentoColunas(carta *origem, carta *destino);
int movimentoFundacao(carta *origem, carta *destino);
int idPilha(char index);

int comando(lista *deck, lista *pile, lista colunas[7], lista pilhas[4]);
int paciencia(lista *deck, lista *pile, lista colunas[7], lista pilhas[4]);

void printpaciencia(lista *deck, lista *pile, lista colunas[7], lista pilhas[4]);
void printpilhas(lista pilhas[4]);
void pilhainvertida(carta *topo);
void printdeck(lista *deck, lista *pile);
void printcolunas(lista colunas[7]);

#endif
