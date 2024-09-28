#include <stdio.h>

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

    return 0;
}