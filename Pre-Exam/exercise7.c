#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    float nota;
    struct Aluno *p;
}Aluno;

/*void selection_sort(Aluno **L){
    Aluno *lower_index;
    Aluno *aux1 = *L;
    Aluno *aux2;
    Aluno *who_points_to_lower;
    Aluno *who_points_to_aux2;
    
    while(aux1 != NULL){
        aux2 = aux1;
        lower_index = aux1;
        printf("\ncurrent aux1: %d", aux1->matricula);
        while(aux2 != NULL){
            who_points_to_aux2 = aux2;
            aux2 = aux2->p;
            printf("\ncurrent aux2: %d", aux2->matricula);
            if(aux2->matricula < lower_index->matricula){
                lower_index = aux2;
                who_points_to_lower = who_points_to_aux2;
                printf("\nwho points to lower: %d", who_points_to_lower->matricula);
                printf("\ncurrent lower: %d", lower_index->matricula);
            }
        }
        
        printf("\nwho points to lower: %d", who_points_to_lower->matricula);
        printf("\naux1: %d", aux1->matricula);
        who_points_to_lower->p = lower_index->p;
        lower_index->p = aux1;
        if(lower_index == aux1){
            aux1 = aux1->p;
        }
        if(aux1 == *L){
            *L = lower_index;
        }
        printf("points changed");
    }
}*/

void selection_sort(Aluno **L) {
    if (L == NULL || *L == NULL) return; // Check for an empty list

    Aluno *aux1 = *L;
    Aluno *prev_aux1 = NULL;

    while (aux1 != NULL && aux1->p != NULL) {
        Aluno *lower_index = aux1;
        Aluno *prev_lower = prev_aux1;
        Aluno *aux2 = aux1->p;
        Aluno *prev_aux2 = aux1;

        // Find the minimum node in the unsorted portion of the list
        while (aux2 != NULL) {
            if (aux2->matricula < lower_index->matricula) {
                lower_index = aux2;
                prev_lower = prev_aux2;
            }
            prev_aux2 = aux2;
            aux2 = aux2->p;
        }

        // If the minimum node is not the current node, swap them
        if (lower_index != aux1) {
            if (prev_aux1 != NULL) {
                prev_aux1->p = lower_index;
            } else {
                *L = lower_index;
            }

            prev_lower->p = aux1;

            // Swap the next pointers
            Aluno *temp = lower_index->p;
            lower_index->p = aux1->p;
            aux1->p = temp;
        }

        // Move `aux1` and `prev_aux1` forward
        prev_aux1 = lower_index;
        aux1 = lower_index->p;
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
    //insereAfter(L,4,6,3);
    selection_sort(&L);
    print_list(L);
    return 0;
}