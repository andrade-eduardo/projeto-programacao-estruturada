# Projeto - Programação Estruturada
Projeto para armazenamento e controle de produtos.

## Compilação
Para compilar o programa, utilize gcc no terminal:

```bash
gcc main.c -o main
```

## Execução
Para executar o programa:

```bash
./main
```

## Uso
Ao ser executado o programa exibe o menu de opções abaixo. Para realizar uma operação, digite o número da opção desejada.

```bash
1. Adicionar produto
2. Buscar produto por codigo
3. Imprimir produtos
4. Ordenar produtos por preco e imprimir
5. Sair
```

Ao escolher a opção 1, insira o nome, preço e quantidade do novo produto, separadas por espaço. Exemplo:

```bash
Pipoca 3.5 8
```

Ao escolher a opção 2, insira o código do produto que deseja buscar. Exemplo:
```bash
122
```

Ao escolher a opção 3, a lista completa de produtos será impressa na tela, ordenados pelo código. Exemplo:
```bash
101 Arroz               5.49 20
102 Feijao              8.90 15
103 Macarrao            4.25 12
104 Leite               6.50 10
105 Cafe                14.99 8
106 Acucar              3.75 25
107 Oleo                7.29 18
108 Manteiga            10.50 6
109 Queijo              25.00 4
110 Presunto            19.80 5
111 Sabonete            2.99 30
112 Shampoo             15.50 7
113 Detergente          3.20 20
114 Esponja             1.50 25
115 Sal                 2.10 40
116 Vinagre             4.40 9
117 Farinha             5.10 16
118 Biscoito            6.90 11
119 Cereal              12.00 8
120 Refrigerante        8.99 14
```

Ao escolher a opção 4, a lista completa de produtos será impressa na tela, ordenados pelo preço. Exemplo:
```bash
114 Esponja             1.50 25
115 Sal                 2.10 40
111 Sabonete            2.99 30
113 Detergente          3.20 20
106 Acucar              3.75 25
103 Macarrao            4.25 12
116 Vinagre             4.40 9 
117 Farinha             5.10 16
101 Arroz               5.49 20
104 Leite               6.50 10
118 Biscoito            6.90 11
107 Oleo                7.29 18
102 Feijao              8.90 15
120 Refrigerante        8.99 14
108 Manteiga            10.50 6
119 Cereal              12.00 8
105 Cafe                14.99 8
112 Shampoo             15.50 7
110 Presunto            19.80 5
109 Queijo              25.00 4
```

Ao escolher a opção 5, o programa é encerrado.
