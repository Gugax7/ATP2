#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 150000

void insertion_sort(int array[], int size){
    for(int i = 0; i < size - 1; i++){
        int current = i+1;
        int aux = array[i+1];
        for(int j = i; array[j] > aux; j--){
            array[j+1] = array[j];
            current = j;
        }
        array[current] = aux;
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Start the clock
    start = clock();

    int arr[SIZE];
    FILE *file = fopen("random_numbers.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

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

    insertion_sort(arr,size);


    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }
    fclose(outputFile);

    // End the clock
    end = clock();

    // Calculate the time used in seconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);


}