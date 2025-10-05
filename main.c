#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load_lib.h"

#define ROWS 8
#define COLS 8
#define SIZE 64

int main() {
    int choice;
    int matrix[ROWS][COLS];
    int array[SIZE];
    srand(time(NULL));

    printf("Choose library:\n1 - Matrix\n2 - Array\n3 - Quit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Заполняем матрицу случайными числами
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    matrix[i][j] = rand() % 101 - 50; // от -50 до 50
                }
            }

            printf("Original matrix:\n");
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%3d ", matrix[i][j]);
                }
                printf("\n");
            }

            // Загружаем библиотеку для матрицы и передаем саму матрицу
            LoadRunMatrix("libmatrix.dll", matrix);

            printf("Modified matrix:\n");
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%3d ", matrix[i][j]);
                }
                printf("\n");
            }

        } else if (choice == 2) {
            // Заполняем массив случайными числами
            for (int i = 0; i < SIZE; i++) {
                array[i] = rand() % 101 - 50;
            }

            printf("Original array:\n");
            for (int i = 0; i < SIZE; i++) {
                if (i % 8 == 0 && i != 0){
                    printf("\n");
                }
                printf("%3d ", array[i]);
            }
            printf("\n");

            // Загружаем библиотеку для массива и передаем сам массив
            LoadRunArray("libarray.dll", array, SIZE);

            printf("Modified array:\n");
            for (int i = 0; i < SIZE; i++) {
                if (i % 8 == 0 && i != 0){
                    printf("\n");
                }
                printf("%3d ", array[i]);
            }
            printf("\n");

        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}