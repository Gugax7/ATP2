#include <stdio.h>
#include <string.h>
struct Aluno{
	char nome[50];
	int idade;
	float nota;
};
	
int main(){
	FILE* file = fopen("arquivo.bin", "ab");
	int num_alun = 0;
	int i;
	struct Aluno aluno[1024];
	printf("Escreva qual posiçao do aluno:");
	scanf("%i", &i);
	printf("\nEscreva o nome do aluno:");
	scanf("%s", aluno[i].nome);
	printf("\nEscreva a idade do aluno:");
	scanf("%i", &aluno[i].idade);
	printf("\nEscreva a nota do aluno:");
	scanf("%f", &aluno[i].nota);
	
	
	fprintf(file,"%s %i %f\n", aluno[i].nome, aluno[i].idade, aluno[i].nota);
	
	fclose(file);
	file = fopen("arquivo.bin", "rb");
	char str[1024];
	fread(str,sizeof(str),1,file);
	//fgets(str, sizeof(str), file);
	printf("%s", str);
	
	return 0;
}
