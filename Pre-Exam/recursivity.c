#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_reverse(int array[], int left, int right){
    if(right <= left) return;
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
    array_reverse(array, left+1,right-1);
}

int number_count(long number, int tofind){
    if(number == 0)return 0;
    return number_count(number/10, tofind) + (number % 10 == tofind);
}

int binary_change(int number){
    if(number == 0) return 0;
    return 10*binary_change(number/2) + (number % 2);
}

int mdc(int x, int y){
    if(x == y) return x;
    if(y>x){
        return mdc(y,x);
    }
       return mdc(x-y,y);
}

int mod(int num, int div){
    if(num < div) return num;
    if(num == div) return 0;
    return mod(num - div, div);
}

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {  // Caso base: apenas um disco para mover
        printf("Mover disco 1 da torre %c para a torre %c\n", origem, destino);
        return;
    }

    // Move n-1 discos da torre origem para a torre auxiliar
    hanoi(n - 1, origem, auxiliar, destino);

    // Move o disco restante da torre origem para a torre destino
    printf("Mover disco %d da torre %c para a torre %c\n", n, origem, destino);

    // Move os n-1 discos da torre auxiliar para a torre destino
    hanoi(n - 1, auxiliar, destino, origem);
}
