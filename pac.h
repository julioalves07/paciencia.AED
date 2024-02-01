#ifndef __PAC_H__
#define __PAC_H__

//Virada serve para dizer se a carta está virada pra cima e é pra ser usada na função de mostrar
typedef struct _carta {
    int valor, id;
    char naipe, virada;
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
void separarCartas(carta *baralho[52], lista *deck, lista colunas[7], lista pilhas[4]);
void liberaBaralho(carta *baralho[52]);
void mostrar();
void mover();
void finaliza();

#endif