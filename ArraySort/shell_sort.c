#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define SIZE 150000


/*void shell_sort(int array[], int size){
    float k = log(size+1)/log(3);
    k = floor(k+0.5);
    int h = (pow(3,k) - 1) / 2;

    while(h > 0){
        for(int i = 0; i < size - h; i++){
            if(array[i] > array[i+h]){
                int aux = array[i+h];
                array[i+h] = array[i];
                array[i] = aux;
                for(int j = i; aux < array[j-h]; j-=h){
                    array[j] = array[j-h];
                    array[j-h] = aux;
                }
            }
        }
        h = (h-1)/3;
    }

}*/

void shell_sort(int lista[], int tamanho){
    int i,j,aux;
    float k = log(tamanho + 1) / log(3);
    int h = (pow(3,k) - 1)/ 2;
    while(h > 0){
        for(i = 0; i < tamanho - h; i++){
            if(lista[i] > lista[i+h]){
                aux = lista[i+h];
                lista[i+h] = lista[i];
                lista[i] = aux;
                j= i-h;
                while(j>=0){
                    if(aux<lista[j]){
                        lista[j+h] = lista[j];
                        lista[j] = aux;

                    }
                    else{break;}
                    j=j-h;
                }
            }
        }h=(h-1)/3;
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

    shell_sort(arr,size);

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