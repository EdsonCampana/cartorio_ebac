#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca para aloca��o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bilioteca responsavel por cuidas das strings

int registrar () //inicio da funcao registra
{	
	
	//inicio da criacao das variaveis/strings
	char arquivo[40]; //variavel para nome do arquivo
	char cpf[40]; //variavel cpf com at� 40 caracteres
	char nome[40]; //varivavel nome com at� 40 caracteres
	char sobrenome[40]; //variavel sobrenome com at� 40 caracteres
	char cargo[40]; //variavel cargo com at� 40 caracteres
	// fim da criacao das variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacoes do usuario
	scanf("%s", cpf); //armazenando a informacao do usuario na variavel cpf (%s refere-se a var�veis do tipo string)
	
	strcpy (arquivo,cpf); //funcao que copia os valores das strings cpf para arquivo
	
	FILE *file; //funcao para criar um arquivo
	file = fopen (arquivo, "w"); //funcao (fopen) refere-se a abrir file com nome "arquivo" com o nome de arquivo e "w" escrever
	file = fopen (arquivo,"a"); //funcao (fopen) refere-se a abrir file com nome "arquivo" e atualizar ("a")
	fprintf (file,cpf); //salva o valor da variavel cpf no file
	fclose (file); //fecha file
	
	file = fopen (arquivo,"a"); //abrir file "arquivo" e atualizar a informa��o
	fprintf (file,";"); //adiciona "," no arquivo
	fclose (file); //fecha o arquivo
	
	printf ("Digite o nome a ser cadastrado: "); //coletando informacoes do nome 
	scanf ("%s", nome); //armazenando as informacoes na variavel nome (%s refere-se a vari�veis do tipo string)
	
	file = fopen (arquivo, "a"); //abrir o file (arquivo) e atualizar ("a");
	fprintf (file,nome); //salvar no file o valor da string nome
	fclose (file);

	file = fopen (arquivo,"a"); //abrir file "arquivo" e atualizar a informa��o
	fprintf (file,";"); //adiciona "," no arquivo
	fclose (file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando as informacoes do sobrenome
	scanf("%s",sobrenome); //armazenando as informacoes da variavel como sobrenome (%s refere-se a vari�veis do tipo string)
	
	file = fopen(arquivo,"a"); //abrir file (arquiv) e atualizar ("a")
	fprintf(file,sobrenome); //salvar no file (arquivo) o valor da string sobrenome
	fclose(file); //fechar o file (arquivo)
	
	file = fopen (arquivo,"a"); //abrir file "arquivo" e atualizar a informa��o
	fprintf (file,";"); //adiciona "," no arquivo
	fclose (file); //fecha o file (arquivo)
	
	printf("Digite o cargo a ser cadastrado: "); //coletando as informacoes do cargo
	scanf("%s", cargo); //aramazenando as informacoes da variavel como cargo (%s refere-se a vari�veis do tipo string)
	
	file = fopen(arquivo,"a"); //abrir file (arquivo) e atualizar ("a")
	fprintf(file,cargo); //salvar no file (arquivo) o valor da string cargo;
	fclose(file); //fechar file (arquivo)
	
	system("pause"); //pausar o systema para visualiza��o do usu�rio
	
}

int consultar () //inicio da funcao consultar
{
	setlocale(LC_ALL, "Portuguese"); //definindo suporte a lingua portuguesa e aos caracteres especiais
	
	//inicio da defini��o de variaveis
	char cpf[40]; //variavel string cpf
	char conteudo[200]; //variavel string conteudo
	char *token; //variavel token armazena temporariamente cada parte da string que est� sendo extra�da pela fun��o 'strtok'
	//termino da definicao de variaveis
	
	printf("Digite o CPF a ser consultado: ");//coletando informacao de CPF com o usuario
	scanf("%s",cpf); //armazenando as informacoes da variave CPF (%s refere-se a vari�veis do tipo string)

	FILE *file; //funcao para arquivos
	file = fopen(cpf,"r"); //funcao para leitura do arquivo que tenha o mesmo nome que a variavel CPF
	
	if(file == NULL) //se a leitura for NULL retorna
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //While (enquanto) tiver informa��o retorna a variavel conteudo
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		
		token = strtok(conteudo, ";"); //funcao 'strtok' � utilizada para dividir a string em linhas segundo a presenca de ";"
		printf("CPF: %s\n", token); 
		
		token = strtok(NULL, ";");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ";");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ";");
		printf("Cargo: %s\n", token);
		
	}
	
	printf("\n\n");
	
	system("pause");
}

int deletar ()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //variavel cpf do tipo string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //recebe a string e armazena a vari�vel cpf do tipo string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema.\n\n");
		system("pause");
	}
	
	else
	{
		fclose (file); //fecha o arquivo aberto
		if (remove(cpf) == 0) //codigo a ser executado se a funcao if for verdadeira
			{
				printf("\nUsu�rio removido com sucesso\n\n");
				system("pause");
			}
		else
			{
				printf("\nFalha ao remover o usu�rio\n\n");
				system("pause");
			}
	}
}	


int main()
{
	int opcao=0; //definindo a vari�vel como 0 para que a resposta seja armazenada na fun��o scanf
	int laco=1; //variavel inteiro
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar os nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//final do menu

		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao) //inicio da selecao do menu
		{
			case 1:
			registrar(); //chamada da funcao registra
			break;
			
			case 2:
			consultar(); //chamada da funcao consulta
			break;
			
			case 3:
			deletar(); //chamada da funcao deletar
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n\n");
			system("pause");
			break;
		}
	
	}
	
}

