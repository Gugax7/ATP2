#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 150000

/*void binary_search(int array[],int array_size, int number){
    int mid = array_size / 2;
    int higher = array_size - 1, lower = 0;
    while(array[mid] != number && higher > lower && mid < array_size){
        if(array[mid]>number){
            higher = mid;
        }
        else{
            lower = mid;
        }
        mid = (higher + lower) / 2;
    }

    if(array[mid] == number){
        printf("number found! (pos: %d)", mid);
    }
    else{
        printf("number not found!");
    }
}*/

void binary_search(int array[], int lower, int higher, int number){
    int mid = (lower + higher) / 2;
    if(array[mid] == number){
        printf("number found! (pos: %d)", mid);
    }
    else{
        if(lower < higher){
            if(array[mid] > number){
                binary_search(array,lower,mid,number);
            }
            else{
                binary_search(array,mid,higher,number);
            }
        }
        else{
            printf("number didnt found!");
        }
    }
}


int main() {
    clock_t start, end;
    double cpu_time_used;

    // Start the clock
    start = clock();

    int arr[SIZE];
    FILE *file = fopen("output.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    char c;
    int size = 0;
    while((c=fgetc(file)) != EOF){
        if(c == '\n'){
            size++;
        }
    }
    size--;
    printf("Size = %d\n ", size);
    fseek(file,0,SEEK_SET);

    // Reading each number from the file into the array
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error: Could not read number %d from the file.\n", i + 1);
            fclose(file);
            return 1;
        }
    }
    

    fclose(file);

    binary_search(arr,0,size-1,4619);


    // End the clock
    end = clock();

    // Calculate the time used in seconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);


}