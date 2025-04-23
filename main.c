#include <stdio.h>
#include <stdlib.h>

#ifdef WINDOWS
#define CLEAR "cls"

#else
#define CLEAR "clear"

#endif

// Estrutura de Produto
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

    printf("\n=== Inserir Saldo ===\n");
    for (int i = 0; i < quantidade_de_notas; i++)
    {
        printf("[%d] - R$%2.f\n", i + 1, notas[i]);
    }

    printf("[0] - Cancelar\n");
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
        printf("Saldo atualizado: R$%.2f\n", *saldo);
    }

    else
    {
        printf("Opção inválida!\n");
    }

    getchar(); // Limpa buffer do scanf
    printf("Pressione ENTER para continuar...");
    getchar();
}

void exibirProdutos(Produto *maquina[], int tamanho)
{
    printf("\n=== Produtos Disponíveis ===\n\n");
    printf("%-3s %-15s %-10s %s\n", "#", "Produto", "Preço", "Estoque");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("[%d] %-15s R$%-9.2f %d\n",
               i + 1, maquina[i]->name, maquina[i]->preco, maquina[i]->estoque);
    }
    printf("--------------------------------------------------\n");
}

void venderProduto(Produto *produto, float *saldo)
{
    if (produto->estoque <= 0)
    {
        printf("Produto esgotado!\n");
    }

    else if (*saldo < produto->preco)
    {
        printf("Saldo insuficiente para comprar %s.\n", produto->name);
    }

    else
    {
        produto->estoque--;
        *saldo -= produto->preco;
        printf("Você comprou um(a) %s!\n", produto->name);
        printf("Saldo restante: R$%.2f\n", *saldo);
    }

    getchar(); // limpa buffer
    printf("Pressione ENTER para continuar...");
    getchar();
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
    Produto *maquina[PRODUTOS_QTD];

    for (int i = 0; i < PRODUTOS_QTD; i++)
    {
        maquina[i] = &itens[i];
    }

    float saldo = 0.0f;
    int opcao = -1;

    while (opcao != 0)
    {
        system(CLEAR);
        printf("=== Máquina de Vendas ===\n");
        printf("Saldo atual: R$%.2f\n", saldo);
        printf("\n[1] Inserir saldo");
        printf("\n[2] Comprar produto");
        printf("\n[0] Sair\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            inserirSaldo(&saldo);
            break;

        case 2:
            system(CLEAR);
            exibirProdutos(maquina, PRODUTOS_QTD);
            printf("\nEscolha o número do produto (0 para cancelar): ");
            int escolha;
            scanf("%d", &escolha);

            if (escolha == 0)
            {
                break;
            }

            if (escolha >= 1 && escolha <= PRODUTOS_QTD)
            {
                venderProduto(maquina[escolha - 1], &saldo);
            }

            else
            {
                printf("Opção inválida.\n");
                getchar();
                printf("Pressione ENTER para continuar...");
                getchar();
            }

            break;

        case 0:
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("Opção inválida.\n");
            getchar();
            printf("Pressione ENTER para continuar...");
            getchar();
            break;
        }
    }

    return 0;
}
