#include <stdio.h>
#include <stdlib.h>
#define SIZE 150000
#include <time.h>
void merge(int arr[], int left, int mid, int right) {
    int tamr = right - mid;
    int taml = mid - left + 1;

    int right_array[tamr], left_array[taml];

    // copy both sides into that shit

    for(int i = 0; i<tamr; i++){
        right_array[i] = arr[mid+i+1];
    }
    for(int i = 0; i < taml; i++){
        left_array[i] = arr[left+i];
    }

    int i = 0,j = 0,k = left;
    // now i need to put back on original matrix sorting
    for(i,j,k; i < taml && j < tamr; k++){
        if(left_array[i] <= right_array[j]){
            arr[k] = left_array[i];
            i++;
        }
        else{
            arr[k] = right_array[j];
            j++;
        }
    }

    // now it probably left some elements on matrix that has big size or no
    // but probably left something, so i have to run through putting each of
    // this values inside original matrix

    for(i,k;i < taml;i++, k++){
        arr[k] = left_array[i];
    }
    for(j,k;j < tamr;j++, k++){
        arr[k] = right_array[j];
    }

}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

   merge_sort(arr,0,size-1);

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