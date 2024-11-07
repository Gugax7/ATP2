#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    float nota;
    struct Aluno *p;
}Aluno;

void selection_sort(Aluno *L){
    int size = 0;
    Aluno *lower_index = L;
    Aluno *aux1 = L;
    Aluno *aux2;
    Aluno *who_points_to_lower;
    Aluno *who_points_to_aux2;
    aux2 = L;
    while(aux2 != NULL){
        aux2 = aux2->p;
        size++;
    }
    aux2 = L;
    
    int last_mat = aux2->matricula;
    while(aux1 != NULL){
        aux2 = aux1;
        lower_index = aux1;
        while(aux2 != NULL){
            who_points_to_aux2 = aux2;
            aux2 = aux2->p;
            if(aux2->matricula > lower_index->matricula){
                lower_index = aux2;
                who_points_to_lower = who_points_to_aux2;
            }
        }
        who_points_to_lower->p = lower_index->p;
        lower_index->p = aux1->p;
        aux1->p = lower_index;
        aux1 = aux1->p;
    }
}

void insereFinal(Aluno **L, int mat, float nota){
    Aluno *aux = (Aluno*)malloc(sizeof(Aluno));
    Aluno *aux2;
    aux2 = *L;
    aux->matricula = mat;
    aux->nota = nota;
    aux->p = NULL;
    if(*L == NULL){
        *L = aux;
    }else{
        while(aux2->p){
            aux2 = aux2->p;
        }
        aux2->p = aux;
    }
}

void insereAfter(Aluno *L, int mat, float nota, int before){
    Aluno *aux = (Aluno *)malloc(sizeof(Aluno));
    aux->matricula = mat;
    aux->nota = nota;
    if(L == NULL){
        printf("There is no list");
        return;
    }
    else{
        while(L->matricula != before){
            L = L->p;
        }
        aux->p = L->p;
        L->p = aux;
    }
}


void print_list(Aluno *L){
    while(L){
        printf("mat = %d, nota = %f\n", L->matricula, L->nota);
        L = L->p;
    }
}

int main(){

    int mat;
    float nota;
    Aluno *L;
    L = NULL;

    do{
        printf("Matricula: ");
        scanf("%d", &mat); 
        printf("\nNota: ");
        scanf("%f", &nota); 
        if(mat > 0){
            insereFinal(&L,mat,nota);
        }
    }while(mat >0);
    insereAfter(L,4,6,3);
    selection_sort(L);
    print_list(L);
    return 0;
}