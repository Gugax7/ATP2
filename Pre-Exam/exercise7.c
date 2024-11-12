#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    float nota;
    struct Aluno *p;
}Aluno;


void selection_sort(Aluno **L){
    Aluno *aux1 = *L;
    Aluno *current;
    Aluno *lower_index;
    Aluno *prev_lower;
    Aluno *prev_aux1 = NULL;
    Aluno *prev;

    while(aux1 && aux1->p){
        lower_index = aux1;
        prev = aux1;
        current = prev->p;
        prev_lower = prev_aux1;
        while(current){
            if(current->matricula < lower_index->matricula){
                lower_index = current;
                prev_lower = prev;
            }
            prev = current;
            current = prev->p;
        }
        if(lower_index != aux1){
            if(aux1 != *L){
                prev_aux1->p = lower_index;
            }
            else{
                *L = lower_index;
            }
            prev_lower->p = aux1;
            Aluno *temp = lower_index->p;
            lower_index->p = aux1->p;
            aux1->p = temp;
        }
        prev_aux1 = lower_index;
        aux1 = lower_index->p;
    }
} 

/*void selection_sort(Aluno **L) {
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
}*/

void bubble_sort(Aluno **L){
    if(L == NULL || *L == NULL) return;

    int swapp = 1;
    while(swapp == 1){
    Aluno *aux1;
    Aluno *prev_aux1 = *L;
    Aluno *prev_prev;
    aux1 = prev_aux1->p;
    swapp = 0;

        while(aux1 != NULL){
                if(aux1->matricula < prev_aux1->matricula){
                    if(*L == prev_aux1){
                        prev_aux1->p = aux1->p;
                        aux1->p = prev_aux1;
                        *L = aux1;
                    }
                    else{
                        prev_prev->p = aux1;
                        prev_aux1->p = aux1->p;
                        aux1->p = prev_aux1;
                    }
                    swapp = 1;
                }
            prev_prev = prev_aux1;
            prev_aux1 = aux1;
            aux1 = aux1->p;
        }
    }
}

/*

void bubble_sort(Aluno **L) {
    if (L == NULL || *L == NULL) return; // Check if the list is empty or NULL
    
    int swapped;
    Aluno *current;
    Aluno *prev = NULL;
    Aluno *next = NULL;

    do {
        swapped = 0; // Reset the swapped flag to detect if any swap happens in this pass
        current = *L;

        while (current != NULL && current->p != NULL) {
            next = current->p;

            // Compare the values of current and next node
            if (current->matricula > next->matricula) {
                // Swap the nodes: current and next

                // If current is the head, change the head pointer
                if (current == *L) {
                    *L = next;
                }

                // Swap the next pointers
                current->p = next->p;
                next->p = current;

                // Adjust the previous node's p to point to the new first node
                if (prev != NULL) {
                    prev->p = next;
                }

                // Mark that a swap has occurred
                swapped = 1;
            }

            // Move prev and current pointers one step forward
            prev = current;
            current = current->p;
        }

        // If no swaps were made, the list is sorted
    } while (swapped);  // Keep iterating until no more swaps occur
}

*/

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

    insereFinal(&L,3,0);
    insereFinal(&L,9,2);
    insereFinal(&L,10,3);
    insereFinal(&L,1,4);
    insereFinal(&L,5,5);
    insereFinal(&L,4,6);
    insereFinal(&L,2,7);
    insereFinal(&L,6,8);
    insereFinal(&L,7,9);
    //insereAfter(L,4,6,3);
    selection_sort(&L);
    print_list(L);
    return 0;
}