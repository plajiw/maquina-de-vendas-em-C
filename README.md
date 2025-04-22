# Anotações Técnicas - Projeto Máquina de Vendas

**Objetivo**:
Este documento reúne anotações, explicações e trechos de código relacionados ao desenvolvimento de uma aplicação em C simulando uma "máquina de vendas". O estudo foi conduzido com base no repositório [maquina-de-vendas](https://github.com/dionisioedu/maquina-de-vendas) criado por [@dionisioedu](https://github.com/dionisioedu), e tem como foco a revisão e fixação de conceitos fundamentais da linguagem C.

## Uso do sizeof

**Conceito**:
O operador sizeof em C é utilizado para determinar, em tempo de compilação, o tamanho em bytes de um tipo de dado ou de uma variável. Isso é útil para manipulação de memória, alocação dinâmica e para calcular a quantidade de elementos em arrays.

Quando aplicado a uma variável ou struct, sizeof retorna o espaço que essa entidade ocupa na memória. Quando aplicado a um array, retorna o tamanho total ocupado pelo array, considerando todos os seus elementos.

Exemplos:

```c
#include <stdio.h>

typedef struct {
    char name[20];
    float preco;
    int estoque;
} Produto;

int main() {
    Produto itens[] = {
        {"Refrigerante", 6.0, 10},
        {"Chocolate", 4.0, 20},
        {"Salgadinho", 5.0, 10},
    };

    printf("sizeof(Produto): %lu bytes\n", sizeof(Produto));
    printf("sizeof(itens): %lu bytes\n", sizeof(itens));
    printf("Quantidade de produtos: %lu\n", sizeof(itens) / sizeof(Produto));

    return 0;
}
```
**Explicação**:

A struct Produto possui três membros: um array de char com 20 posições, um float e um int. No sistema em questão, ela ocupa 28 bytes de memória, sem adição de padding (ajuste de alinhamento).

O array itens contém 3 elementos do tipo Produto. Ao aplicar sizeof(itens), obtemos o tamanho total em bytes ocupado pelo array: 3 × 28 = 84 bytes.

Para descobrir quantos elementos existem no array, divide-se o tamanho total pelo tamanho de um único elemento:

```c
sizeof(itens) / sizeof(Produto) // 84 / 28 = 3
```

## Uso de Ponteiros como Parâmetro em Funções (`inserirSaldo`)

**Conceito**:
Ao utilizar ponteiros como parâmetro em funções, é possível acessar e modificar diretamente o conteúdo de variáveis definidas fora do escopo da função. Isso é feito por meio da passagem do endereço da variável, permitindo alterações permanentes no valor original.

Exemplos:

```c
void inserirSaldo(float *saldo) {
    *saldo += 10.0f;
}

// Chamada da função no main
inserirSaldo(&saldo);
```

```c
#include <stdio.h>

void inserirSaldo(float *saldo) {
    *saldo += 10.0f;
}

int main() {
    float saldo = 0.0f;
    inserirSaldo(&saldo);
    printf("Saldo final: %.2f\n", saldo);  // Saída: 10.00
    return 0;
}
```

**Explicação**:
A função `inserirSaldo` recebe como parâmetro um ponteiro para float, ou seja, um endereço de memória que aponta para uma variável do tipo float.

Ao chamarmos a função com `inserirSaldo(&saldo);`, o que está sendo passado como argumento é o endereço da variável saldo, e não uma cópia do seu valor.

Dentro da função, o operador * (desreferenciação) permite acessar o valor contido no endereço recebido. Assim, ao executar *saldo += 10.0f;, estamos modificando diretamente o valor armazenado no endereço da variável saldo.

Essa abordagem permite que a função `inserirSaldo` modifique diretamente o conteúdo da variável saldo, mesmo ela tendo sido declarada fora da função. Isso ocorre porque a função opera sobre o endereço de memória da variável original, e não sobre uma cópia local.

Ou seja, a função `inserirSaldo` possui como parâmetro um ponteiro para uma variável de determinado tipo (por exemplo, float*). Esse ponteiro recebe o endereço de uma variável do mesmo tipo fornecido no momento da chamada da função. Dentro da função, o ponteiro permite acessar e modificar diretamente o conteúdo da variável original, utilizando o operador de desreferenciação (*).

