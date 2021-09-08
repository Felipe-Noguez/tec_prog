#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



typedef struct
{
    char marca[18];
    char modelo[30];
    int fabricacao_ano;
    char placa[8];
}Cad_veiculo;

void imprimirVeiculo(Cad_veiculo car)
{
	printf("Marca: %s\n", car.marca);
	printf("Modelo: %s\n", car.modelo);
	printf("Ano de fabricação: %d\n", car.fabricacao_ano);
}

int qtd = 2;
Cad_veiculo cadastrar()
{
    //int i, opt;
    Cad_veiculo car;
    
    
	printf("Insira a marca do veiculo: ");
	scanf(" %s",car.marca);
	
	printf("Insira o modelo: ");
	scanf(" %s",car.modelo);
	
	printf("Insira o ano de fabricação: ");
	scanf(" %d", &car.fabricacao_ano);
	
	
	
	return car;    
}

void menu_opcao()
{
    int opt /*, i*/;
    do
    {
        printf(
            "1 - Listar veiculo.\n"
            "2 - Cadastrar veiculo.\n"
            "3 - Listar veiculos por ano de fabricao.\n"
            "4 - Filtrar por ano.\n"
            "5 - Listar veiculos por modelo:\n"
            "6 - Sair.\n"
            "Escolha uma opcao: ");
        scanf("%d", &opt);

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
	setlocale(LC_ALL, "Portuguese");
    Cad_veiculo veiculos[2], menor, aux;
    

    
	int i, j, opt, pos_menor;
    /*do
	{
		menu_opcao();
		//printf("Confirmar os dados cadastrados?\nDigite 1 para confirmar ou 0 para corrigir");
		//scanf("%d", &opt);
		veiculos[i] = cadastrar();
		printf("Deseja retornar para o menu, 0=Sim, 1= sair? ");		
		scanf("%d", &opt);
		printf("\n%d\n",opt);				
		i++;
	} while(opt <= 0);*/
	menu_opcao();
	
	for(i = 0; i < 2; i++){
		veiculos[i] = cadastrar();		
	}
	
	for(i=0; i<2; i++){
        //veiculos[i] = cadastrar();
        menor.fabricacao_ano = veiculos[i].fabricacao_ano;
        pos_menor = i;
        for(j = i+1; j < 2; j++){
            if(veiculos[j].fabricacao_ano < menor.fabricacao_ano){
                veiculos[j] = veiculos[j];
                pos_menor = j;
            }
        }
        if(pos_menor != i){
            aux = veiculos[i];
            veiculos[i] = veiculos[pos_menor];
            veiculos[pos_menor] = aux;
        }        
    }

   
    for (i = 0; i < 2; i++)
    	imprimirVeiculo(veiculos[i]);

    
    

    return 0;
}