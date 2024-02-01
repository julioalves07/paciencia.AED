#ifndef __PAC_H__
#define __PAC_H__

typedef struct _carta {
    int valor;
    char naipe;
    struct _carta *proxima;
} carta;

extern carta *monte;

void novoBaralho();
void embaralha();
void novoDeck();
void fundacao();
void pilhas();
void separaCartas();
void mostrar();
void mover();
void finaliza();

#endif