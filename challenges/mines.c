#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void clear_area(int mat[MAX][MAX],int lin,int col, int limitlin, int limitcol){
    if(lin < limitlin && col < limitcol && lin > -1 && col > -1){
        if(mat[lin][col] == 0){
            mat[lin][col] = 10;
            //printf("lin = %d, col = %d cleared", lin, col);
            clear_area(mat,lin,col+1,limitlin,limitcol);
            clear_area(mat,lin,col-1,limitlin,limitcol);
            clear_area(mat,lin+1,col,limitlin,limitcol);
            clear_area(mat,lin-1,col,limitlin,limitcol);
        }
    }
}


void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    // Print the matrix
    printf("Matrix:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if(matrix[r][c] < 10){
                printf(" ");
            }
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int map_size = 10;
    int bomb_number = 3;

    if(bomb_number > (map_size - 2)*(map_size - 2)){
        return 0;
    }


    int matrix[MAX][MAX] = {0};
    // put bombs
    int bombs = 0;
    while(bombs < bomb_number){
        int i = 1 + rand()%(map_size - 2);
        int j = 1 + rand()%(map_size - 2);
        if(matrix[i][j] == 0){
            printf("i = %d; j = %d\n", i,j);
            matrix[i][j] = 9;
            bombs++;
        }
    }

    for(int i = 0; i < map_size; i++){
        for(int j = 0; j < map_size; j++){
            if(matrix[i+1][j] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
            if(matrix[i+1][j+1] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
            if(matrix[i][j+1] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
            if(matrix[i-1][j+1] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
            if(matrix[i-1][j-1] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
            if(matrix[i-1][j] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
            if(matrix[i][j-1] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
            if(matrix[i+1][j-1] == 9 && matrix[i][j] < 9){
                matrix[i][j]++;
            }
        }
    }

    //int draw_map[MAX][MAX] = {0};
    

     printMatrix(map_size, map_size, matrix);
     int lin,col;
     scanf("%d%d", &lin, &col);
     //printf("scanned: lin = %d col = %d and value on matrix is %d", lin,col,matrix[lin][col]);
     clear_area(matrix,lin,col,map_size,map_size);

    printMatrix(map_size,map_size,matrix);
   
    return 0;
}

