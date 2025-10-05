#ifndef LOAD_LIB_H
#define LOAD_LIB_H

// Объявляем типы функций
typedef void (*ArrayFunc)(int[], int);
typedef void (*MatrixFunc)(int[8][8]);

void LoadRunArray(const char *libname, int arr[], int size);
void LoadRunMatrix(const char *libname, int mat[8][8]);

#endif