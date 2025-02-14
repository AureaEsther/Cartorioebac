# include <stdio.h> // biblioteca de comunica��o com o usu�rio
# include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
# include <locale.h> // biblioteca de aloca��o de texto por regi�o
# include <string.h> // biblioteca respons�vel pelas strings

int registrar()
{	

	setlocale(LC_ALL, "Portuguese");

	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE * file; // chama a fun��o de criar arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}



int consultar()
{	

	setlocale(LC_ALL, "Portuguese");

	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{	
	
		printf("N�o localizado. Tente novamente. \n");
	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
		system("pause");
		
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{ 
		printf("Usu�rio n�o localizado! \n");
		system("pause");
		
	}
	
}
	





int main()

{ 
    int opcao = 0;
    int laco = 1; 
    
    for(laco=1;laco=1;)
    {
	
		system("cls");
		
        setlocale(LC_ALL, "Portuguese");

		printf(" ##### CART�RIO DA EBAC #### \n\n");
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Op��o:");
	
		scanf("%d", &opcao); // permite a entrada de dados pelo usu�rio 
	
		system("cls"); // limpa as informa��es da tela quando o programa � encerrado
		 
		switch(opcao)
		{
			
			case 1:
			registrar ();
			break;
			
			case 2:
			consultar ();
    		break;
    		
    		case 3:
    		deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			
			default:
			printf("Op��o inv�lida\n");
			system("pause");
			break;	
		}	
	}
}



