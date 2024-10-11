#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char origem, char destino, char auxiliar){
    printf("\n-----Origem = %c, Destino = %c, Auxiliar = %c---------", origem,destino,auxiliar);
    if(n == 1){
        printf("\nMove disc 1 from base %c to base %c", origem, destino);
        return;
    }
    hanoi(n-1, origem, auxiliar,destino);
    printf("\nMove disc %d from base %c to base %c",n,origem,destino);
    hanoi(n-1,auxiliar,destino,origem);
}

int main(){

    hanoi(3,'A','B','C');

}