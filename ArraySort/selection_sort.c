#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[] = {5,2,6,7,3,17,123,12,54};
    int lower_index = 0;
    for(int g = 0; g < sizeof(array)/sizeof(array[0]); g++){
            printf("%d ", array[g]);
        }
        printf("\n");
    for(int j = 0; j < sizeof(array)/sizeof(array[0]); j++){
        for(int i = j; i < sizeof(array)/sizeof(array[0]); i++){
            if(array[i] < array[lower_index]){
                lower_index = i;
            }
        }
        int aux = array[lower_index];
        array[lower_index] = array[j];
        array[j] = aux;
        lower_index = j+1;
        for(int g = 0; g < sizeof(array)/sizeof(array[0]); g++){
            printf("%d ", array[g]);
        }
        printf("\n");
    }



    return 0;
}