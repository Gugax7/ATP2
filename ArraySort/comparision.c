#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000
#include <time.h>
#include <math.h>

void bubble_sort(int array[], int size){
    int has_trade = 1;
    for(int i = 0; i < size - 1 && has_trade == 1; i++){
        int has_trade = 0;
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                int aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                has_trade = 1;
            }
        }
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int array[], int ini_lim, int las_lim)
{
    int upper_apex = ini_lim - 1, lower_apex = ini_lim - 1, pivot;
    pivot = las_lim;
    if (ini_lim < las_lim)
    {
        while (upper_apex < las_lim)
        {
            upper_apex++;
            if (array[upper_apex] <= array[pivot])
            {
                lower_apex++;
                int temp = array[upper_apex];
                array[upper_apex] = array[lower_apex];
                array[lower_apex] = temp;
            }
        }

        quick_sort(array, ini_lim, lower_apex - 1);
        quick_sort(array, lower_apex + 1, las_lim);
    }
}
void print_array(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Encontra o índice do menor elemento no subarray não ordenado
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento do subarray
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void shellSort(int arr[], int n) {
    // Define o gap inicial usando a sequência de Knuth
    int gap = 1;
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    // Executa o Shell Sort usando os gaps da sequência de Knuth
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Move os elementos `gap` posições à frente para abrir espaço
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Coloca o elemento `temp` na posição correta
            arr[j] = temp;
        }
        // Reduz o gap de acordo com a sequência de Knuth
        gap = (gap - 1) / 3;
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

    //bubble_sort(arr,size);
    //quick_sort(arr,0,size-1);

    shellSort(arr,size);

    //print_array(arr,SIZE);

    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
        //printf("%d\n", arr[i]);
    }
    fclose(outputFile);

    // End the clock
    end = clock();

    // Calculate the time used in seconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);


}