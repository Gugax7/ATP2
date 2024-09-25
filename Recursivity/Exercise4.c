#include <stdio.h>


int result = 0;
int current_elevation = 1;
int current_number = 0;



int powr(int number, int elevations){
    if (current_number == 0){
        current_number = number;
    }
    if(elevations == 1){
        return number;
    }
    else if(elevations == 0){
        return 1;
    }
    else{
        //printf("entered on else\n number: %d", number);

        number = number * current_number;
       // printf("\nnumber: %d", number);
        elevations--;
        //printf("Called again\n");
        powr(number,elevations);
    }
}


int main(){

    printf("Result = %d", powr(24,4));

    return 0;
}