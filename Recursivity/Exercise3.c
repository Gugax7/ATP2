#include <stdio.h>

long long sum = 0;

// Esse abaixo deu certo também :)
long long sum_of_last_numbers(int number){
    long long result = 7;
    if(number != 0){
        sum += number;
        number--;
        result = sum;
        //printf("result = %i", result);
        sum_of_last_numbers(number);
        
    }
    else{
        result = sum;
       // printf("result = %i", result);
        sum = 0;
        return result;
    }
}
/*
int sum_of_last_numbers(int number){
    int result;
    if(number == 0){
        result = sum;
        sum = 0;
        return result;
    }
    else{
        sum+=number;
        number--;
        sum_of_last_numbers(number);
    }
}*/

int main(){
    int number;
    printf("Please type an int:");
    scanf("%i", &number);

    printf("Sum = %d", sum_of_last_numbers(number));

}