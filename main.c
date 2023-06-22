#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./src/func.h"

int main() {
    inicializar_tela();
    janela(1, 1, 15, 45, "Minha Janela", 1);
    label(3, 3, "Digite uma string:");
    char str[51];
    ler_string(4, 3, 50, str);
    label(6, 3, "Digite um inteiro:");
    int num = ler_inteiro(7, 3, 10);
    label(9, 3, "Digite um decimal:");
    float dec = ler_decimal(10, 3, 10);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("String: %s\n", str);
    printf("Inteiro: %d\n", num);
    printf("Decimal: %.2f\n", dec);
    return 0;
}