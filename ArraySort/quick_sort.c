#include <stdio.h>
#include <stdlib.h>

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
        // printf("upper = %d, lower = %d, las_lim = %d, ini_lim = %d\n",upper_apex,lower_apex,las_lim,ini_lim);
        // printf("quick_sort called***** (%d,%d)",ini_lim, lower_apex-1);
        quick_sort(array, ini_lim, lower_apex - 1);
        // printf("quick_sort called (%d,%d)",lower_apex+1, las_lim);
        quick_sort(array, lower_apex + 1, las_lim);
    }
}

int main()
{

    int array[] = {1, 9, 2, 8, 3, 7, 4, 6, 5,83,262,263,45,23,45,23,45,2,76,234,71,3,5,2,3,5,23,417,3,45,23,71,3,42,71,34,5,234,5,7,17,8,1,51,89,1,91,465,2,418,2,3,87,23,46};
     size_t size = sizeof(array) / sizeof(array[0]);
     printf("%d\n", size);
    quick_sort(array, 0, size-1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}