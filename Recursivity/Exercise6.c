#include <stdio.h>
#include <stdlib.h>

int fibonacci(int nd, int n1, int n2){
    if(nd == 1){
        return n1;
    }
    return fibonacci(nd-1,n2,n1+n2);
}

int main(){
    for(int i = 1; i < 20; i++){
    printf("%i\n", fibonacci(i,0,1));
    }
    return 0;
}