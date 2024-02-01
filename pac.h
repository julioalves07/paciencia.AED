#ifndef __PAC_H__
#define __PAC_H__

typedef struct _carta {
    int valor, id;
    char naipe;
    struct _carta *proxima;
} carta;

void novoBaralho(carta *baralho[52]);
void embaralha(carta *baralho[52]);
void novoDeck();
void fundacao();
void pilhas();
void separaCartas();
void mostrar();
void mover();
void finaliza();

#endif