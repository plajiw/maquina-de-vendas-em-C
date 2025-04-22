#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    float preco;
    int estoque;
} Produto;

void inserirSaldo(float *saldo)
{
    *saldo += 10.0f;
}

int main()
{
    Produto itens[] = {
        {"Refrigerante", 6.0, 10},
        {"Chocolate", 4.0, 20},
        {"Salgadinho", 5.0, 10},
        {"Suco", 6.0, 8},
    };

    const int PRODUTOS_QTD = sizeof(itens) / sizeof(Produto);

    Produto *
        maquina[PRODUTOS_QTD];

    for (int i = 0; i < PRODUTOS_QTD; i++)
    {
        maquina[i] = &itens[i];
    }

    float saldo = 0.0f; // 0x909371928

    int opcao = -1;

    while (opcao != 0)
    {
        inserirDinheiro(&saldo);
        printf("Saldo R$%.2f\n", saldo);

        scanf("%d", &opcao);
    }

    return 0;
}