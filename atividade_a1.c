#include <stdio.h>
#include <stdlib.h>



/*typedef struct placa_veiculo
{
    int placa_numero;
    char placa_letra[5];
}TP_PLACA; */

typedef struct veiculo
{
    char marca[18];
    char modelo[30];
    int fabricacao_ano;
    char placa[8];
}TP_VEICULO;


int contador_cadastro=0;
void cadastrar()
{
    TP_VEICULO car;
    char resp, continuar;
    int i;
    do
    {
        do
        {            
            printf("Insira a marca do veiculo: ");
            scanf(" %s", &car.marca);
            printf("Insira o modelo: ");
            scanf(" %s", &car.modelo);
            printf("Insira o ano de fabricacao: ");
            scanf(" %d", &car.fabricacao_ano);            
            printf("Insira o numeros da placa: ");
            scanf(" %s", car.placa);
            printf("#### Confirmar dados inseridos, digite S/N ####\n");            
            printf("Marca: %s\n", car.marca);
            printf("Modelo: %s\n", car.modelo);
            printf("Ano de fabricacao: %d\n", car.fabricacao_ano);
            printf("Placa do veiculo: %d - %s\n",car.placa);
            printf("Confirmar? ");
            scanf(" %s", &resp);
        } while (!resp == 'S');
        contador_cadastro++;
        printf("Deseja continuar S/N? ");
        scanf(" %s", &continuar);
    } while (continuar == 'S');
}

void menu_opcao()
{
    int opt, i;
    do
    {
        printf(
        "1 - Listar veiculo.\n"
        "2 - Cadastrar veiculo.\n"
        "3 - Listar veiculos por ano de fabricao.\n"
        "4 - Filtrar por ano.\n"
        "5 - Listar veiculos por modelo:\n"
        "6 - Sair.\n"
        "Escolha uma opcao: "
        );
        scanf(" %d", &opt);

        switch (opt)
        {
        case 1:
            //listar_carros();
            break;
        case 2:
            cadastrar();
            break;        
        default:
            printf("Opcao invailda, digite novamente.");
            break;
        }
    } while (opt == 6);
}

int main()
{
    TP_VEICULO *carros[11];
    int i;
    
    menu_opcao();
    for(i=0; i<11; i++)
    {
        if(carros[i] == !NULL)
        {
            cadastrar();
            printf("Cadastrado com sucesso! ");
        }
        else
        {
            printf("ERRO, capacidade excedida! ");
            break;
        }
    }

    
    

    //printf("%s", );
    /*for(i=0; i<2; i++)
    {

    }*/

    return 0;
}