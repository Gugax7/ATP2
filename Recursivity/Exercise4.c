#include <stdio.h>

/*

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

*/

int powr(int a, int e){
    if(e == 0){
        return 1;
    }
    if(e == 1){
        return a;
    }
    return a*powr(a,e-1);
}
int main(){

<<<<<<< HEAD
    printf("Result = %d", powr(2,6));
=======
    printf("Result = %d", powr(3,8));
>>>>>>> 3547ea98f532b59df4f4c575d9d197f053c47435

    return 0;
}