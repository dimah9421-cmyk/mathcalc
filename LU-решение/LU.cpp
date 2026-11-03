#include <stdio.h>
#include <vector>

#include "matrix.h"

int main(){

    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;
    std::vector<double> Y;
    std::vector<double> X;

    unsigned int n = 0;

    puts("Ведиете количество переменных");
    puts("Чтобы выполнить задание необходимо ввести 5");
    printf("n = ");
    scanf("%d",&n);

    A.resize(n + 1);
    L.resize(n);
    U.resize(n);
    Y.resize(n);
    X.resize(n);
    for (unsigned int i = 0; i < n; i++){
        A[i].resize(n);
        L[i].resize(n);
        U[i].resize(n);
    }
    matrix_filling(A);

    puts("Начальная матрица");
    printm(A);

    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++){
            L[i][j] = 0;
            if (i == j)
            U[i][j] = 1;
        }
    
    for (unsigned int i = 0; i < n; i++)
        L[i][0] = A[i][0];
    for (unsigned int j = 0; j < n; j++)
        U[0][j] = A[0][j]/L[0][0];
    
    for (unsigned int k = 0; k < n; k++){
        for (unsigned int i = k; i < n; i++){
            L[i][k] = A[i][k];
            for (unsigned int m = 0; m < k; m++)
                L[i][k] = L[i][k] - L[i][m] * U[m][k];
        }
        if (k < n - 1)
            for (unsigned int j = k + 1; j < n; j++){
                U[k][j] = A[k][j];
                for (unsigned int m = 0; m < k; m++)
                    U[k][j] = U[k][j] - L[k][m] * U[m][j];
                U[k][j] = U[k][j] / L[k][k];
            }
    }

    puts("L:");
    printm(L);
    puts("U:");
    printm(U);

    Y[0] = A[0][n] / L[0][0];
    for (unsigned int k = 1; k < n; k++){
        Y[k] = A[k][n];
        for (unsigned int m = 0; m < k; m++)
            Y[k] = Y[k] - L[k][m] * Y[m];
        Y[k] = Y[k] / L[k][k];
    }

    X[n - 1] = Y[n - 1];
    for (int k = n - 2; k >= 0; k--){
        X[k] = Y[k];
        for (unsigned int m = k + 1; m < n; m++)
            X[k] = X[k] - U[k][m] * X[m];
    }
    puts("X:");
    for (unsigned int k = 0; k < n; k++){
        printf("x[%d] = %.2f \n", k, X[k]);
    }
}