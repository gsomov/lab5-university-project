#include "matrix_lib.h"

void replace_positive_with_zero_matrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mat[i][j] > 0) {
                mat[i][j] = 0;
            }
        }
    }
}