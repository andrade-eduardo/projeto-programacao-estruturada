#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    int codigo;
    char nome[20];
    float preco;
    int quantidade;
} Produto;

void adiciona_produto (Produto *produtos, int *qtd_produtos) {

    //aumenta o tamanho do vetor produtos
    produtos = realloc(produtos, *qtd_produtos * sizeof(Produto) + sizeof(Produto));
    if(produtos == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }

    //salva as informacoes do novo produto
    printf("\nDigite nome, preco e quantidade (separados por espaco) do novo produto:\n");
    scanf("%s %f %d", produtos[*qtd_produtos].nome, &produtos[*qtd_produtos].preco, &produtos[*qtd_produtos].quantidade);
    printf("Produto adicionado!\n");

    //adiciona o codigo do novo produto
    produtos[*qtd_produtos].codigo = (*qtd_produtos) + 101;

    //salva a nova quantidade de produtos
    (*qtd_produtos)++;
}

int busca_produto (Produto *produtos, int qtd_produtos) {
    
    //recebe o codigo do produto desejado
    printf("\nDigite o codigo:\n");
    int codigo_digitado;
    scanf("%d", &codigo_digitado);
    
    //realiza uma busca binaria pelo codigo do produto
    int ini = 0;
    int fim = qtd_produtos - 1;
    int meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if(produtos[meio].codigo == codigo_digitado) {
            printf("%s %.2f %d\n", produtos[meio].nome, produtos[meio].preco, produtos[meio].quantidade);
            return 0;
        } else if (produtos[meio].codigo < codigo_digitado) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    //avisa se o codigo digitado nao foi encontrado
    printf("Codigo nao encontrado!\n");
    return 0;
}

void imprime_produtos (Produto *produtos, int qtd_produtos) {
    printf("\n");
    for(int i = 0; i < qtd_produtos; i++) {
        printf("%d %-19s %.2f %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

void ordena_produtos (Produto *produtos, int qtd_produtos) {
    
    //cria uma copia do vetor de produtos para a ordenacao
    Produto produtos_ordenados[qtd_produtos];
    memcpy(produtos_ordenados, produtos, qtd_produtos * sizeof(Produto));

    //ordena os produtos por preco com bubble sort
    Produto temp;
    for (int i = 0; i < qtd_produtos-1; i++) {
        for(int j = 0; j < qtd_produtos - i - 1; j++) {
            if(produtos_ordenados[j].preco > produtos_ordenados[j+1].preco) {
                temp = produtos_ordenados[j];
                produtos_ordenados[j] = produtos_ordenados[j+1];
                produtos_ordenados[j+1] = temp;
            }
        }
    }

    imprime_produtos(produtos_ordenados, qtd_produtos);
}

int main() {

    //abrindo o arquivo produtos.txt
    FILE *arquivo = fopen("produtos.txt", "r");
    if(arquivo == NULL) {
        puts("Erro ao abrir arquivo\n");
        return 1;
    }

    //alocando memoria para o vetor que ira guardar as informacoes dos produtos
    Produto *produtos = malloc(20 * sizeof(Produto));
    if(produtos == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }
    //lendo e salvando as informacoes dos produtos no vetor produtos
    int qtd_produtos = 0;
    while(fscanf(arquivo, "%d %19s %f %d", &produtos[qtd_produtos].codigo, produtos[qtd_produtos].nome, &produtos[qtd_produtos].preco, &produtos[qtd_produtos].quantidade) != EOF){
        qtd_produtos++;
    }
    fclose(arquivo);

    //menu de opcoes
    int opcao;
    while(1) {
        printf("\nDigite a operacao desejada:\n1. Adicionar produto\n2. Buscar produto por codigo\n3. Imprimir produtos\n4. Ordenar por preco e imprimir\n5. Sair\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                adiciona_produto(produtos, &qtd_produtos);
                break;
            case 2:
                busca_produto(produtos, qtd_produtos);
                break;
            case 3:
                imprime_produtos(produtos, qtd_produtos);
                break;
            case 4:
                ordena_produtos(produtos, qtd_produtos);
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