#include <stdio.h>
#include <stdlib.h>

void reverse(int *n, int reverted_n){
    reverted_n += (*n % 10);
    *n = *n/10; //printf("n = %d", *n);
    if(*n > 0){
        reverted_n = reverted_n * 10;
        //printf("reverted_n = %d", reverted_n);
        reverse(n,reverted_n);
    }
    else{
        *n = reverted_n;
    }
}

void decompose(int n){
    int current = n % 10;
    n = n / 10;
    printf("%i ", current);
    if(n > 0){
        decompose(n);
    }
}

int main(){
    int n;
    printf("Please type the number:");
    scanf("%i", &n);
    reverse(&n, 0);
    decompose(n);

    return 0;
}