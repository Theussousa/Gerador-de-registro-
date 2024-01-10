
#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 10
#define MAX_NOME 50


struct Registro {
    int id;
    char nome[MAX_NOME];
    char conta[MAX_NOME];
    float valor;
};


void ordenarPorId(struct Registro registros[]) {
   
    for (int i = 0; i < MAX_REGISTROS - 1; i++) {
        for (int j = 0; j < MAX_REGISTROS - i - 1; j++) {
            if (registros[j].id > registros[j + 1].id) {
                struct Registro temp = registros[j];
                registros[j] = registros[j + 1];
                registros[j + 1] = temp;
            }
        }
    }
}



void ordenarPorValor(struct Registro registros[]) {
    
    for (int i = 0; i < MAX_REGISTROS - 1; i++) {
        for (int j = 0; j < MAX_REGISTROS - i - 1; j++) {
            if (registros[j].valor < registros[j + 1].valor) {
                struct Registro temp = registros[j];
                registros[j] = registros[j + 1];
                registros[j + 1] = temp;
            }
        }
    }
} 

void buscarPorNome(struct Registro registros[], char nome[]) {
    int encontrados = 0;
    for (int i = 0; i < MAX_REGISTROS; i++) {
        if (strcmp(registros[i].nome, nome) == 0) {
            printf("ID: %d, Nome: %s, Conta: %s, Valor: %.2f\n", registros[i].id, registros[i].nome, registros[i].conta, registros[i].valor);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum registro encontrado com esse nome.\n");
    }
}

 int main() {

    struct Registro registros[MAX_REGISTROS] = {
        {1, "João", "Fisica", 100},
        {2, "Maria", "Fisica", 150},
        {3, "Pedro", "Juridica", 75},
        {4, "Ana", "Juridica", 200},
        {5, "Carlos", "Juridica", 120},
        {6, "Mariana", "Fisica", 180},
        {7, "José", "Fisica", 90},
        {8, "Laura", "Fisica", 300},
        {9, "Paulo", "Fisica", 250},
        {10, "Lúcia", "Juridica", 50}
    };
    
    ordenarPorId(registros);
    
    printf("Registros ordenados por Id? \n");
     for(int i = 0; i < MAX_REGISTROS; i++) {
        printf("ID: %d, Nome: %s, Conta: %s, Valor: %.2f\n", registros[i].id, registros[i].nome, registros[i].conta, registros[i].valor);
    } 
    
    ordenarPorId(registros);
    
    printf("\nRegistros ordenados por valor (ordem decrescente):\n");
    for (int i = 0; i < MAX_REGISTROS; i++) {
        printf("ID: %d, Nome: %s, Conta: %s, Valor: %.2f\n", registros[i].id, registros[i].nome, registros[i].conta, registros[i].valor);
    }
    
    
    char nomeBusca[MAX_NOME];
    printf("\nDigite o nome a ser buscado: ");
    scanf("%s", nomeBusca);
    buscarPorNome(registros, nomeBusca);
    
    
    return 0;
    
}

