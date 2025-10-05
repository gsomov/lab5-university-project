#include "load_lib.h"
#include <stdio.h>
#include <windows.h>

void LoadRunArray(const char *libname, int arr[], int size) {
    HMODULE lib = LoadLibrary(libname);
    if (!lib) {
        printf("Cannot open library '%s'\n", libname);
        return;
    }

    ArrayFunc func = (ArrayFunc)GetProcAddress(lib, "replace_positive_with_zero_array");
    if (func == NULL) {
        printf("Cannot load function 'replace_positive_with_zero_array'\n");
    } else {
        func(arr, size);  // Передаем массив и размер
    }

    FreeLibrary(lib);
}

void LoadRunMatrix(const char *libname, int mat[8][8]) {
    HMODULE lib = LoadLibrary(libname);
    if (!lib) {
        printf("Cannot open library '%s'\n", libname);
        return;
    }

    MatrixFunc func = (MatrixFunc)GetProcAddress(lib, "replace_positive_with_zero_matrix");
    if (func == NULL) {
        printf("Cannot load function 'replace_positive_with_zero_matrix'\n");
    } else {
        func(mat);  // Передаем матрицу
    }

    FreeLibrary(lib);
}