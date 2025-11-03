#include <stdio.h>

typedef struct produto {
    int codigo;
    char nome[30];
    float preco;
    int quantidade;
} Produto;

int main() {

    FILE *produtos = fopen("produtos.txt", "r");
    if(produtos == NULL) {
        puts("Erro ao abrir arquivo\n");
        return 1;
    }

    Produto lista_de_produtos[20];

    int operacao;
    while(1) {
        printf("Digite a operacao desejada:\n1. Adicionar produto\n2. Buscar produto por código\n3. Imprimir produtos\n4. Ordenar pro preço e imprimir\n");
        scanf("%d", &operacao);
        switch(operacao) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                return 0;
            default:
                printf("Operacao invalida\n");
        }
    }

    return 0;
}