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
Cad_veiculo veiculos[2], menor, aux, filtro_ano, filtro_modelo;

void imprimirVeiculo(Cad_veiculo car)
{
	printf("Marca: %s\n", car.marca);
	printf("Modelo: %s\n", car.modelo);
	printf("Ano de fabricação: %d\n", car.fabricacao_ano);
	printf("Placa: %s\n", car.placa);
}

//int qtd = 2;
Cad_veiculo cadastrar()
{
    //int i, opt;
    Cad_veiculo car;
    int i, j, opt, pos_menor;
    
	printf("Insira a marca do veiculo: ");
	scanf(" %s",car.marca);
	
	printf("Insira o modelo: ");
	scanf(" %s",car.modelo);
	
	printf("Insira o ano de fabricação: ");
	scanf(" %d", &car.fabricacao_ano);
	
	printf("Insira a placa: ");
	scanf(" %s", &car.placa);
		
	return car;    
}



void menu_opcao()
{
    int opt , i;
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
            for (i = 0; i < 2; i++)
    			imprimirVeiculo(veiculos[i]);
            break;
        case 2:
            cadastrar();
            for(i = 0; i < 2; i++){
		        veiculos[i] = cadastrar();		
	        }
        int pos_menor, j;
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
            break;
        case 3:
        	for (i = 0; i < 2; i++)
    			imprimirVeiculo(veiculos[i]);
    		break;
    	case 4:
    		printf("Entre com o ano de fabricação: ");
    		scanf(" %d", &filtro_ano.fabricacao_ano);
    		for(i=0; i<2; i++){
				if(filtro_ano.fabricacao_ano == veiculos[i].fabricacao_ano)
				{
					printf("Resultado:\n");
					printf("Marca: %s\n", veiculos[i].marca);
					printf("Modelo: %s\n", veiculos[i].modelo);
					printf("Ano de fabricação: %d\n", veiculos[i].fabricacao_ano);
					printf("Placa: %s", veiculos[i].placa);
				}else
				{
					printf("Nenhum veículo cadastrado com este ano de fabricação!\n");
				}
			}
    		break;
    	case 5:
    		printf("Pesquise por modelo: ");
    		scanf(" %s", &filtro_modelo.modelo);
    		for(i=0; i<2; i++){
				if(filtro_modelo.modelo == veiculos[i].modelo)
				{
					printf("Resultado:\n");
					printf("Marca: %s\n", veiculos[i].marca);
					printf("Modelo: %s\n", veiculos[i].modelo);
					printf("Ano de fabricação: %d\n", veiculos[i].fabricacao_ano);
					printf("Placa: %s", veiculos[i].placa);
				}else
				{
					printf("Nenhum veículo cadastrado com este MODELO!\n");
				}
			}
			break;
        default:
            printf("Opcao invalida, digite novamente.");
            break;
        }
    } while (opt == 6);
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
    
    

    
	int i, j, opt, pos_menor;
    do
	{
		menu_opcao();
		printf("Deseja retornar para o menu, 0=Sim, 1= sair? ");		
		scanf(" %d", &opt);				
		i++;
	} while(opt <= 0);

   
    
    return 0;
}