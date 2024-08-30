#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int numMat;
  char nome[1024];
  struct regFunc *p;
} regFunc;

void InsereInic(struct regFunc **L, int x, char str[]) {
  regFunc *aux;
  aux = (regFunc *)malloc(sizeof(regFunc));
  aux->numMat = x;
  strcpy(aux->nome, str);
  aux->p = *L;
  *L = aux;
}
void insereFinal(regFunc **L, int x, char str[]) {
  regFunc *aux = (regFunc *)malloc(sizeof(regFunc));
  regFunc *aux2;
  aux2 = *L;
  aux->numMat = x;
  strcpy(aux->nome, str);
  aux->p = NULL;
  	if(aux2 == NULL){
		*L = aux;
	} else {
    while (aux2->p) {
      aux2 = aux2->p;
    }
    aux2->p = aux;
  }
}

void insereAfter(regFunc **L, int x, char str[], int previous){
  regFunc *aux = (regFunc *)malloc(sizeof(regFunc));
  strcpy(aux->nome,str);
  aux->numMat = x;
  regFunc *aux2;
  aux2 = *L;
  if(!aux2){
    aux->p = *L;
    *L = aux;
    return;
  }

    while(aux2->numMat != previous && aux2->p != NULL){
      aux2 = aux2->p;
    }
    aux->p = aux2->p;
    aux2->p = aux;

}
void print_list(regFunc *L) {
  while (L) {
    printf("%d %s\n", L->numMat, L->nome);
    L = L->p;
  }
}
int main() {
  regFunc *list = NULL;
  char nome[1024]; int i = 1;
 	while(i <= 10){
  	printf("Print the name of student: ");
  	scanf("%s", nome);
  	insereFinal(&list,i,nome);
  	i++;
  }
	print_list(list);

  insereAfter(&list,15,"Elizabeth",7);
  print_list(list);
return 0;
}
