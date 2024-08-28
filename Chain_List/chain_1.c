#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct no {
  int value;
  struct no *next;
} No;

void insere_begin(No **L, int value){
    No *aux = (No*)malloc(sizeof(No));
    aux->value = value;
    aux->next = *L;
    *L = aux;
}
void print_list(No *list){
    No *aux = list;
    while(aux){
    printf("%d ", aux->value);
    aux = aux->next;
    }   
}

int main() {
  No *list = NULL;
  

  insere_begin(&list, 10);
  insere_begin(&list, 9);
  insere_begin(&list, 8);
  insere_begin(&list, 7);
  insere_begin(&list, 6);

  print_list(list);


  return 0;
}