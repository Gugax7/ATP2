#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void find_word(char word[],FILE* file){
    char c;
    int find_lines[1000];
    int i =0;
    int line_counter = 1;
    int char_counter = 0;
    fseek(file,0,SEEK_SET);
    
    while((c = fgetc(file)) != EOF){
        if(c == '\n'){
            line_counter++;
        }
        if(c == word[char_counter]){
            char_counter++;
        }
        else{
            char_counter = 0;
        }
        if(char_counter == strlen(word) - 2){
            find_lines[i] = line_counter;
            i++;
            char_counter = 0;
        }
        printf("\nchar: %c", c);
        
    }
    if(i == 0){
            printf("no words finded");
        }
        else{
            printf("Word finded on lines:");
            for(int j = 0; j < i; j++){
               printf("%i, ",find_lines[j]);
            }
        }
}
//exercise 1
/*int main(){
    FILE* file;
    FILE* file2;
    file = fopen("take.txt","a");
    char name[50];
    for(int i = 0; i < 5; i++){
        printf("Name %i:",i);
        fgets(name,sizeof(name),stdin);
        //strcat(name,"\n");
        fputs(name,file);
    }

    fclose(file);
    file = fopen("take.txt", "r");
    file2 = fopen("give.txt", "w");
    char name2[50];
    char caracter;
    int linha = 1;
    while ((caracter = fgetc(file)) != EOF) {
        if(caracter == '\n'){
            linha++;
        }
        printf("%c", caracter);
        fputc(caracter,file2);
    }
    find_word("Gustavo",file);
    printf("\nlinhas: %i", linha);
    return 0;
}
*/

typedef struct{
    char nome[1024];
    float nota;
    int idade;
}Aluno;



int main(){
    
    FILE* file_bin; //arq binario
    file_bin = fopen("studants.bin", "ab"); //a =append(escreve embaixo) b=binary
    int escolha;
    //Menu
    printf("Escolha uma opção:\n\nAdicionar aluno - 1\nBuscar aluno - 2\nListar alunos - 3");
    scanf("%i", &escolha);
    switch(escolha){
        int student_count = 0;
        Aluno aluno;
        char busca[1024];
        case 1: printf("NOME:"); scanf("%s",aluno.nome);  
                printf("\nIDADE:"); scanf("%i",&aluno.idade);
                printf("\nNOTA:"); scanf("%f",&aluno.nota);
                fwrite(&aluno,sizeof(Aluno),1,file_bin);
                student_count++;
                break;
        case 2: printf("por qual aluno deseja buscar?: "); scanf("%s", busca);
                fclose(file_bin);
                file_bin = fopen("studants.bin","rb");
                //for(int i = 0; i<student_count;i++){
                    fread(&aluno,sizeof(Aluno),1,file_bin);
                    if(strcmp(aluno.nome,busca)){
                        //printf("i find a name like this on line %i", i);
                    }
                //}
        break;
        case 3: 
        //for(int i = 0; i<student_count;i++){
                    fread(&aluno,sizeof(Aluno),1,file_bin);
                    printf("Nome: %s -- Idade: %i -- Nota: %f",aluno.nome, aluno.idade, aluno.nota);
                //}
        break;
        default: printf("Tendi nn meu fi");

    }

    return 0;
}