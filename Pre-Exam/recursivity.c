#include <stdio.h>
#include <stdlib.h>

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

int main(){
    printf("count: %d", binary_change(2));
    return 0;
}