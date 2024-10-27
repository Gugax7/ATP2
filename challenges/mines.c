#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50


void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    // Print the matrix
    printf("Matrix:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int map_size = 14;
    int bomb_number = 144;

    if(bomb_number > (map_size - 2)*(map_size - 2)){
        return 0;
    }


    int matrix[MAX][MAX] = {0};

    int bombs = 0;
    while(bombs < bomb_number){
        int i = 1 + rand()%(map_size - 2);
        int j = 1 + rand()%(map_size - 2);
        if(matrix[i][j] == 0){
            printf("i = %d; j = %d\n", i,j);
            matrix[i][j] = 1;
            bombs++;
        }
    }
     printMatrix(map_size, map_size, matrix);

    return 0;
}

