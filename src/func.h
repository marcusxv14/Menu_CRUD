#ifndef FUNC_H
#define FUNC_H

// Função para definir a tela do terminal
void inicializar_tela();
// Função para desenhar a janela
void janela(int linInicial, int colInicial, int linFinal, int colFinal, char* titulo, int tipoMoldura);
// Função para exibir um rótulo
void label(int lin, int col, char* texto);
// Função para ler uma string do usuário
void ler_string(int lin, int col, int tamanho, char* destino);
// Função para ler um número inteiro do usuário
int ler_inteiro(int lin, int col, int tamanho);
// Função para ler um número decimal do usuário
float ler_decimal(int lin, int col, int tamanho);

#endif