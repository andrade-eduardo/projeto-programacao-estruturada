#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    int codigo;
    char nome[30];
    float preco;
    int quantidade;
} Produto;

int main() {

    // abrindo o arquivo produtos.txt
    FILE *arquivo = fopen("produtos.txt", "r");
    if(arquivo == NULL) {
        puts("Erro ao abrir arquivo\n");
        return 1;
    }

    //salvando os produtos do arquivo no vetor produtos
    Produto *produtos = malloc(20 * sizeof(Produto));
    int qtd_produtos = 0;
    while(fscanf(arquivo, "%d %s %f %d", &produtos[qtd_produtos].codigo, produtos[qtd_produtos].nome, &produtos[qtd_produtos].preco, &produtos[qtd_produtos].quantidade) != EOF){
        qtd_produtos++;
    }
    fclose(arquivo);

    int operacao;
    while(1) {
        printf("\nDigite a operacao desejada:\n1. Adicionar produto\n2. Buscar produto por codigo\n3. Imprimir produtos\n4. Ordenar por preco e imprimir\n5. Sair\n");
        scanf("%d", &operacao);
        switch(operacao) {
            case 1:
                produtos = realloc(produtos, qtd_produtos * sizeof(Produto) + sizeof(Produto));
                printf("Digite o nome, preco e quantidade do produto:\n");
                scanf("%s %f %d", produtos[qtd_produtos].nome, &produtos[qtd_produtos].preco, &produtos[qtd_produtos].quantidade);
                produtos[qtd_produtos].codigo = produtos[qtd_produtos-1].codigo + 1;
                qtd_produtos++;
                break;
            case 2:
                printf("Digite o codigo:\n");
                int codigo_digitado;
                scanf("%d", &codigo_digitado);
                for(int i = 0; i < qtd_produtos; i++) {
                    if(produtos[i].codigo == codigo_digitado) {
                        printf("%s %.2f %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
                        break;
                    }
                }
                break;
            case 3:
                for(int i = 0; i < qtd_produtos; i++) {
                    printf("%d %s %.2f %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
                }
                break;
            case 4:
                for (int i = 0; i < qtd_produtos-1; i++) {
                    for(int j = 0; j < qtd_produtos - i - 1; j++) {
                        if(produtos[j].preco > produtos[j+1].preco) {
                            Produto temp = produtos[j];
                            produtos[j] = produtos[j+1];
                            produtos[j+1] = temp;
                        }
                    }
                }
                for(int i = 0; i < qtd_produtos; i++) {
                    printf("%d %s %.2f %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
                }
                break;
            case 5:
                free(produtos);
                return 0;
            default:
                printf("Operacao invalida\n");
        }
    }

    return 0;
}