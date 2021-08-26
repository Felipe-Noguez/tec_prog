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

int qtd = 3;
int contador_cadastro=0;
TP_VEICULO cadastrar()
{
    TP_VEICULO car[qtd];
    char resp, continuar;
    int i;
    do
    {
        do
        {            
            printf("Insira a marca do veiculo: ");
            scanf(" %s", &car[i].marca);
            printf("Insira o modelo: ");
            scanf(" %s", &car[i].modelo);
            printf("Insira o ano de fabricacao: ");
            scanf(" %d", &car[i].fabricacao_ano);            
            printf("Insira o numeros da placa: ");
            scanf(" %s", car[i].placa);
            printf("#### Confirmar dados inseridos, digite S/N ####\n");            
            printf("Marca: %s\n", car[i].marca);
            printf("Modelo: %s\n", car[i].modelo);
            printf("Ano de fabricacao: %d\n", car[i].fabricacao_ano);
            printf("Placa do veiculo: %s\n",car[i].placa);
            printf("Confirmar? ");
            scanf(" %s", &resp);
        } while (!resp == 'S');
        i++;
        if(i == qtd)
        {
            printf("Atingido limite maximo de cadastro!");
            break;
        }
        printf("Deseja continuar S/N? ");
        scanf(" %s", &continuar);
    } while (!continuar == 'S');
    return car[qtd];
}

void menu_opcao()
{
    int opt/*, i*/;
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
    TP_VEICULO carros[qtd];
    int i;
    
    menu_opcao();

    for(i=0; i<qtd; i++)
    {
        carros[i] = cadastrar();
    }

    carros[0] = cadastrar();
    for(i=0; i<qtd; i++)
    {
        printf("%s", carros->modelo);
    }

    
    

    //printf("%s", );
    /*for(i=0; i<2; i++)
    {

    }*/

    return 0;
}