#include <stdio.h> //Biblioteca de comunicação do usuário
#include <stdlib.h> //Biblioteca de alocação em memória
#include <locale.h> //Biblioteca de alocaçôes de texto por região
#include <string.h> //Biblioteca responsável por cudiardas strings
int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:\n");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //responsável por copiar valores de uma string
	
	FILE *file;
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome para cadastro:\n");
	scanf("%s",nome);	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Sobrenome para cadastro:\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo para cadastro:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	system("pause");
	
	
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Abara o arquivo e "lê/r" 
	
	if(file == NULL) //Caso seja diferente dos numeros cadastrados, segue a mensagem de erro.
	{
		printf("Sua consulta falhou, tente novamente!!!\n");		
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //Buscando a variavel "char: conteudo[200]" no arquivo "file" // //Caso não ache, é nulo.|"!=":Diferente dê... EX: A!=B
	{
		printf("\nSegue informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF inexistente, tente novamente!!!\n\n");
		system("pause");
		}	
	
	
}

int main()
{
	int opcao=0; //Variável
	int rep=1; //Variavel
	
	for(rep=1;rep=1;) //Repetição
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("\t### Cartório da EBAC ###\n\n"); //Tela Principal do Sistema
    	printf("\t------- MENU -------\n\n"); 
		printf("\tEscolha a opção desejada: \n\n");
		printf("1 - Registrar Nomes\n");
		printf("2 - Consultar Nomes\n");
		printf("3 - Deletar Nomes\n\n"); //Fim do menu
		printf("Digite a opção desejada: "); //Escolha do Usuário
	
		scanf("%d", &opcao); //Amarzenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Volte ao Menu Principal!\n\n");
			system("pause");
			break;
		}
	}
}
	

