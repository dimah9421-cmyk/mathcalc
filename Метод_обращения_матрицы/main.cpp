#include <stdio.h>
#include <vector>
#include <cmath>

#include "matrix.h"

int main(){
    std::vector<std::vector<double>> A, L, Lt, A_1;

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

    L.resize(n);
    Lt.resize(n);
    A_1.resize(n);
    for (int i = 0; i < n; i++){
        L[i].resize(n);
        Lt[i].resize(n);
        A_1[i].resize(n);
    }
    
    for (int k = 0; k < n; k ++){
        double sum_sqrt = 0;
        for (int i = 0; i < k; i ++){
            sum_sqrt = sum_sqrt + pow(L[k][i], 2);
        }
        L[k][k] = sqrt(A[k][k] - sum_sqrt);
        for (int i = k + 1; i < n; i ++){
            double pairsum = 0; 
            for (int m = 0; m < k; m++)
                pairsum = pairsum + L[i][m] * L[k][m];
            L[i][k] = (A[i][k] - pairsum) / L[k][k];
            }
        }
    
    puts("L:");
    printm(L);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j > i)  Lt[i][j] = 0;
            else if (j == i) Lt[i][j] = 1/L[i][i];
            else {
                Lt[i][j] = 0;
                for (int m = j; m < i; m++)
                    Lt[i][j] = Lt[i][j] + L[i][m]* Lt[m][j];
                Lt[i][j] = Lt[i][j] / (-L[i][i]);
            }
        }
    }

    puts("Lt:");
    printm(Lt);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            A_1[i][j] = 0;
            for (int m = 0; m < n; m++)
                A_1[i][j] = A_1[i][j] + Lt[m][i]*Lt[m][j]; 
        }
    
    puts("A_1");
    printm(A_1);
}