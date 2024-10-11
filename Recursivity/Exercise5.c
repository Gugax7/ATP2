#include <stdio.h>
<<<<<<< HEAD
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
    
=======

int of_integer = 0;
int count_divisors = 0;

int is_prime(int integer){
    if(of_integer == 0){
        of_integer = integer;
    }
    integer--;
    if(integer == 1){
        return 1;
    }
    if(integer == 0){
        return 0;
    }
    if(of_integer % integer == 0){
        return 0;
    }
    return is_prime(integer);
}

int main(){
    // return 1 if is prime or 0 if not.
    printf("%d", is_prime(53));

>>>>>>> 3547ea98f532b59df4f4c575d9d197f053c47435
    return 0;
}