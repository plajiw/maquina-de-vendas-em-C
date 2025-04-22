#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    float preco;
    int estoque;
} Produto;

// Determinar o valor do saldo do usuário
void inserirSaldo(float *saldo)
{
    float notas[] = {2.0f, 5.0f, 10.0f, 20.0f, 50.0f, 100.0f};

    // Obter quantidade de notas dinamicamente
    int quantidade_de_notas = sizeof(notas) / sizeof(float);

    for (int i = 0; i < quantidade_de_notas; i++)
    {
        printf("[%d] - R$%2.f\n", i + 1, notas[i]);
    }

    printf("Escolha uma nota para inserir: ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 0)
    {
        return;
    }

    else if (opcao >= 1 && opcao <= quantidade_de_notas)
    {
        *saldo += notas[opcao - 1];
    }

    else
    {
        printf("Opção inválida!\n");
    }
}

void exibirProdutos(Produto *maquina[], int tamanho, float saldo)
{
    printf("\n=== Máquina de Vendas ===\n\n");

    printf("%-3s %-15s %-10s %s\n", "#", "Produto", "Preço", "Estoque");
    printf("-----------------------------------------\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("[%d] %-15s R$%-9.2f %d\n",
               i + 1,
               maquina[i]->name,
               maquina[i]->preco,
               maquina[i]->estoque);
    }

    printf("\nSaldo atual: R$%.2f\n\n", saldo);

}

int main()
{
    Produto itens[] = {
        {"Refrigerante", 6.0, 10},
        {"Chocolate", 4.0, 20},
        {"Salgadinho", 5.0, 10},
        {"Suco", 6.0, 8},
    };

    // Obter quantidade de produtos dinamicamente
    // Evita-se "magic number"
    const int PRODUTOS_QTD = sizeof(itens) / sizeof(Produto);

    Produto *maquina[PRODUTOS_QTD];

    for (int i = 0; i < PRODUTOS_QTD; i++)
    {
        maquina[i] = &itens[i];
    }

    float saldo = 0.0f;

    int opcao = -1;

    while (opcao != 0)
    {
        inserirSaldo(&saldo);
        exibirProdutos(maquina, PRODUTOS_QTD, saldo);

        scanf("%d", &opcao);
    }

    return 0;
}