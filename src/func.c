#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void inicializar_tela() {
    printf("\033[2J"); // Limpa a tela
    printf("\033[1;1H"); // Posiciona o cursor no canto superior esquerdo
}

void janela(int linInicial, int colInicial, int linFinal, int colFinal, char* titulo, int tipoMoldura) {
    int i, j;
    
    // Define o tamanho da janela
    int largura = colFinal - colInicial + 1;
    int altura = linFinal - linInicial + 1;
    
    // Desenha a moldura superior
    printf("\033[%dm", tipoMoldura);
    printf("\033[%d;%dH", linInicial, colInicial);
    for (i = 0; i < largura; i++) {
        printf("=");
    }
    
    // Escreve o título centralizado
    int tituloLen = strlen(titulo);
    int tituloPos = colInicial + (largura - tituloLen) / 2;
    printf("\033[%d;%dH%s", linInicial, tituloPos, titulo);
    
    // Desenha a moldura inferior
    printf("\033[%d;%dH", linFinal, colInicial);
    for (i = 0; i < largura; i++) {
        printf("=");
    }
    
    // Desenha as laterais da moldura
    for (i = linInicial + 1; i < linFinal; i++) {
        printf("\033[%d;%dH", i, colInicial);
        printf("|");
        printf("\033[%d;%dH", i, colFinal);
        printf("|");
    }
    
    // Define a cor padrão
    printf("\033[0m");
}

void label(int lin, int col, char* texto) {
    printf("\033[%d;%dH%s", lin, col, texto);
}

void ler_string(int lin, int col, int tamanho, char* destino) {
    printf("\033[%d;%dH", lin, col);
    fgets(destino, tamanho, stdin);
    
    // Remove a quebra de linha da string lida
    size_t len = strlen(destino);
    if (len > 0 && destino[len - 1] == '\n') {
        destino[len - 1] = '\0';
    }
}

int ler_inteiro(int lin, int col, int tamanho) {
    char buffer[11]; // Tamanho máximo de um número inteiro com sinal em string é 10 + 1 para o caractere nulo
    ler_string(lin, col, tamanho, buffer);
    return atoi(buffer);
}

float ler_decimal(int lin, int col, int tamanho) {
    char buffer[11]; // Tamanho máximo de um número decimal com sinal em string é 10 + 1 para o caractere nulo
    ler_string(lin, col, tamanho, buffer);
    return atof(buffer);
}

