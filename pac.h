#ifndef __PAC_H__
#define __PAC_H__

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _carta {
    int valor, id;
    char naipe;
    struct _carta *proximo;
} carta;

void novoBaralho(carta *k[52]);
void embaralha(carta *k[52]);
void novoDeck();
void fundacao();
void pilhas();
void separaCartas();
void mostrar();
void mover();
void finaliza();

#endif