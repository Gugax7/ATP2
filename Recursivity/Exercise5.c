#include <stdio.h>
#include <stdlib.h>

int prime_or_not(int n,int n_hold){
    n = n-1;
    if(n == 0){
       // printf("No")
       return 0;
    }
    if(n == 1){
        //printf("Yes");
        return 1;
    }
    if(n_hold % n == 0){
        //printf("No");
        return 0;
    }
    return prime_or_not(n,n_hold);
}


int main(){

    for(int i = 1; i < 100; i++){
        if(prime_or_not(i,i) == 1){
            printf("%d\n", i);
        }
    }
    
    return 0;
}