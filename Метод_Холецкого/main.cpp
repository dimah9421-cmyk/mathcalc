#include <stdio.h>
#include <vector>

#include "matrix.h"

int main(){
    std::vector<std::vector<double>> A, U, L, X, Y, A_1;

    int var = -1;
    do{
        puts("выбирете спомоб заполнения матрицы\n 0 - по заданию\n 1 - самостоятельно\n 2 - рандомно");
        scanf("%d", &var);
        if (var == 0 || var == 1 || var == 2)
            break;
    }while(1);
    int n = 0;
    
    puts("заполнение матрицы A:");
    switch (var){
    case 0:
        task_fill(A);
        break;
    case 1: 
        person_fill(A);
        break;
    case 2:
        rand_fill(A);
        break;
    }
    printm(A);
     
    n = A.size();

    L.resize(n); U.resize(n); X.resize(n); Y.resize(n); A_1.resize(n);
    for (int i = 0; i < n; i++){
        L[i].resize(n);
        U[i].resize(n);
        X[i].resize(n);
        Y[i].resize(n);
        A_1[i].resize(n);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            L[i][j] = 0;
            if (i == j) U[i][j] = 1;
            else        U[i][j] = 0;
        }
    
    for (int i = 0; i < n; i++)
        L[i][0] = A[i][0];   
    
    for (int i = 1; i < n; i++)
        U[0][i] = A[0][i] / L[0][0];
    
    for (int k = 1; k < n; k++){
        for (int i = k; i < n; i++){
            L[i][k] = A[i][k];
            for (int m = 0; m < k; m++){
                L[i][k] = L[i][k] - L[i][m] * U[m][k];
            }
        }
        if (k <= n - 2){
            for (int i = k + 1; i < n; i++){
                U[k][i] = A[k][i];
                for (int m = 0; m < k; m++){
                    U[k][i] = U[k][i] - L[k][m] * U[m][i];
                }
                U[k][i] = U[k][i]/L[k][k];
            }
        }
    }
    puts("L:");
    printm(L);

    puts("U:");
    printm(U);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j > i)          Y[i][j] = 0;
            else if (i == j)    Y[i][j] = 1 / L[i][i];
            else {
                Y[i][j] = 0;
                for (int m = j; m < i; m++){
                    Y[i][j] = Y[i][j] - L[i][m] * Y[m][j];
                }
                Y[i][j] = Y[i][j] / L[i][i];
            }
        }   
    }

    puts("Y:");
    printm(Y);

    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if (j < i)  X[i][j] = 0;
            else if (j == i) X[i][j] = 1;
            else{
                X[i][j] = 0;
                for (int m = i + 1; m <= j; m++)
                    X[i][j] = X[i][j] -U[i][m] * X[m][j];
            }
        }
    }

    puts("X:");
    printm(X);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            A_1[i][j] = 0;
            for (int m = 0; m < n; m ++)
                A_1[i][j] = A_1[i][j] + X[i][m] * Y[m][j];
        }   
    }

    puts("A_1");
    printm(A_1);
}